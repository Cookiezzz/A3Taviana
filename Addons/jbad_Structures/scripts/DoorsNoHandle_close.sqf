// Close a door without an animated doorhandle.

// _this select 0		object pointer
// _this select 1		door animation
// _this select 2		door animation

(_this select 0) animate [(_this select 1), 0];
(_this select 0) animate [(_this select 2), 0];