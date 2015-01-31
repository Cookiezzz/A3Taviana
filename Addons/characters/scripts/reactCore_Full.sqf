/*
	File: reactCore_Full.sqf
	Author: Joris-Jan van 't Land

	Description:
	Processing which responses should be shown in the Core_Full conversation.

	Parameter(s):
	- 
	
	Returns:
	Results Array
*/

//Xbox button defines:
#define KEY_XINPUT                0x00050000

#define KEY_XBOX_A                KEY_XINPUT + 0
#define KEY_XBOX_B                KEY_XINPUT + 1
#define KEY_XBOX_X                KEY_XINPUT + 2


private ["_result"];
_result = [];

//Check if other side already greeted us and this topic is his / her language.
private ["_greetedByPeople", "_index", "_alreadyGreeted"];
_alreadyGreeted = false;
_greetedByPeople = _this getVariable "BIS_greetedByPeople";
_index = _greetedByPeople find _from;
if (_index != -1) then 
{
	//See if the greeting was evil.
	private ["_greetedByEvil"];
	_greetedByEvil = _this getVariable "BIS_greetedByEvil";
	if (_greetedByEvil select _index) exitWith {};
	
	//Now see if this is the correct language topic.
	private ["_greetedByLanguages", "_language", "_wantedTopic"];
	_greetedByLanguages = _this getVariable "BIS_greetedByLanguages";
	_language = _greetedByLanguages select _index;
	
	switch (_language) do 
	{
		case "EN": {_wantedTopic = "core_en"};
		case "RU": {_wantedTopic = "core_ru"};
		case "CZ": {_wantedTopic = "core_cz"};
	};
	
	if (_topic == _wantedTopic) exitWith  
	{
		_alreadyGreeted = true;
	};
};

private ["_PlayerInitiated"];
if (isnil "_PlayerInitiated") then {_PlayerInitiated = false};

//Check if the other side did not responded by saying he / she doesn't understand you, or by a very negative greeting.
if (((_sentenceId == "") || _PlayerInitiated) && _alreadyGreeted) then 
{
	private ["_hint", "_postFix"];
	switch (_topic) do 
	{
		case "core_en": {_postFix = "_EN"; _hint = " (" + (localize "STR_CONV_CORE_HINT_ENGLISH") + ")"};
		case "core_ru": {_postFix = "_RU"; _hint = " (" + (localize "STR_CONV_CORE_HINT_RUSSIAN") + ")"};
		case "core_cz": {_postFix = "_CZ"; _hint = " (" + (localize "STR_CONV_CORE_HINT_CHERNARUSSIAN") + ")"};
	};
	
	//Targets query.
	private ["_sentence"];	
	if ((random 1) > 0.5) then 
	{
		_sentence = "DidYouSeeAnyoneElseAroundHere";
	} 
	else 
	{
		_sentence = "DidYouNoticeAnythingOutOfTheOrdinaryRecently";
	};
	
	_result = _result + [[[((localize "STR_CONV_CORE_TARGETS") + "?" + _hint), [/*KEY_XBOX_B*/]], _topic, (_sentence + _postFix), []]];

	//Location query.
	//Check if we are near or in some settlement.
	private ["_location"];
	_location = nearestLocationWithDubbing (position player);
	
	if (!(isNull _location)) then 
	{
		//TODO: depends on size of Location?
		if (((locationPosition _location) distance player) > 150) then 
		{
			//Question selection.
			switch (floor (random 4)) do 
			{
				case 0: {_sentence = "WhereAreWe"};	
				case 1: {_sentence = "DoYouKnowWhereWeAre"};
				case 2: {_sentence = "WhereIsTheClosestSettlement"};
				case 3: {_sentence = "CanYouPointMeToTheNearestSettlement"};
				default {};
			};		
			
			_result = _result + [[[((localize "STR_CONV_CORE_LOCATION") + "?" + _hint), [/*KEY_XBOX_X*/]], _topic, (_sentence + _postFix), []]];
		} 
		else 
		{
			//This settlement?
			if ((random 1) > 0.5) then 
			{
				_sentence = "WhatIsTheNameOfThisSettlement";
			} 
			else 
			{
				_sentence = "WhatSettlementIsThis";
			};
			
			_result = _result + [[[((localize "STR_CONV_CORE_LOCATION") + "?" + _hint), [/*KEY_XBOX_X*/]], _topic, (_sentence + _postFix), []]];
		};
	};
	
	//Weather forecast query.
	if (overcast < 0.2) then 
	{
		_sentence = "NiceWeatherIsntIt";
	} 
	else 
	{
		if (overcast > 0.8) then 
		{
			_sentence = "ThatsSomeNastyWeatherAintIt";	
		} 
		else 
		{
			if ((random 1) > 0.5) then 
			{
				_sentence = "AnyWordOnWhatTheWeathersGonnaDo";
			} 
			else 
			{
				_sentence = "WhatsTheWeatherForecastLike";
			};
		};	
	};	
	
	_result = _result + [[[((localize "STR_CONV_CORE_WEATHER") + "?" + _hint), [/*KEY_XBOX_A*/]], _topic, (_sentence + _postFix), []]];
};

_result