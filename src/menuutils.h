#pragma once

#include "raylib.h"

namespace PONG
{

	struct BUTTON
	{
		Rectangle rectangle;
		Color buttonColor = WHITE;
	};

	BUTTON InitButton(int positionY);
	bool IsMouseHoveringOverButton(BUTTON button);

	void DrawMenuElements(BUTTON buttonPlay, BUTTON buttonRules, BUTTON buttonCredits, BUTTON buttonExit);
	void DrawRules(BUTTON button);
	void DrawCredits(BUTTON button);
	void DrawEndScreen(BUTTON button, int player1Score, int winningScore);

}