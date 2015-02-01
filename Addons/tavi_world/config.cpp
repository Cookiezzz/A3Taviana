#define _ARMA_

class CfgPatches
{
	class tavi_worlds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_epoch_code"};
	};
};
class CfgWorlds
{
	class CAWorld;
	class tavi: CAWorld
	{
		author = "Martin Bauer (OriginsMod Team)"; // Author
		description = "Taviana"; // World name
		pictureMap = "tavi_world\data\tavi_pic.paa"; // Background map


		// Loading texts displayed on the bottom of the loading screen (picked randomly)
		loadingTexts[]=
		{
			"The area of Taviana is about 625 square kilometers.",
			"Taviana is an island country situated in the Baltic Sea.",
			"The capital city of Taviana is Sabina."
		};

	};
};
