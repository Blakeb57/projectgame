#include "cmdcolor.h"
#include <iostream>
#include <windows.h>

std::ostream& cmdcolor::operator << (std::ostream& outs, const cmdcolor::color& clr) {
	static int defaultColor = 0;
	CONSOLE_SCREEN_BUFFER_INFO info;

	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
		return outs;

	unsigned char current = info.wAttributes;
	// first four bits are -> current >> 4
	// last four bits are -> current & 0x0f
	unsigned char background = (current >> 4);
	unsigned char text = (current & 0x0f);

	if (!defaultColor) {
		defaultColor = current + 1;
	}

	if (clr > 15) {
		// I want to change the background color
		background = clr - 0x10;
	}
	else {
		// I want to change the text color
		text = clr;
	}

	// Reconstruct the number from the bits
	unsigned char totalColor = (background << 4) | text;


	if (clr == DEFAULT) {
		totalColor = defaultColor - 1;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), totalColor);
	return outs;
}
