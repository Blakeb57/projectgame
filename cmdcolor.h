//***********************************************************
//
//  File:   cmdcolor.h
//
//  Author: Kaeden Saunders
//  Email:  ks679318@ohio.edu
//
//  Usage:  This is for use in a cmd window when running
//			code. It contains reserved words for every
//			color a cmd window can change to. A default
//			is also included, so that the window can be
//			changed back to the colors that were used 
//			as default before the program was run.
//			Also remember to use the namespace cmdcolor
//
//	Example:To use this header, simply cout the color you
//			want. B_ signifies a background color.
//			std::cout << RED; changes text color to red
//			std::cout << B_GRAY; changes background to 
//						gray, keeping the text color the same
//			std::cout << DEFAULT should be used at the very
//						end of every program, to bring the
//						window's colors back to default.
//
//***********************************************************

#ifndef CMDCOLOR_H
#define CMDCOLOR_H

#include <iostream>
namespace cmdcolor {
	enum color 
	{
		BLACK = 0, 	BLUE, GREEN, AQUA, RED, PURPLE, YELLOW, WHITE, GRAY, LIGHTBLUE, LIGHTGREEN, LIGHTAQUA, LIGHTRED, LIGHTPURPLE, LIGHTYELLOW, LIGHTWHITE,
					B_BLACK, B_BLUE, B_GREEN, B_AQUA, B_RED, B_PURPLE, B_YELLOW, B_WHITE, B_GRAY, B_LIGHTBLUE, B_LIGHTGREEN, B_LIGHTAQUA, B_LIGHTRED, 
					B_LIGHTPURPLE, B_LIGHTYELLOW, B_LIGHTWHITE, DEFAULT = 1000
	};

	std::ostream& operator << (std::ostream& outs, const color& clr);
}

#endif //CMDCOLOR_H
