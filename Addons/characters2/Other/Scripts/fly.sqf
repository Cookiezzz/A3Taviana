// SCRIPT FOR GENERATING FLYES AROUND MASS GRAVE

// FIXED PARAMS
_source = "#particlesource" createVehicleLocal getpos (_this select 0);
_source setParticleParams 
/*Sprite*/		[["\ca\characters2\OTHER\FLY.p3d", 1, 0, 1, 0], "", // File, Ntieth, Index, Count, Loop(Bool)
/*Type*/ 			"spaceObject",
/*TimmerPer*/ 		1,
/*Lifetime*/ 		4,
/*Position*/		[0, 0, 0],
/*MoveVelocity*/	[0, 0, 0.5],
/*Simulation*/ 	1, 1.30, 1, 0, //rotationVel, weight, volume, rubbing
/*Scale*/			[0.03, 0.03, 0.03, 0],
/*Color*/			[[1, 1, 1, 1],[1, 1, 1, 1]],
/*AnimSpeed*/		[1.5,0.5],
/*randDirPeriod*/	0.01,
/*randDirIntesity*/	0.08,
/*onTimerScript*/ 	"",
/*DestroyScript*/ 	"",
/*Follow*/ 		_this];

// RANDOM / TOLERANCE PARAMS
_source setParticleRandom
/*LifeTime*/ 		[2,
/*Position*/		[2, 2, 0.25], 
/*MoveVelocity*/	[0, 0, 0],
/*rotationVel*/ 	1, 
/*Scale*/			0.02, 
/*Color*/			[0, 0, 0, 0.1],
/*randDirPeriod*/	0.01,
/*randDirIntesity*/ 0.03,
/*Angle*/ 		10];

_source setDropInterval 0.003;
a = createSoundSource["Sound_Flies",getpos (_this select 0),[],0];