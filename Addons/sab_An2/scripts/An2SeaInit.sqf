//----------------------------------------
// script originally by Gnat
//----------------------------------------
// adapted by Sabre[Dust]
//----------------------------------------
// if you use it too, credit Gnat - and me pls : )
//----------------------------------------

if (!isServer) exitWith {};
_plane = _this select 0;

_makefakefloat = [_plane] execvm "\sab_An2\scripts\An2posFloat.sqf";

sleep 0.2; 
// sleep command added, it's better for performance

_xx = getpos _plane select 0;
_yy = getpos _plane select 1;
_zz = getpos _plane select 2;
if ((_zz < 7) and (surfaceIsWater [_xx, _yy])) then
{
	_plane setposasl [_xx, _yy, 0.0];
};


