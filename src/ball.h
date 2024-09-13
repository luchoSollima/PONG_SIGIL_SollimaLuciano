#pragma once

#include "raylib.h"
#include "paddles.h"
#include "gameutils.h"

namespace PONG
{

    struct BALL
    {
        float speedX = 300.0f;
        float speedY = 250.0f;
        Vector2 ballCenter;
        float radius = 20.0f;
        Color circleColor = WHITE;
        float collisionCooldown = 0.0f;
    };

    void DefaultBallPosition(BALL& ball);
    void DefaultBallSpeed(BALL& ball, float deltaTime);
    void InitBall(BALL& ball, float deltaTime);
    void DrawBall(BALL ball);
    void MoveBall(BALL& ball);

    void UpdateBall(BALL& ball, PADDLE& leftPaddle, PADDLE& rightPaddle, int& player1Score, int& player2Score, float deltaTime);
    void ChangeDirectionOnX(BALL& ball);
    void ChangeDirectionOnY(BALL& ball);
    void IncreaseBallSpeed(BALL& ball);
    void ResetCollisionCooldown(BALL& ball);

}