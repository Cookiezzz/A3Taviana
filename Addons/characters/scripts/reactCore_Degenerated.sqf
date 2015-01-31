/*
	File: reactCore_Degenerated.sqf
	Author: Joris-Jan van 't Land

	Description:
	Processing which responses should be shown in the Core_Degenerated conversation.

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

//Someone spoke to me, but I don't understand it.
if (_sentenceId != "") then 
{
	//Determine my languages.
	private ["_languages", "_language"];
	_languages = getArray(configFile >> "CfgVehicles" >> (typeOf _this) >> "languages");
	_language = _languages select 0;
	
	//Tell in your primary language that you don't understand the other party.
	private ["_sentence"];
	switch (floor (random 3)) do 
	{
		case 0: {_sentence = "SorryIDontUnderstand"};
		case 1: {_sentence = "WhatAreYouSaying"};
		case 2: {_sentence = "IDontKnowWhatYouMean"};
	};

	_this kbTell [_from, _topic, (_sentence + "_" + _language)];
	
	//Determine remaining languages that can be tried.
	_languages = _languages - [_language];
	
	//Any language remain for _this?
	if ((count _languages) > 0) then 
	{
		//Find the best Core sentence.
		private ["_sentence"];
		_sentence = "";
		if ("EN" in _languages) then 
		{
			_sentence = _sentence + "_EN";
		};
	
		if ("CZ" in _languages) then 
		{
			_sentence = _sentence + "_CZ";
		};
	
		if ("RU" in _languages) then 
		{
			_sentence = _sentence + "_RU";
		};
		
		//Tell the other party which other languages you speak (automatically).
		_this kbTell [_from, "core", _sentence];
	};
};

_result