class CfgPatches {
	class A3_emod {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_epoch_code"};
	};
};

class cfgFunctions {
	class Emod {
		class Emod_Pre_Init {
			file = "\x\addons\a3_emod\init";
			class init {
				preInit = 1;
			};
		};
	};
	class A3 {
		tag = BIS;
		class Epoch_Client_Pre {
			file = "\x\addons\a3_epoch_code\init";
			class init {
				preinit = 0;
			};
		};
		class Epoch_Client {
			file = "\x\addons\a3_epoch_code\init";
			
			class init {
				preInit = 0;
			};
			
			class postinit {
				postInit = 1;
			};
		};
	};
};