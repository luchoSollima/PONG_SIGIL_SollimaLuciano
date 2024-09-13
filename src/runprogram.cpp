#include "runprogram.h"
#include "scenes.h"
#include "sl.h"
#include "constants.h"
#include "ball.h"
#include "paddles.h"

namespace PONG
{

	void RunProgram()
	{
		SCENES nextScene = SCENES::Menu;

		BALL ball;
		PADDLE leftPaddle;
		PADDLE rightPaddle;

		Color WHITE;
		Color BLACK;

		int player1Score = 0;
		int player2Score = 0;
		int winningScore = 5;

		bool isPaused = false;
		bool gameFirstCall = true;


		slWindow(screenWidth, screenHeight, "SPEED PONG", 1);


		while (!slShouldClose())
		{
			switch (nextScene)
			{
			case SCENES::Menu:

				player1Score = 0;
				player2Score = 0;

				RunMenu(nextScene);

				break;
			case SCENES::Game:

				RunGame(nextScene, ball, leftPaddle, rightPaddle, player1Score, player2Score, winningScore, isPaused, gameFirstCall);

				break;
			case SCENES::Rules:

				ShowRules(nextScene);

				break;
			case SCENES::Credits:

				ShowCredits(nextScene);

				break;
			case SCENES::EndScreen:

				ShowEndScreen(nextScene, player1Score, winningScore);

				break;
			case SCENES::Exit:

				slClose();

			default:
				break;
			}
		}

		slClose();
	}

}