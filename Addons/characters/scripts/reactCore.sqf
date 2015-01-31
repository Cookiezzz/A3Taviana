/*
	File: reactCore.sqf
	Author: Joris-Jan van 't Land

	Description:
	Processing which responses should be shown in the Core conversation.

	Parameter(s):
	- 
	
	Returns:
	Results Array
*/

//Xbox button defines:
#define KEY_XINPUT                0x00050000

#define KEY_XBOX_A                KEY_XINPUT + 0
#define KEY_XBOX_B                KEY_XINPUT + 1
#define KEY_XBOX_Y                KEY_XINPUT + 3


private ["_result"];
_result = [];

//Load the random sentence selection function.
if (isnil "BIS_selectRandomSentenceFunc") then 
{
	BIS_selectRandomSentenceFunc = compile (preprocessFileLineNumbers "ca\characters\scripts\selectRandomSentence.sqf");
};

scopeName "main";

//We are starting a new conversation, we greet him / her.
//Check the other party is not enemy to us.
if ((_sentenceId == "") && ((_this countEnemy [_from]) == 0)) then 
{
	//See if either party is in agony.
	private ["_fromAgony", "_thisAgony"];
	_fromAgony = _from getVariable "BIS_IS_inAgony";
	_thisAgony = _this getVariable "BIS_IS_inAgony";
	
	if (isNil "_fromAgony") then {_fromAgony = false};
	if (isNil "_thisAgony") then {_thisAgony = false};
	
	if (!_fromAgony && !_thisAgony) then 
	{
		//See if either party has core conversations disabled.
		private ["_fromDisabled", "_thisDisabled"];
		_fromDisabled = _from getVariable "BIS_noCoreConversations";
		_thisDisabled = _this getVariable "BIS_noCoreConversations";
		
		if (isNil "_fromDisabled") then {_fromDisabled = false};
		if (isNil "_thisDisabled") then {_thisDisabled = false};
		
		if (!_fromDisabled && !_thisDisabled) then 
		{
			//Is it time to update? We only want to process sentence availability once every 5 seconds.
			private ["_lastUpdate"];
			_lastUpdate = _this getVariable "BIS_lastCoreConvUpdate";
			if (isnil "_lastUpdate") then {_lastUpdate = -5};
			
			if ((time - _lastUpdate) >= 5) then 
			{
				//Process forgetting of greetings.
				//Initialize greeting history arrays.
				//For _this.
				private ["_greetedPeople", "_greetedTimes", "_greetedLanguages", "_greetedByPeople", "_greetedByTimes", "_greetedByLanguages", "_greetedByEvil"];
				_greetedPeople = _this getVariable "BIS_greetedPeople";
				if (isNil "_greetedPeople") then 
				{
					_greetedPeople = [];
					_greetedTimes = [];
					_greetedLanguages = [];
				} 
				else 
				{
					_greetedTimes = _this getVariable "BIS_greetedTimes";
					_greetedLanguages = _this getVariable "BIS_greetedLanguages";
				};
				
				_greetedByPeople = _this getVariable "BIS_greetedByPeople";
				if (isNil "_greetedByPeople") then 
				{
					_greetedByPeople = [];
					_greetedByTimes = [];
					_greetedByLanguages = [];
					_greetedByEvil = [];
				} 
				else 
				{
					_greetedByTimes = _this getVariable "BIS_greetedByTimes";
					_greetedByLanguages = _this getVariable "BIS_greetedByLanguages";
					_greetedByEvil = _this getVariable "BIS_greetedByEvil";
				};
				
				//For _from.
				private ["_greetedPeopleFrom", "_greetedTimesFrom", "_greetedLanguagesFrom", "_greetedByPeopleFrom", "_greetedByTimesFrom", "_greetedByLanguagesFrom", "_greetedByEvilFrom"];
				_greetedPeopleFrom = _from getVariable "BIS_greetedPeople";
				if (isNil "_greetedPeopleFrom") then 
				{
					_greetedPeopleFrom = [];
					_greetedTimesFrom = [];
					_greetedLanguagesFrom = [];
				} 
				else 
				{
					_greetedTimesFrom = _from getVariable "BIS_greetedTimes";
					_greetedLanguagesFrom = _from getVariable "BIS_greetedLanguages";
				};
				
				_greetedByPeopleFrom = _from getVariable "BIS_greetedByPeople";
				if (isNil "_greetedByPeopleFrom") then 
				{
					_greetedByPeopleFrom = [];
					_greetedByTimesFrom = [];
					_greetedByLanguagesFrom = [];
					_greetedByEvilFrom = [];	
				} 
				else 
				{
					_greetedByTimesFrom = _from getVariable "BIS_greetedByTimes";
					_greetedByLanguagesFrom = _from getVariable "BIS_greetedByLanguages";
					_greetedByEvilFrom = _from getVariable "BIS_greetedByEvil";	
				};
				
				//Forgetting for _this.
				//Process forgetting of greetings after 5 minutes.
				for "_i" from 0 to ((count _greetedTimes) - 1) do 
				{
					if ((time - (_greetedTimes select _i)) >= 300) then 
					{
						_greetedTimes set [_i, -1];
						_greetedPeople set [_i, -1];
						_greetedLanguages set [_i, -1];
					};
				};
				
				for "_i" from 0 to ((count _greetedByTimes) - 1) do 
				{
					if ((time - (_greetedByTimes select _i)) >= 300) then 
					{
						_greetedByTimes set [_i, -1];
						_greetedByPeople set [_i, -1];
						_greetedByLanguages set [_i, -1];
						_greetedByEvil set [_i, -1];
					};
				};
				
				_greetedTimes = _greetedTimes - [-1];
				_greetedPeople = _greetedPeople - [-1];
				_greetedLanguages = _greetedLanguages - [-1];
				_greetedByTimes = _greetedByTimes - [-1];
				_greetedByPeople = _greetedByPeople - [-1];
				_greetedByLanguages = _greetedByLanguages - [-1];
				_greetedByEvil = _greetedByEvil - [-1];
				
				
				//Forgetting for _from.
				//Process forgetting of greetings after 5 minutes.
				for "_i" from 0 to ((count _greetedTimesFrom) - 1) do 
				{
					if ((time - (_greetedTimesFrom select _i)) >= 300) then 
					{
						_greetedTimesFrom set [_i, -1];
						_greetedPeopleFrom set [_i, -1];
						_greetedLanguagesFrom set [_i, -1];
					};
				};
				
				for "_i" from 0 to ((count _greetedByTimesFrom) - 1) do 
				{
					if ((time - (_greetedByTimesFrom select _i)) >= 300) then 
					{
						_greetedByTimesFrom set [_i, -1];
						_greetedByPeopleFrom set [_i, -1];
						_greetedByLanguagesFrom set [_i, -1];
						_greetedByEvilFrom set [_i, -1];
					};
				};
				
				_greetedTimesFrom = _greetedTimesFrom - [-1];
				_greetedPeopleFrom = _greetedPeopleFrom - [-1];
				_greetedLanguagesFrom = _greetedLanguagesFrom - [-1];
				_greetedByTimesFrom = _greetedByTimesFrom - [-1];
				_greetedByPeopleFrom = _greetedByPeopleFrom - [-1];
				_greetedByLanguagesFrom = _greetedByLanguagesFrom - [-1];
				_greetedByEvilFrom = _greetedByEvilFrom - [-1];
				
				//Store the updated list of people and times.
				_this setVariable ["BIS_greetedPeople", _greetedPeople, true];
				_this setVariable ["BIS_greetedTimes", _greetedTimes, true];
				_this setVariable ["BIS_greetedLanguages", _greetedLanguages, true];
				_this setVariable ["BIS_greetedByPeople", _greetedByPeople, true];
				_this setVariable ["BIS_greetedByTimes", _greetedByTimes, true];
				_this setVariable ["BIS_greetedByLanguages", _greetedByLanguages, true];
				_this setVariable ["BIS_greetedByEvil", _greetedByEvil, true];
				
				_from setVariable ["BIS_greetedPeople", _greetedPeopleFrom, true];
				_from setVariable ["BIS_greetedTimes", _greetedTimesFrom, true];
				_from setVariable ["BIS_greetedLanguages", _greetedLanguagesFrom, true];
				_from setVariable ["BIS_greetedByPeople", _greetedByPeopleFrom, true];
				_from setVariable ["BIS_greetedByTimes", _greetedByTimesFrom, true];
				_from setVariable ["BIS_greetedByLanguages", _greetedByLanguagesFrom, true];
				_from setVariable ["BIS_greetedByEvil", _greetedByEvilFrom, true];			
				
				//Only show option to greet if _this didn't yet greet _from.
				private ["_index"];
				_index = _greetedPeople find _from;
				
				if (_index == -1) then 
				{	
					//Check handshake history in greeting.
					//See if I already once found out _from's language.
					private ["_index"];
					_index = _greetedByPeople find _from;
							
					private ["_useLanguage"];
					if (_index != -1) then 
					{
						_useLanguage = _greetedByLanguages select _index;
					} 
					else 
					{
						//Determine which language should be displayed.
						private ["_faction"];
						
						//Find _from's faction.
						_faction = faction _from;
						
						//Find _from's faction's primary language.
						switch (_faction) do 
						{
							case "USMC": {_useLanguage = "EN"};
							case "CDF": {_useLanguage = "CZ"};
							case "RU": {_useLanguage = "RU"};
							case "INS": {_useLanguage = "RU"};
							case "GUE": {_useLanguage = "CZ"};
							case "CIV": {_useLanguage = "CZ"};
							
							default {};	
						};
						
						if (isnil "_useLanguage") then 
						{
							_useLanguage = "";
						};
					};
					
					//Does _this speak the chosen language?
					private ["_languages"];
					_languages = getArray(configFile >> "CfgVehicles" >> (typeOf _this) >> "languages");
					
					if (!(_useLanguage in _languages)) then 
					{
						//No, so use _this's primary language.
						_useLanguage = _languages select 0;
					};
					
					//Determine to-be-used topic.
					private ["_useTopic", "_postFix", "_hint"];
					switch (_useLanguage) do 
					{
						case "EN": {_useTopic = "core_en"; _postFix = "_EN"; _hint = " (" + (localize "STR_CONV_CORE_HINT_ENGLISH") + ")"};
						case "RU": {_useTopic = "core_ru"; _postFix = "_RU"; _hint = " (" + (localize "STR_CONV_CORE_HINT_RUSSIAN") + ")"};
						case "CZ": {_useTopic = "core_cz"; _postFix = "_CZ"; _hint = " (" + (localize "STR_CONV_CORE_HINT_CHERNARUSSIAN") + ")"};
					};
					
					//Find an appropriate greeting.
					private ["_sentence"];
					_sentence = [_this, _from] call BIS_selectRandomSentenceFunc;
					
					if (!(isNil "_sentence")) then 
					{
						_result = _result + [[[((localize "STR_CONV_CORE_GREETING") + _hint), [/*KEY_XBOX_A*/]], _useTopic, (_sentence + _postFix), [["PlayerInitiated", true, "", []]]]];
					};
				};
				
				_this setVariable ["BIS_coreConvList", _result]; //Cache the results.
				_this setVariable ["BIS_lastCoreConvUpdate", time]; //Store the cache timestamp.
			} 
			else 
			{
				_result = _this getVariable "BIS_coreConvList"; //Use the sentences from cache.
			};
		};
	};
};

//Someone told us which languages he / she speaks, we greet him / her.
if (_sentenceId in ["English", "Czech", "Russian", "EnglishCzech", "EnglishRussian", "CzechRussian"]) then 
{
	//There was a greeting: _this to _from. 
	//Remove it, because it failed due to bad language.
	private ["_greetedPeopleFrom", "_greetedTimesFrom", "_greetedLanguagesFrom", "_greetedByPeople", "_greetedByTimes", "_greetedByLanguages"];
	_greetedPeopleFrom = _from getVariable "BIS_greetedPeople";
	if (isNil "_greetedPeopleFrom") then 
	{
		_greetedPeopleFrom = [];
		_greetedTimesFrom = [];
		_greetedLanguagesFrom = [];
	} 
	else 
	{
		_greetedTimesFrom = _from getVariable "BIS_greetedTimes";
		_greetedLanguagesFrom = _from getVariable "BIS_greetedLanguages";
	};
	
	_greetedByPeople = _this getVariable "BIS_greetedByPeople";
	if (isNil "_greetedByPeople") then 
	{
		_greetedByPeople = [];
		_greetedByTimes = [];
		_greetedByLanguages = [];
	} 
	else 
	{
		_greetedByTimes = _this getVariable "BIS_greetedByTimes";
		_greetedByLanguages = _this getVariable "BIS_greetedByLanguages";
	};
	
	private ["_index"];
	_index = _greetedPeople find _from;
	if (_index != -1) then 
	{
		_greetedPeople set [_index, -1];	
		_greetedTimes set [_index, -1];
		_greetedLanguages set [_index, -1];
		
		_greetedPeople = _greetedPeople - [-1];
		_greetedTimes = _greetedTimes - [-1];
		_greetedLanguages = _greetedLanguages - [-1];
	};
	
	_index = _greetedByPeopleFrom find _this;
	if (_index != -1) then 
	{
		_greetedByPeopleFrom set [_index, -1];	
		_greetedByTimesFrom set [_index, -1];
		_greetedByLanguagesFrom set [_index, -1];
		
		_greetedByPeopleFrom = _greetedByPeopleFrom - [-1];
		_greetedByTimesFrom = _greetedByTimesFrom - [-1];
		_greetedByLanguagesFrom = _greetedByLanguagesFrom - [-1];
	};
	
	_from setVariable ["BIS_greetedPeople", _greetedPeopleFrom, true];
	_from setVariable ["BIS_greetedTimes", _greetedTimesFrom, true];
	_from setVariable ["BIS_greetedLanguages", _greetedLanguagesFrom, true];
	
	_this setVariable ["BIS_greetedByPeople", _greetedByPeople, true];
	_this setVariable ["BIS_greetedByTimes", _greetedByTimes, true];
	_this setVariable ["BIS_greetedByLanguages", _greetedByLanguages, true];
	
	private ["_tryLanguages"];
	switch (_sentenceId) do 
	{
		case "English": {_tryLanguages = ["EN"]};
		case "Czech": {_tryLanguages = ["CZ"]};
		case "Russian": {_tryLanguages = ["RU"]};
		case "EnglishCzech": {_tryLanguages = ["EN", "CZ"]};
		case "EnglishRussian": {_tryLanguages = ["EN", "RU"]};
		case "CzechRussian": {_tryLanguages = ["CZ", "RU"]};
		
		default {};	
	};
	
	//Do we speak any of these?
	private ["_languages", "_language"];
	_languages = getArray(configFile >> "CfgVehicles" >> (typeOf _this) >> "languages");
	{
		if (_x in _languages) exitWith {_language = _x};
	} 
	forEach _tryLanguages;
	
	//Did we find a good language?
	if (!(isNil "_language")) then 
	{
		private ["_useTopic", "_hint"];
		switch (_language) do 
		{
			case "EN": {_useTopic = "core_en"; _hint = " (" + (localize "STR_CONV_CORE_HINT_ENGLISH") + ")"};
			case "RU": {_useTopic = "core_ru"; _hint = " (" + (localize "STR_CONV_CORE_HINT_RUSSIAN") + ")"};
			case "CZ": {_useTopic = "core_cz"; _hint = " (" + (localize "STR_CONV_CORE_HINT_CHERNARUSSIAN") + ")"};
			
			default {};	
		};
		
		//Find an appropriate greeting.
		private ["_sentence"];
		_sentence = [_this, _from] call BIS_selectRandomSentenceFunc;
			
		if (!(isNil "_sentence")) then 
		{
			//Automatically send new greeting using new language.
			//The player already chose to greet before, shouldn't have to do it again.
			_this kbTell [_from, _useTopic, (_sentence + "_" + _language), ["PlayerInitiated", false, "", []]];
		};
	};
};

_result