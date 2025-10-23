/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MOUSEKEY_DELAY	10 //Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL	20	//Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA	8	//Step size
#define MOUSEKEY_MAX_SPEED	10	//Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX	30	//Time until maximum cursor speed is reached

#define MOUSEKEY_WHEEL_DELAY	10	//Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL	80	//Time between wheel movements
#define MOUSEKEY_WHEEL_DELTA	1	//Wheel movement step size
#define MOUSEKEY_WHEEL_MAX_SPEED	8	//Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX	40	//Time until maximum scroll speed is reached

// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 280
//#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 280

#define FLOW_TAP_TERM 280

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_LINUX
