// Open a door with an animated doorhandle.

// _this select 0		object pointer
// _this select 1		door animation
// _this select 2		doorhandle up->down animation
// _this select 3		doorhandle down->up animation

(_this select 0) say (_this select 1);
(_this select 0) animate [(_this select 2), 1]; sleep 1.5;
(_this select 0) animate [(_this select 2), 0];
(_this select 0) animate [(_this select 3), 0];
(_this select 0) animate [(_this select 4), 0];
(_this select 0) animate [(_this select 5), 0];
(_this select 0) animate [(_this select 6), 0];
(_this select 0) animate [(_this select 7), 0];
(_this select 0) animate [(_this select 8), 0];
