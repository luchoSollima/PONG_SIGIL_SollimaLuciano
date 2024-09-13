#pragma once

#include "ball.h"
#include "paddles.h"

namespace PONG
{
	struct Rectangle
	{
		int width;
		int height;
		int x;
		int y;
	};

	struct Vector2
	{
		int x;
		int y;
	};

	struct Color
	{
		float r;
		float g;
		float b;
		float a;
	};

	struct BALL;

	struct PADDLE;

	void InitGame(BALL& ball, PADDLE& leftPaddle, PADDLE& rightPaddle, float deltaTIme);
	void InitColors(Color& WHITE, Color& BLACK);
	void DrawGameElements(BALL ball, PADDLE leftPaddle, PADDLE rightPaddle, int player1Score, int player2Score, int player1GamesWon, int player2GamesWon);

	void CheckCollisions(BALL& ball, PADDLE& leftPaddle, PADDLE& rightPaddle, int& player1Score, int& player2Score, float deltaTime);

}