//lock jiggle

// _this select 0		object pointer
// _this select 1		door animation

(_this select 0) animate [(_this select 1), 0]; sleep .05;
(_this select 0) animate [(_this select 2), 1]; sleep .05;
(_this select 0) animate [(_this select 3), 0]; sleep .05;
(_this select 0) animate [(_this select 4), 1];