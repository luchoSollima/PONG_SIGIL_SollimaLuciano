#include "ball.h"
#include "paddles.h"

namespace PONG
{

    void DefaultBallPosition(BALL& ball)
    {
        ball.ballCenter.x = 800;
        ball.ballCenter.y = 440;
    }

    void DefaultBallSpeed(BALL& ball, float deltaTime)
    {
        ball.speedX = 300.0f;
        ball.speedY = 250.0f;

        ball.speedX *= deltaTime;
        ball.speedY *= deltaTime;
    }

    void InitBall(BALL& ball, float deltaTime)
    {
        DefaultBallPosition(ball);

        DefaultBallSpeed(ball, deltaTime);
    }

    void DrawBall(BALL ball)
    {
        DrawCircleV(ball.ballCenter, ball.radius, ball.circleColor);
    }

    void MoveBall(BALL& ball)
    {
        ball.ballCenter.x += ball.speedX;

        ball.ballCenter.y += ball.speedY;
    }

    void UpdateBall(BALL& ball, PADDLE& leftPaddle, PADDLE& rightPaddle, int& player1Score, int& player2Score, float deltaTime)
    {
        if (ball.collisionCooldown > 0)
            ball.collisionCooldown -= deltaTime;

        MoveBall(ball);

        CheckCollisions(ball, leftPaddle, rightPaddle, player1Score, player2Score, deltaTime);
    }

    void ChangeDirectionOnX(BALL& ball)
    {
        ball.speedX *= -1;
    }

    void ChangeDirectionOnY(BALL& ball)
    {
        ball.speedY *= -1;
    }

    void IncreaseBallSpeed(BALL& ball)
    {
        ball.speedX *= 1.1f;
        ball.speedY *= 1.1f;
    }

    void ResetCollisionCooldown(BALL& ball)
    {
        ball.collisionCooldown = 0.5f;
    }

}