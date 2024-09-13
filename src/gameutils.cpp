#include "gameutils.h"
#include "ball.h"
#include "paddles.h"
#include "constants.h"
#include "sl.h"

namespace PONG
{

    void InitGame(BALL& ball, PADDLE& leftPaddle, PADDLE& rightPaddle, float deltaTime)
    {
        InitBall(ball, deltaTime);
        InitPaddles(leftPaddle, rightPaddle, deltaTime);
    }

    void InitColors(Color& WHITE, Color& BLACK)
    {
        WHITE.r = 255;
        WHITE.g = 255;
        WHITE.b = 255;
    }


    void DrawGameElements(BALL ball, PADDLE leftPaddle, PADDLE rightPaddle, int player1Score, int player2Score, int player1GamesWon, int player2GamesWon)
    {
        BeginDrawing();

        ClearBackground(BLACK);


        DrawBall(ball);

        DrawPaddles(leftPaddle, rightPaddle);



        DrawText(TextFormat("Games won: %i", player1GamesWon), (screenWidth / 4) - 120, 20, 50, WHITE);

        DrawText(TextFormat("%i", player1Score), (screenWidth / 4), 70, 50, WHITE);



        DrawText(TextFormat("Games won: %i", player2GamesWon), ((screenWidth / 4) * 3) - 120, 20, 50, WHITE);

        DrawText(TextFormat("%i", player2Score), (screenWidth / 4) * 3, 70, 50, WHITE);



        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);


        EndDrawing();
    }

    void CheckCollisions(BALL& ball, PADDLE& leftPaddle, PADDLE& rightPaddle, int& player1Score, int& player2Score, float deltaTime)
    {
        bool player1Scores = ball.ballCenter.x >= GetScreenWidth();
        bool player2Scores = ball.ballCenter.x <= 0;
        bool ballOutOfBounds = ball.ballCenter.y >= GetScreenHeight() || ball.ballCenter.y <= 0;
        bool ballCanCollide = ball.collisionCooldown <= 0;

        if (player1Scores)
        {
            DefaultBallPosition(ball);
            DefaultBallSpeed(ball, deltaTime);
            DefaultPaddleSpeed(leftPaddle, rightPaddle, deltaTime);
            player1Score++;
        }

        else if (player2Scores)
        {
            DefaultBallPosition(ball);
            DefaultBallSpeed(ball, deltaTime);
            DefaultPaddleSpeed(leftPaddle, rightPaddle, deltaTime);
            player2Score++;
        }

        if (ballOutOfBounds)
        {
            ChangeDirectionOnY(ball);
        }

        if (ballCanCollide)
        {
            if (CheckCollisionCircleRec(ball.ballCenter, ball.radius, leftPaddle.rectangle))
            {
                ChangeDirectionOnX(ball);
                ResetCollisionCooldown(ball);
                IncreasePaddleSpeed(leftPaddle, rightPaddle);
                IncreaseBallSpeed(ball);
            }

            if (CheckCollisionCircleRec(ball.ballCenter, ball.radius, rightPaddle.rectangle))
            {
                ChangeDirectionOnX(ball);
                ResetCollisionCooldown(ball);
                IncreasePaddleSpeed(leftPaddle, rightPaddle);
                IncreaseBallSpeed(ball);
            }
        }
    }

}