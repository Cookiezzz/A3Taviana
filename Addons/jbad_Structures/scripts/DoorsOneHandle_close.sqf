// Close multiple doors with a animated doorhandles.

// _this select 0		object pointer
// _this select 1		door animation
// _this select 2		doorhandle up->down animation
// _this select 3		doorhandle down->up animation
// _this select 4		door animation

(_this select 0) animate [(_this select 1), 0];
(_this select 0) animate [(_this select 2), 0];
(_this select 0) animate [(_this select 3), 0];
(_this select 0) animate [(_this select 4), 0];
