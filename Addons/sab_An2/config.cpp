// config.bin - 14:06:11 02/08/15, generated in 0.06 seconds
// Generated by unRap v1.06 by Kegetys
// Separate rootclasses: Disabled, Automatic comments: Enabled

#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

#define VSoft		0
#define VArmor		1
#define VAir		2

#define CanSeeRadar 1
#define CanSeeEye 2
#define CanSeeOptics 4
#define CanSeeEar 8
#define CanSeeCompass 16
#define CanSeeAll 31
#define CanSeePeripheral 32
#define CanSeeRadarC CanSeeRadar+CanSeeCompass

#define TEast		0
#define TWest		1
#define TGuerrila		2
#define TCivilian		3
#define TSideUnknown		4
#define TEnemy		5
#define TFriendly		6
#define TLogic		7

class CfgPatches {
	class sab_An2 {
		author[] = {"Sabre[Dust]"};
		authorUrl = "";
		version = 0.95;
		units[] = {"Sab_ana_An2", "sab_BI_An2", "sab_AH_An2", "sab_ca_An2", "sab_cz_An2", "Sab_ee_An2", "Sab_yel_An2", "Sab_ru_An2", "Sab_af_An2", "Sab_tk_An2", "Sab_A2_An2", "Sab_An2_b", "Sab_An2_i", "Sab_An2_o", "Sab_Snow2_An2", "Sab_Snow3_An2", "Sab_Snow_An2", "Sab_sea_An2", "Sab_sea2_An2", "Sab_sea3_An2", "Sab_sea4_An2", "Sab_Amphi_An2"};
		weapons[] = {};
		requiredAddons[] = {"A3_Air_F", "A3_Characters_F_Gamma"};
	};
};
class ViewPilot;	// External class reference

class CfgVehicles {
	class Strategic;	// External class reference
	class Air;	// External class reference
	class Ship;	// External class reference
	
	class sabFloat : Ship {
		scope = protected;
		animated = false;
		vehicleClass = "training";
		typicalCargo[] = {};
		irTarget = false;
		mapSize = 1;
		model = "\sab_An2\SeaVersion\sabFloat.p3d";
		icon = "";
		displayName = "float x";
		accuracy = 0.1;	// accuracy needed to recognize type of this target
		camouflage = 0.1;	// how dificult to spot - bigger - better spotable
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		destrType = "DestructTent";
		coefInside = 0.5;
		coefInsideHeur = 0.8;
		cost = 0;
		armor = 5000;
		
		class Turrets {};
	};
	
	class sabFloat1 : sabFloat {
		model = "\sab_An2\SeaVersion\sabFloat1.p3d";
		
		class Turrets {};
	};
	
	class Plane : Air {
		class NewTurret;	// External class reference
		class Sounds;	// External class reference
		class AnimationSources;	// External class reference
		
		class HitPoints {
			class HitHull;	// External class reference
		};
	};
	
	class sab_an2_BASE : Plane {
		displayName = "sab_An2";
		model = "\sab_an2\an2.p3d";
		icon = "sab_an2\data\icon_an2_civ.paa";
		picture = "sab_an2\data\picture_an2_ca.paa";
		mapSize = 20;
		hasGunner = true;
		fuelCapacity = 800;
		hascommander = false;
		startEngine = true;
		gearRetracting = false;
		fov = 0.7;
		cabinOpening = 0;
		crew = "C_man_shorts_2_F";
		
		class Library {
			libTextDesc = "From Wikipedia: The Antonov An-2 (Russian nickname: Annushka or Annie) is a Soviet mass-produced single-engine biplane utility/agricultural aircraft designed and manufactured by the Antonov Design Bureau (now State Company) since 1946.  The Guinness Book of World Records states that the 45-year production run for the An-2 was for a time the longest ever, for any aircraft, but it was recently exceeded by the Lockheed C-130 Hercules. A note from the pilot's handbook reads: If the engine quits in instrument conditions or at night, the pilot should pull the control column full aft and keep the wings level. The leading-edge slats will snap out at about 64 km/h (40 mph), and when the airplane slows to a forward speed of about 40 km/h (25 mph), the airplane will sink at about a parachute descent rate until the aircraft hits the ground. ...Don't count on that in Arma tho :)";
		};
		commanderCanSee = 30;	// default
		gunnerCanSee = 30;	// default
		driverCanSee = 30;	// default
		driverCompartments = "Compartment1";
		driverAction = "driver_Truck_02";
		driverIsCommander = true;
		ejectDeadDriver = true;
		hideWeaponsDriver = true;
		hideWeaponsCargo = false;
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		driverLeftHandAnimName = "stick_leftwheel";
		driverRightHandAnimName = "stick_pilot";
		driverLeftLegAnimName = "pedal1";
		driverRightLegAnimName = "pedal1";
		enableManualFire = 0;
		
		class Turrets {
			class MainTurret : NewTurret {
				commanding = -1;
				primaryGunner = 1;
				isCopilot = 1;
				proxyIndex = 1;
				ejectDeadGunner = true;
				caneject = 1;
				weapons[] = {};
				magazines[] = {};
				gunnerName = "Co-Pilot";
				gunnerCompartments = "Compartment1";
				gunnerUsesPilotView = true;
				gunnergetinaction = "GetInLow";
				gunnergetoutaction = "GetOutHigh";
				gunnerForceOptics = false;
				gunnerAction = "driver_Truck_02";
				gunnerlefthandanimname = "stick_rightwheel";
				gunnerrighthandanimname = "stick_pilot_2";
				gunnerLeftLegAnimName = "pedal2";
				gunnerRightLegAnimName = "pedal2";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				minElev = -60;
				maxElev = 10;
				initElev = 0;
				minTurn = -70;
				maxTurn = 70;
				initTurn = 0;
				
				// internal camera viewing limitations
				class ViewPilot : ViewPilot {
					initFov = 1;
					minFov = 0.3;
					maxFov = 1.2;
					initAngleX = 0;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -170;
					maxAngleY = 170;
				};
			};
			
			class GunnerTurret : NewTurret {
				enableCopilot = 0;
				commanding = -2;
				gunnerName = "Door seat 1";
				gunnerCompartments = "Compartment1";
				gunnerUsesPilotView = false;
				gunnerAction = "passenger_bench_1";
				primaryGunner = 0;
				isCopilot = 0;
				proxyIndex = 2;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				gunnergetinaction = "GetInLow";
				gunnergetoutaction = "GetOutHigh";
				caneject = 1;
				weapons[] = {};
				magazines[] = {};
				gunnerForceOptics = false;
				ejectDeadGunner = true;
				isPersonTurret = 1;
				minElev = -50;
				maxElev = 10;
				initElev = 0;
				minTurn = -25;
				maxTurn = 25;
				initTurn = 0;
				
				// internal camera viewing limitations
				class ViewPilot : ViewPilot {
					initFov = 1;
					minFov = 0.3;
					maxFov = 1.2;
					initAngleX = 0;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -170;
					maxAngleY = 170;
				};
			};
			
			class GunnerTurret2 : NewTurret {
				enableCopilot = 0;
				commanding = -3;
				gunnerName = "Door Seat 2";
				gunnerCompartments = "Compartment1";
				gunnerUsesPilotView = false;
				gunnerAction = "passenger_bench_1";
				primaryGunner = 0;
				isCopilot = 0;
				proxyIndex = 3;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				gunnergetinaction = "GetInLow";
				gunnergetoutaction = "GetOutHigh";
				caneject = 1;
				weapons[] = {};
				magazines[] = {};
				gunnerForceOptics = false;
				ejectDeadGunner = true;
				isPersonTurret = 1;
				minElev = -50;
				maxElev = 10;
				initElev = 0;
				minTurn = 0;
				maxTurn = 42;
				initTurn = 0;
				
				// internal camera viewing limitations
				class ViewPilot : ViewPilot {
					initFov = 1;
					minFov = 0.3;
					maxFov = 1.2;
					initAngleX = 0;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -170;
					maxAngleY = 170;
				};
			};
		};
		cargoCompartments[] = {"Compartment1"};
		ejectDeadCargo = true;
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		cargocaneject = 1;
		transportSoldier = 10;
		cargoProxyIndexes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		cargoGetInAction[] = {"GetOutLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		cargoAction[] = {"passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands"};
		transportMaxWeapons = 15;
		transportMaxMagazines = 45;
		transportMaxBackpacks = 10;
		
		class TransportItems {};
		maxFordingDepth = 0.3;
		passThrough = 0.7;
		crewVulnerable = "true";
		accuracy = 0.2;	// accuracy needed to recognize type of this target
		cost = 5000;
		laserScanner = false;
		gunAimDown = 0.029;
		minFireTime = 30;	// minimal time spent firing on single target
		
		// threat (VSoft, VArmor, VAir), how threatening vehicle is to unit types
		threat[] = {0.1, 1, 0.7};

		type = VAir;
		ejectSpeed[] = {1, 2, -1};
		armor = 35;
		damageResistance = 0.00278;
		destrType = "DestructWreck";
		irScanRangeMin = 500;
		irScanRangeMax = 5000;
		irScanToEyeFactor = 2;
		damageEffect = "DamageSmokePlane";
		weapons[] = {};
		magazines[] = {};
		hiddenSelections[] = {"camo1", "camo2", "camo3"};
		extCameraPosition[] = {0, 0, -15};
		maxSpeed = 258;	// max speed on level road, km/h
		aileronSensitivity = 0.8;	// relative aileron sensitivity
		elevatorSensitivity = 1.1;	// relative elevator sensitivity
		rudderInfluence = 0.02;
		aileronControlsSensitivityCoef = 3;
		elevatorControlsSensitivityCoef = 2;
		rudderControlsSensitivityCoef = 4;
		elevatorCoef[] = {0.7, 0.75, 0.75, 0.6, 0.55, 0.4, 0.3};
		aileronCoef[] = {0.6, 0.83, 0.91, 0.92, 0.93, 0.97, 1};
		rudderCoef[] = {};
		envelope[] = {0, 0.6, 1, 1.8, 2.8, 3.3, 3.5, 3.2, 2.6, 2, 1.5, 1, 0.7, 0.3};
		thrustCoef[] = {0.8, 1, 1.3, 1.25, 1.1, 1, 1, 0.9, 0.75, 0.65, 0.5, 0.25, 0};
		acceleration = 300;
		flapsFrictionCoef = 3.35;
		angleOfIndicence = 0.0523599;
		draconicForceXCoef = 1.5;
		draconicForceYCoef = 2.5;
		draconicForceZCoef = 0.5;
		draconicTorqueXCoef = 2.5;
		draconicTorqueYCoef = 1;
		landingSpeed = 50;
		wheelSteeringSensitivity = 1.5;
		canFloat = true;
		WaterLeakiness = 0.5;
		landingAoa = "rad 10";
		headAimDown = 0.029;
		insideSoundCoef = 0.6;
		nameSound = "plane";
		attenuationEffectType = "HeliAttenuation";
		soundGetIn[] = {"\sab_An2\data\sounds\close", 1, 1};
		soundGetOut[] = {"\sab_An2\data\sounds\open", 1, 1};
		soundDammage[] = {"\sab_An2\data\sounds\alarm_loop1", 0.562341, 1};
		soundEngineOnInt[] = {"\sab_An2\data\sounds\AN2_engine_start_int", 0.177828, 1};
		soundEngineOnExt[] = {"\sab_An2\data\sounds\AN2_engine_start_ext", 0.398107, 1, 600};
		soundEngineOffInt[] = {"\sab_An2\data\sounds\AN2_engine_stop_int", 0.177828, 1};
		soundEngineOffExt[] = {"\sab_An2\data\sounds\AN2_engine_stop_ext", 0.398107, 1, 600};
		soundFlapsUp[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Up", 0.398107, 1, 600};
		soundFlapsDown[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Down", 0.398107, 1, 600};
		
		class Sounds {
			class EngineLowOut {
				sound[] = {"\sab_An2\data\sounds\AN2_engine_low_ext", db5, 1, 900};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*engineOn*(rpm factor[0.85, 0])";
			};
			
			class EngineHighOut {
				sound[] = {"\sab_An2\data\sounds\AN2_engine_high_ext", db5, 1, 1100};
				frequency = "1";
				volume = "camPos*engineOn*(rpm factor[0.25, 1.0])";
			};
			
			class WindNoiseOut {
				sound[] = {"\sab_An2\data\sounds\ext-wind", db5, 1, 600};
				frequency = "(0.1+(1.2*(speed factor[1, 100])))";
				volume = "camPos*(speed factor[1, 100])";
			};
			
			class EngineLowIn {
				sound[] = {"\sab_An2\data\sounds\AN2_engine_low_int", db5, 1};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.65, 0]))";
			};
			
			class EngineHighIn {
				sound[] = {"\sab_An2\data\sounds\AN2_engine_high_int", db5, 1};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.25, 1.0]))";
			};
			
			class WindNoiseIn {
				sound[] = {"\sab_An2\data\sounds\int-wind", 0.398107, 1, 600};
				frequency = "(0.1+(1.2*(speed factor[1, 100])))";
				volume = "(1-camPos)*(speed factor[1, 100])";
			};
		};
		
		class Exhausts {
			class Exhaust1 {
				position = "exhaust";
				direction = "exhaust_dir";
				effect = "ExhaustsEffectPlane";
			};
			
			class Exhaust2 {
				position = "exhaust2";
				direction = "exhaust2_dir";
				effect = "ExhaustsEffectPlane";
			};
		};
		
		class HitPoints : HitPoints {
			class HitGlass1 {
				armor = 0.1;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = false;
			};
			
			class HitGlass2 {
				armor = 0.1;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = false;
			};
			
			class HitGlass3 {
				armor = 0.1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = false;
			};
			
			class HitGlass4 {
				armor = 0.1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = false;
			};
		};
		
		class AnimationSources {
			class cabindoor {
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			
			class HitGlass1 {
				source = "Hit";
				hitpoint = "HitGlass1";
				raw = 1;
			};
			
			class HitGlass2 : HitGlass1 {
				hitpoint = "HitGlass2";
			};
			
			class HitGlass3 : HitGlass1 {
				hitpoint = "HitGlass3";
			};
			
			class HitGlass4 : HitGlass1 {
				hitpoint = "HitGlass4";
			};
		};
		
		class UserActions {
			class opendoor {
				displayName = "Open Door";
				position = "pos cargo";
				radius = 8;
				showWindow = 0;
				onlyforplayer = 1;
				hideOnUse = 1;
				condition = "this animationPhase ""cabindoor"" < 0.5";
				statement = "this animate [""cabindoor"", 1]";
			};
			
			class closedoor {
				displayName = "Close Door";
				position = "pos cargo";
				radius = 40;
				showWindow = 0;
				onlyforplayer = 1;
				hideOnUse = 1;
				condition = "this animationPhase ""cabindoor"" >= 0.5 ";
				statement = "this animate [""cabindoor"", 0]";
			};
		};
		
		class Damage {
			tex[] = {};
			mat[] = {"sab_An2\data\an2_1.rvmat", "sab_An2\data\an2_1_damage.rvmat", "sab_An2\data\an2_1_destruct.rvmat", "sab_An2\data\an2_2.rvmat", "sab_An2\data\an2_2_damage.rvmat", "sab_An2\data\an2_2_destruct.rvmat", "sab_An2\data\an2_interier.rvmat", "sab_An2\data\an2_interier_damage.rvmat", "sab_An2\data\an2_interier_destruct.rvmat", "sab_An2\data\an2_cockpit.rvmat", "sab_An2\data\an2_cockpit_damage.rvmat", "sab_An2\data\an2_cockpit_destruct.rvmat", "sab_An2\data\an2_wings.rvmat", "sab_An2\data\an2_wings_damage.rvmat", "sab_An2\data\an2_wings_destruct.rvmat", "sab_An2\data\an2_window.rvmat", "sab_An2\data\an2_window_damage.rvmat", "sab_An2\data\an2_window_destruct.rvmat", "A3\Data_F\default.rvmat", "A3\Data_F\default.rvmat", "sab_An2\data\default_destruct.rvmat"};
		};
		
		class Reflectors {
			class Left {
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				position = "L svetlo";
				direction = "L svetlo dir";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				useFlare = 1;
				dayLight = 0;
				flareSize = 1;
				
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			
			class Right : Left {
				position = "P svetlo";
				direction = "P svetlo dir";
				hitpoint = "P svetlo";
				selection = "P svetlo";
			};
			
			class Interior : Left {
				color[] = {1900, 200, 200};
				ambient[] = {5, 1, 1};
				position = "I svetlo";
				direction = "I svetlo dir";
				hitpoint = "I svetlo";
				selection = "I svetlo";
				innerAngle = 75;
				outerAngle = 100;
				coneFadeCoef = 50;
				intensity = 0.01;
				useFlare = 0;
				
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 1;
					hardLimitEnd = 10;
				};
			};
			
			class Interior2 : Interior {
				position = "I svetlo 2";
				direction = "I svetlo 2 dir";
				hitpoint = "I svetlo 2";
				selection = "I svetlo 2";
				innerAngle = 180;
				outerAngle = 270;
				coneFadeCoef = 60;
				intensity = 0.01;
				useFlare = 0;
				
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 1;
					hardLimitEnd = 60;
				};
			};
		};
		
		class MarkerLights {
			class sab_RedStill {
				name = "PositionLight_red_1_pos";
				color[] = {1, 0.1, 0.1, 1};
				ambient[] = {0.1, 0.01, 0.01, 1};
				brightness = 0.04;
				blinking = false;
			};
			
			class sab_GreenStill {
				name = "PositionLight_green_1_pos";
				color[] = {0.1, 1, 0.1, 1};
				ambient[] = {0.01, 0.1, 0.01, 1};
				brightness = 0.04;
				blinking = false;
			};
			
			class sab_WhiteStill {
				name = "PositionLight_white_1_pos";
				color[] = {1, 1, 1, 1};
				ambient[] = {0.1, 0.1, 0.1, 1};
				brightness = 0.03;
				blinking = false;
			};
			
			class sab_WhiteCollision {
				name = "CollisionLight_white_1_pos";
				color[] = {1, 1, 1, 1};
				ambient[] = {0.1, 0.1, 0.1, 1};
				brightness = 0.03;
				blinking = true;
			};
		};
		
		// internal camera viewing limitations
		class ViewPilot : ViewPilot {
			initFov = 1;
			minFov = 0.3;
			maxFov = 1.2;
			initAngleX = 0;
			minAngleX = -75;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -170;
			maxAngleY = 170;
			initMoveX = 0;
			initMoveY = 0;
			initMoveZ = 0;
			minMoveX = -0.2;
			maxMoveX = 0.2;
			minMoveY = -0.025;
			maxMoveY = 0.1;
			minMoveZ = -0.2;
			maxMoveZ = 0.2;
		};
	};
	
	class sab_an2_BASE_sea : sab_an2_BASE {
		displayName = "sab_An2";
		model = "\sab_an2\an2sea.p3d";
		wheelSteeringSensitivity = 0.7;
		gearRetracting = false;
		landingSpeed = 60;
		acceleration = 140;
		maxSpeed = 190;	// max speed on level road, km/h
		armor = 75;
		aileronSensitivity = 0.6;	// relative aileron sensitivity
		elevatorSensitivity = 0.7;	// relative elevator sensitivity
		driveOnComponent[] = {"floatGeo"};
		canFloat = true;
		WaterLeakiness = 0;
		simulation = "airplane";
		
		class AnimationSources {
			class cabindoor {
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			
			class AnimLC {
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			
			class HitGlass1 {
				source = "Hit";
				hitpoint = "HitGlass1";
				raw = 1;
			};
			
			class HitGlass2 : HitGlass1 {
				hitpoint = "HitGlass2";
			};
			
			class HitGlass3 : HitGlass1 {
				hitpoint = "HitGlass3";
			};
			
			class HitGlass4 : HitGlass1 {
				hitpoint = "HitGlass4";
			};
		};
	};
	
	class sab_BI_An2 : sab_an2_BASE {
		author = "Sabre[Dust]";
		scope = public;
		displayName = "An-2 BohemiaInteractive";
		side = TCivilian;
		faction = CIV_F;
		vehicleClass = "air";
		driveOnComponent[] = {"wheel_1", "wheel_2", "wheel_3"};
		crew = "C_man_shorts_2_F";
		hiddenSelectionsTextures[] = {"sab_an2\data\BIAN2_1.paa", "sab_an2\data\czAN2_2.paa", "sab_an2\data\czAN2_wings.paa"};
		
		class TransportMagazines {};
		
		class TransportItems {
			class _xx_FirstAidKit {
				name = "FirstAidKit";
				count = 2;
			};
		};
		
		class TransportBackpacks {
			class _xx_B_Parachute {
				backpack = "B_Parachute";
				count = 4;
			};
		};
		
		class TransportWeapons {};
	};
	
	class Sab_cz_An2 : sab_BI_An2 {
		displayName = "An-2 Czech Aero Club";
		hiddenSelectionsTextures[] = {"sab_An2\data\czAN2_1.paa", "sab_An2\data\czAN2_2.paa", "sab_An2\data\czAN2_wings.paa"};
	};
	
	class Sab_fd_An2 : sab_BI_An2 {
		displayName = "An-2 Firefighter";
		hiddenSelectionsTextures[] = {"sab_An2\data\fdAN2_1.paa", "sab_An2\data\fdAN2_2.paa", "sab_An2\data\fdAN2_wings.paa"};
	};
	
	class Sab_yel_An2 : sab_BI_An2 {
		displayName = "An-2 Big Panda";
		hiddenSelectionsTextures[] = {"sab_An2\data\Sab_YP_AN2_1.paa", "sab_An2\data\Sab_YP_AN2_2.paa", "sab_An2\data\Sab_YP_AN2_3.paa"};
	};
	
	class Sab_ana_An2 : sab_BI_An2 {
		displayName = "An-2 Anastasija";
		hiddenSelectionsTextures[] = {"sab_An2\data\Sab_AJ_AN2_1.paa", "sab_An2\data\Sab_AJ_AN2_2.paa", "sab_An2\data\Sab_AJ_AN2_3.paa"};
	};
	
	class sab_AH_An2 : sab_BI_An2 {
		displayName = "An-2 Armaholic Promo Plane";
		hiddenSelectionsTextures[] = {"sab_an2\data\AHAN2_1.paa", "sab_an2\data\caAN2_2.paa", "sab_an2\data\caAN2_wings.paa"};
		maxSpeed = 285;	// max speed on level road, km/h
		armor = 15;
		crew = "C_Driver_1_yellow_F";
		thrustCoef[] = {1, 1.2, 1.3, 1.25, 1.1, 1, 1, 0.9, 0.75, 0.65, 0.5, 0.25, 0};
		acceleration = 300;
	};
	
	class sab_ca_An2 : sab_AH_An2 {
		displayName = "An-2 AirRacing";
		hiddenSelectionsTextures[] = {"sab_an2\data\caAN2_1.paa", "sab_an2\data\caAN2_2.paa", "sab_an2\data\caAN2_wings.paa"};
		maxSpeed = 325;	// max speed on level road, km/h
	};
	
	class Sab_ee_An2 : sab_BI_An2 {
		displayName = "An-2 Estonian AF";
		hiddenSelectionsTextures[] = {"sab_An2\data\eeAN2_1.paa", "sab_An2\data\eeAN2_2.paa", "sab_An2\data\eeAN2_wings.paa"};
		crew = "C_man_polo_2_F";
	};
	
	class Sab_ru_An2 : Sab_ee_An2 {
		displayName = "An-2 Russian AF";
		hiddenSelectionsTextures[] = {"sab_An2\data\eeAN2_1.paa", "sab_An2\data\ruAN2_2.paa", "sab_An2\data\eeAN2_wings.paa"};
	};
	
	class Sab_An2_b : sab_an2_BASE {
		author = "Sabre[Dust]";
		scope = public;
		displayName = "An-2 Bluefor";
		driveOnComponent[] = {"wheel_1", "wheel_2", "wheel_3"};
		
		// threat (VSoft, VArmor, VAir), how threatening vehicle is to unit types
		threat[] = {1, 1, 1};

		icon = "sab_an2\data\icon_an2_blu.paa";
		side = TWest;
		faction = BLU_G_F;
		vehicleClass = "air";
		crew = "B_G_Soldier_lite_F";
		draconicForceXCoef = 5;
		draconicForceYCoef = 1;
		draconicForceZCoef = 0.5;
		draconicTorqueXCoef = 0.15;
		draconicTorqueYCoef = 2.5;
		flapsFrictionCoef = 0.3;
		aileronSensitivity = 1.2;	// relative aileron sensitivity
		elevatorSensitivity = 2.3;	// relative elevator sensitivity
		noseDownCoef = 1;	// how much goes nose down during turns
		thrustCoef[] = {1.2, 1.6, 1.5, 1.2, 1.1, 1, 0.9, 0.8, 0.7, 0.6, 0.4, 0.2, 0, 0, 0, 0};
		maxSpeed = 275;	// max speed on level road, km/h
		armor = 25;
		hiddenSelectionsTextures[] = {"sab_An2\data\eeAN2_1.paa", "sab_An2\data\ruAN2_2.paa", "sab_An2\data\eeAN2_wings.paa"};
		
		class AnimationSources : AnimationSources {
			class cabindoor : cabindoor {
				initPhase = 1;
			};
		};
		weapons[] = {HMG_127};
		magazines[] = {"500Rnd_127x99_mag_Tracer_Yellow"};
		
		class TransportMagazines {
			class _xx_SmokeShellGreen {
				magazine = "SmokeShellGreen";
				count = 1;
			};
			
			class _xx_6Rnd_RedSignal_F {
				magazine = "6Rnd_RedSignal_F";
				count = 1;
			};
		};
		
		class TransportItems {
			class _xx_FirstAidKit {
				name = "FirstAidKit";
				count = 3;
			};
		};
		
		class TransportBackpacks {
			class _xx_B_Parachute {
				backpack = "B_Parachute";
				count = 3;
			};
		};
		
		class TransportWeapons {
			class _xx_Weapon_hgun_Pistol_Signal_F {
				weapon = "hgun_Pistol_Signal_F";
				count = 1;
			};
		};
	};
	
	class Sab_An2_i : Sab_An2_b {
		displayName = "An-2 Independent";
		side = TGuerrila;
		faction = IND_F;
		vehicleClass = "air";
		crew = "I_G_Soldier_lite_F";
		icon = "sab_an2\data\icon_an2_ind.paa";
		hiddenSelectionsTextures[] = {"sab_An2\data\eeAN2_1.paa", "sab_An2\data\ruAN2_2.paa", "sab_An2\data\eeAN2_wings.paa"};
	};
	
	class Sab_An2_o : Sab_An2_b {
		displayName = "An-2 Opfor";
		side = TEast;
		faction = OPF_F;
		vehicleClass = "air";
		crew = "O_G_Soldier_A_F";
		icon = "sab_an2\data\icon_an2_red.paa";
		hiddenSelectionsTextures[] = {"sab_An2\data\an2_1_co.paa", "sab_An2\data\an2_2_co.paa", "sab_An2\data\an2_wings_co.paa"};
	};
	
	class Sab_tk_An2 : sab_BI_An2 {
		displayName = "An-2 Air Tak";
		hiddenSelectionsTextures[] = {"sab_An2\data\an2_1_b_co.paa", "sab_An2\data\an2_2_b_co.paa", "sab_An2\data\an2_wings_b_co.paa"};
		crew = "C_man_polo_4_F";
	};
	
	class Sab_af_An2 : Sab_tk_An2 {
		displayName = "An-2 Aeroflot";
		hiddenSelectionsTextures[] = {"sab_An2\data\an2_1_a_co.paa", "sab_An2\data\an2_2_a_co.paa", "sab_An2\data\an2_wings_a_co.paa"};
	};
	
	class Sab_A2_An2 : Sab_tk_An2 {
		displayName = "An-2 Takistan Army";
		hiddenSelectionsTextures[] = {"sab_An2\data\an2_1_co.paa", "sab_An2\data\an2_2_co.paa", "sab_An2\data\an2_wings_co.paa"};
	};
	
	class Sab_Snow_An2 : sab_BI_An2 {
		crew = "C_man_hunter_1_F";
		displayName = "An-2PK Snow";
		model = "\sab_an2\an2snow.p3d";
		hiddenSelectionsTextures[] = {"sab_An2\SnowVersion\SnoAN2_1.paa", "sab_An2\SnowVersion\SnoAN2_2.paa", "sab_An2\SnowVersion\SnoAN2_wings.paa"};
		maxSpeed = 267;	// max speed on level road, km/h
	};
	
	class Sab_Snow2_An2 : Sab_Snow_An2 {
		displayName = "An-2PK Aeroflot";
		hiddenSelectionsTextures[] = {"sab_An2\data\an2_1_a_co.paa", "sab_An2\data\an2_2_a_co.paa", "sab_An2\data\an2_wings_a_co.paa"};
	};
	
	class Sab_Snow3_An2 : Sab_Snow_An2 {
		displayName = "An-2PK AF";
		hiddenSelectionsTextures[] = {"sab_An2\data\eeAN2_1.paa", "sab_An2\data\ruAN2_2.paa", "sab_An2\data\eeAN2_wings.paa"};
	};
	
	class Sab_sea_An2 : sab_an2_BASE_sea {
		author = "Sabre[Dust]";
		vehicleClass = "air";
		scope = public;
		displayName = "An-2V Sea Aeroflot";
		hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4"};
		hiddenSelectionsTextures[] = {"sab_An2\data\an2_1_a_co.paa", "sab_An2\data\an2_2_a_co.paa", "sab_An2\data\an2_wings_a_co.paa", "sab_An2\SeaVersion\float_red.paa"};
		canFloat = true;
		WaterLeakiness = 0;
		side = TCivilian;
		faction = CIV_F;
		crew = "C_man_shorts_4_F";
		
		class EventHandlers {
			init = "_this execvm 'sab_An2\scripts\An2SeaInit.sqf'";
		};
		
		class TransportItems {
			class _xx_FirstAidKit {
				name = "FirstAidKit";
				count = 2;
			};
		};
		
		class TransportBackpacks {};
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	
	class Sab_sea2_An2 : Sab_sea_An2 {
		displayName = "An-2V Anastasija";
		hiddenSelectionsTextures[] = {"sab_An2\data\Sab_AJ_AN2_1.paa", "sab_An2\data\Sab_AJ_AN2_2.paa", "sab_An2\data\Sab_AJ_AN2_3.paa", "sab_An2\SeaVersion\float_red.paa"};
	};
	
	class Sab_sea3_An2 : Sab_sea_An2 {
		displayName = "An-2V Army";
		hiddenSelectionsTextures[] = {"sab_An2\data\eeAN2_1.paa", "sab_An2\data\ruAN2_2.paa", "sab_An2\data\eeAN2_wings.paa", "sab_An2\SeaVersion\float_army.paa"};
	};
	
	class Sab_sea4_An2 : Sab_sea_An2 {
		displayName = "An-2V Fire Tanker";
		hiddenSelectionsTextures[] = {"sab_An2\data\fdAN2_1.paa", "sab_An2\data\fdAN2_2.paa", "sab_An2\data\fdAN2_wings.paa", "sab_An2\SeaVersion\float_fire.paa"};
	};
	
	class Sab_Amphi_An2 : Sab_sea_An2 {
		displayName = "An-2V Island Hoppers";
		hiddenSelectionsTextures[] = {"sab_An2\SeaVersion\seaAN2_1.paa", "sab_An2\SeaVersion\seaAN2_2.paa", "sab_An2\SeaVersion\seaAN2_wings.paa", "sab_An2\SeaVersion\float_sea.paa"};
	};
};

class cfgMods {
	author = 76561198037316212;
	timepacked = 1422713028;
};
