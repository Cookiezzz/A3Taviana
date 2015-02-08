//----------------------------------------
// script originally by Gnat
//----------------------------------------
// adapted by Sabre[Dust]
//----------------------------------------
// if you use it too, credit Gnat - and me pls : )
//----------------------------------------

_plane = _this select 0;
if !(local _plane) exitwith {};
_Float1 = "sabFloat1" createvehicle[0,0,0];


_Float1 setVectorUp [0,0,1];
sleep 0.1;  
// sleep command added, it's better for performance

while {(alive _plane)} do {
	_xx = getpos _plane select 0;
	_yy = getpos _plane select 1;
	_zz = getpos _plane select 2;
	_dd = getdir _plane;
	// getdir added, so the float can adjusted better
	
	sleep 0.025;
	// sleep command added, it's better for performance
	if(_zz < 7) then
	{
		if(surfaceIsWater [_xx, _yy]) then
		{
			_plane Animate ["LandContact", 1];
			
			//_Float1 setvelocity velocity _plane;
			_Float1 setVelocity [0, 0, 0]; 
			_Float1 setdir _dd;						
			_Float1 setpos [getpos _plane select 0, getpos _plane select 1, 0.4];
			
			sleep 0.025;
			// sleep command added, it's better for performance
		}
		else
		{
			// this puts down the fake gear so the plane can go up a beach
			
			_plane Animate ["LandContact", 0];
			_Float1 setPosASL [0,0,-10];
			_Float1 setVelocity [0, 0, 0]; 
			sleep 1;
			// sleep command added, it's better for performance
		};
	};

};
deleteVehicle _Float1;
