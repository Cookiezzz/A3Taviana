if !(isNil "EModStarted") exitWith { false };
EModStarted = true;
diag_log 'EMOD: Checking for mission file';
if (isClass (missionConfigFile >> 'CfgEmod')) then {
	if (getNumber (missionConfigFile >> 'CfgEmod' >> 'override') == 1) then {
		call compile preProcessFileLineNumbers (getText(missionConfigFile >> 'CfgEmod' >> 'file'));
	};
};
diag_log 'Continuing to load Epoch';
call compile preprocessFileLineNumbers '\x\addons\a3_epoch_code\init\fn_init.sqf';