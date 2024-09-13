#pragma once

#include "runprogram.h"
#include "ball.h"

namespace PONG
{

	void RunMenu(SCENES& nextScene);
	void RunGame(SCENES& nextScene, BALL& ball, PADDLE& leftPaddle, PADDLE& rightPaddle, int& player1Score, int& player2Score, int winningScore, bool& isPaused, bool& gameFirstCall);

	void ShowRules(SCENES& nextScene);
	void ShowCredits(SCENES& nextScene);

	void ShowEndScreen(SCENES& nextScene, int player1Score, int winningScore);

}