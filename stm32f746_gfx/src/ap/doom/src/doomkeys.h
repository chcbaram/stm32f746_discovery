//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//       Key definitions
//

#ifndef __DOOMKEYS__
#define __DOOMKEYS__

//
// DOOM keyboard definition.
// This is the stuff configured by Setup.Exe.
// Most key data are simple ascii (uppercased).
//
#define D_KEY_RIGHTARROW	0xae
#define D_KEY_LEFTARROW	0xac
#define D_KEY_UPARROW	0xad
#define D_KEY_DOWNARROW	0xaf
#define D_KEY_ESCAPE	27
#define D_KEY_ENTER	13
#define D_KEY_TAB		9
#define D_KEY_F1		(0x80+0x3b)
#define D_KEY_F2		(0x80+0x3c)
#define D_KEY_F3		(0x80+0x3d)
#define D_KEY_F4		(0x80+0x3e)
#define D_KEY_F5		(0x80+0x3f)
#define D_KEY_F6		(0x80+0x40)
#define D_KEY_F7		(0x80+0x41)
#define D_KEY_F8		(0x80+0x42)
#define D_KEY_F9		(0x80+0x43)
#define D_KEY_F10		(0x80+0x44)
#define D_KEY_F11		(0x80+0x57)
#define D_KEY_F12		(0x80+0x58)

#define D_KEY_BACKSPACE	0x7f
#define D_KEY_PAUSE	0xff

#define D_KEY_EQUALS	0x3d
#define D_KEY_MINUS	0x2d

#define D_KEY_RSHIFT	(0x80+0x36)
#define D_KEY_RCTRL	(0x80+0x1d)
#define D_KEY_RALT	(0x80+0x38)

#define D_KEY_LALT	D_KEY_RALT

// new keys:

#define D_KEY_CAPSLOCK    (0x80+0x3a)
#define D_KEY_NUMLOCK     (0x80+0x45)
#define D_KEY_SCRLCK      (0x80+0x46)
#define D_KEY_PRTSCR      (0x80+0x59)

#define D_KEY_HOME        (0x80+0x47)
#define D_KEY_END         (0x80+0x4f)
#define D_KEY_PGUP        (0x80+0x49)
#define D_KEY_PGDN        (0x80+0x51)
#define D_KEY_INS         (0x80+0x52)
#define D_KEY_DEL         (0x80+0x53)

#define D_KEYP_0          KEY_INS
#define D_KEYP_1          KEY_END
#define D_KEYP_2          KEY_DOWNARROW
#define D_KEYP_3          KEY_PGDN
#define D_KEYP_4          KEY_LEFTARROW
#define D_KEYP_5          (0x80+0x4c)
#define D_KEYP_6          KEY_RIGHTARROW
#define D_KEYP_7          KEY_HOME
#define D_KEYP_8          KEY_UPARROW
#define D_KEYP_9          KEY_PGUP

#define D_KEYP_DIVIDE     '/'
#define D_KEYP_PLUS       '+'
#define D_KEYP_MINUS      '-'
#define D_KEYP_MULTIPLY   '*'
#define D_KEYP_PERIOD     0
#define D_KEYP_EQUALS     KEY_EQUALS
#define D_KEYP_ENTER      KEY_ENTER

#define SCANCODE_TO_KEYS_ARRAY {                                            \
    0,   0,   0,   0,   'a',                                  /* 0-9 */     \
    'b', 'c', 'd', 'e', 'f',                                                \
    'g', 'h', 'i', 'j', 'k',                                  /* 10-19 */   \
    'l', 'm', 'n', 'o', 'p',                                                \
    'q', 'r', 's', 't', 'u',                                  /* 20-29 */   \
    'v', 'w', 'x', 'y', 'z',                                                \
    '1', '2', '3', '4', '5',                                  /* 30-39 */   \
    '6', '7', '8', '9', '0',                                                \
    KEY_ENTER, KEY_ESCAPE, KEY_BACKSPACE, KEY_TAB, ' ',       /* 40-49 */   \
    KEY_MINUS, KEY_EQUALS, '[', ']', '\\',                                  \
    0,   ';', '\'', '`', ',',                                 /* 50-59 */   \
    '.', '/', KEY_CAPSLOCK, KEY_F1, KEY_F2,                                 \
    KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7,                   /* 60-69 */   \
    KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12,                              \
    KEY_PRTSCR, KEY_SCRLCK, KEY_PAUSE, KEY_INS, KEY_HOME,     /* 70-79 */   \
    KEY_PGUP, KEY_DEL, KEY_END, KEY_PGDN, KEY_RIGHTARROW,                   \
    KEY_LEFTARROW, KEY_DOWNARROW, KEY_UPARROW,                /* 80-89 */   \
    KEY_NUMLOCK, KEYP_DIVIDE,                                               \
    KEYP_MULTIPLY, KEYP_MINUS, KEYP_PLUS, KEYP_ENTER, KEYP_1,               \
    KEYP_2, KEYP_3, KEYP_4, KEYP_5, KEYP_6,                   /* 90-99 */   \
    KEYP_7, KEYP_8, KEYP_9, KEYP_0, KEYP_PERIOD,                            \
    0, 0, 0, KEYP_EQUALS,                                     /* 100-103 */ \
}

// Default names for keys, to use in English or as fallback.
#define KEY_NAMES_ARRAY {                                            \
    { KEY_BACKSPACE,  "BACKSP" },   { KEY_TAB,        "TAB" },       \
    { KEY_INS,        "INS" },      { KEY_DEL,        "DEL" },       \
    { KEY_PGUP,       "PGUP" },     { KEY_PGDN,       "PGDN" },      \
    { KEY_ENTER,      "ENTER" },    { KEY_ESCAPE,     "ESC" },       \
    { KEY_F1,         "F1" },       { KEY_F2,         "F2" },        \
    { KEY_F3,         "F3" },       { KEY_F4,         "F4" },        \
    { KEY_F5,         "F5" },       { KEY_F6,         "F6" },        \
    { KEY_F7,         "F7" },       { KEY_F8,         "F8" },        \
    { KEY_F9,         "F9" },       { KEY_F10,        "F10" },       \
    { KEY_F11,        "F11" },      { KEY_F12,        "F12" },       \
    { KEY_HOME,       "HOME" },     { KEY_END,        "END" },       \
    { KEY_MINUS,      "-" },        { KEY_EQUALS,     "=" },         \
    { KEY_NUMLOCK,    "NUMLCK" },   { KEY_SCRLCK,     "SCRLCK" },    \
    { KEY_PAUSE,      "PAUSE" },    { KEY_PRTSCR,     "PRTSC" },     \
    { KEY_UPARROW,    "UP" },       { KEY_DOWNARROW,  "DOWN" },      \
    { KEY_LEFTARROW,  "LEFT" },     { KEY_RIGHTARROW, "RIGHT" },     \
    { KEY_RALT,       "ALT" },      { KEY_LALT,       "ALT" },       \
    { KEY_RSHIFT,     "SHIFT" },    { KEY_CAPSLOCK,   "CAPS" },      \
    { KEY_RCTRL,      "CTRL" },     { KEYP_5,         "NUM5" },      \
    { ' ',            "SPACE" },                                     \
    { 'a', "A" },   { 'b', "B" },   { 'c', "C" },   { 'd', "D" },    \
    { 'e', "E" },   { 'f', "F" },   { 'g', "G" },   { 'h', "H" },    \
    { 'i', "I" },   { 'j', "J" },   { 'k', "K" },   { 'l', "L" },    \
    { 'm', "M" },   { 'n', "N" },   { 'o', "O" },   { 'p', "P" },    \
    { 'q', "Q" },   { 'r', "R" },   { 's', "S" },   { 't', "T" },    \
    { 'u', "U" },   { 'v', "V" },   { 'w', "W" },   { 'x', "X" },    \
    { 'y', "Y" },   { 'z', "Z" },   { '0', "0" },   { '1', "1" },    \
    { '2', "2" },   { '3', "3" },   { '4', "4" },   { '5', "5" },    \
    { '6', "6" },   { '7', "7" },   { '8', "8" },   { '9', "9" },    \
    { '[', "[" },   { ']', "]" },   { ';', ";" },   { '`', "`" },    \
    { ',', "," },   { '.', "." },   { '/', "/" },   { '\\', "\\" },  \
    { '\'', "\'" },                                                  \
}

#endif          // __DOOMKEYS__

