/*
	File: selectRandomSentence.sqf
	Author: Joris-Jan van 't Land

	Description:
	Analyzes conversation partners and determines which tags should be used 
	in selecting a sentence. A random matching sentence is then returned.

	Parameter(s):
	_this select 0: 'this' - speaking party - person for who tags are determined (Object)
	_this select 1: 'from' - spoken to party (Object)
	
	Returns:
	Sentence (String)
*/

private ["_personThis", "_personFrom"];
_personThis = _this select 0;
_personFrom = _this select 1;


private ["_tags"];
_tags = ["greeting", "question"];


//Determine partner combination.
private ["_typeTag", "_sideThis", "_sideFrom"];
_sideThis = side _personThis;
_sideFrom = side _personFrom;

if (_sideThis == civilian) then 
{
	_typeTag = "civilianTo";
} 
else 
{
	_typeTag = "combatantTo";	
};

if (_sideFrom == civilian) then 
{
	_typeTag = _typeTag + "Civilian";	
} 
else 
{
	_typeTag = _typeTag + "Combatant";
};

_tags = _tags + [_typeTag];


//Two combatants are speaking to one another.
if (_typeTag == "combatantToCombatant") then 
{
	//TODO: Does this apply to player? Or should he have the option to speak still?
	//Determine combat situation.
	private ["_behaviour"];
	_behaviour = behaviour _personThis;
	
	if ((_behaviour == "COMBAT") || (_behaviour == "STEALTH")) then 
	{
		_tags = _tags + ["inCombat"];	
	} 
	else 
	{
		_tags = _tags + ["notInCombat"];	
	};
	
	
	//Determine rank difference.
	private ["_rankTag", "_rankIdThis", "_rankIdFrom"];
	_rankIdThis = rankId _personThis;
	_rankIdFrom = rankId _personFrom;
	
	if ((typeName _rankIdThis) != (typeName 0)) then 
	{
		_rankIdThis = 0;
	};
	
	if ((typeName _rankIdFrom) != (typeName 0)) then 
	{
		_rankIdFrom = 0;
	};
	
	if (_rankIdThis > _rankIdFrom) then 
	{
		_rankTag = "toLowerRank";
	} 
	else 
	{
		if (_rankIdThis < _rankIdFrom) then 
		{
			_rankTag = "toHigherRank";
		} 
		else 
		{
			_rankTag = "toSameRank";
		};
	};
	
	_tags = _tags + [_rankTag];
	
	
	//Speaking to a lower-ranking combatant.
	if (_rankTag == "toLowerRank") then 
	{
		_tags = _tags + ["to" + (rank _personFrom)];
	};
};


//Determine instigator morale.
//TODO: When negative, often don't approach at all?
//We will not speak to captives in a friendly way for now.
if (!(captive _personFrom)) then 
{
	private ["_morale"];
	_morale = morale _personThis;

	if (_morale > 0.3) then 
	{
		_tags = _tags + ["positive"];
	} 
	else 
	{
		if (_morale < 0) then 
		{
			_tags = _tags + ["negative"];
		} 
		else 
		{
			_tags = _tags + ["neutral"];
		};
	};
} 
else 
{
	_tags = _tags + ["negative"];
};


//Determine gender combination.
private ["_womanThis", "_womanFrom"];
_womanThis = getNumber(configFile >> "CfgVehicles" >> (typeOf _personThis) >> "woman");
_womanFrom = getNumber(configFile >> "CfgVehicles" >> (typeOf _personFrom) >> "woman");

if ((_womanThis == 1) && (_womanFrom != 1)) then 
{
	_tags = _tags + ["femaleToMale"];
} 
else 
{
	if ((_womanThis != 1) && (_womanFrom == 1)) then 
	{
		_tags = _tags + ["maleToFemale"];
	} 
	else 
	{
		if ((_womanThis != 1) && (_womanFrom != 1)) then 
		{
			_tags = _tags + ["maleToMale"];
		} 
		else 
		{
			_tags = _tags + ["femaleToFemale"];
		};
	};
};


//Determine time of day.
if ((dayTime > 6) && (dayTime < 12)) then 
{
	_tags = _tags + ["morning"];
} 
else 
{
	if ((dayTime > 16) && (dayTime < 22)) then 
	{
		_tags = _tags + ["evening"];
	} 
	else 
	{
		if ((dayTime >= 22) || (dayTime <= 6)) then 
		{
			_tags = _tags + ["night"];
		} 
		else 
		{
			_tags = _tags + ["day"];
		};
	};
};


//Determine surrender status.
if (captive _personThis) then 
{
	_tags = _tags + ["surrendered"];
} 
else 
{
	_tags = _tags + ["notSurrendered"];	
};


//Select random, matching greeting and gesture.
//We want to access the config only once.
if (isNil "BIS_coreTalkSentences") then 
{
	BIS_coreTalkSentences = [];
	BIS_coreTalkTags = [];
	
	private ["_cfgTalkSentences"];
	_cfgTalkSentences = configFile >> "CfgTalkSentences";
	
	for "_i" from 0 to ((count _cfgTalkSentences) - 1) do 
	{
		private ["_candidate"];
		_candidate = _cfgTalkSentences select _i;
		
		BIS_coreTalkSentences = BIS_coreTalkSentences + [configName _candidate];
		BIS_coreTalkTags = BIS_coreTalkTags + [getArray(_candidate >> "tags")];
	};
};	

//Make a list of candidates which match all given tags.
private ["_candidates"];
_candidates = [];

for "_i" from 0 to ((count BIS_coreTalkSentences) - 1) do 
{
	private ["_candidate", "_candidateTags"];
	_candidate = BIS_coreTalkSentences select _i;
	_candidateTags = BIS_coreTalkTags select _i;
	
	//Are all tags in this candidate?
	if (({_x in _candidateTags} count _tags) == (count _tags)) then 
	{
		_candidates = _candidates + [_candidate];
	};
};

//TODO: remove.
//debugLog (format ["Log: %1", _tags]);

//Select a random sentence from the candidates.
private ["_sentence"];
_sentence = _candidates select (floor (random (count _candidates)));

_sentence