#pragma once

#include "raylib.h"

namespace PONG
{

    struct PADDLE
    {
        float speedY = 300.0f;
        Rectangle rectangle;
        Color paddleColor = WHITE;
    };

    void InitPaddles(PADDLE& leftPaddle, PADDLE& rightPaddle, float deltaTime);
    void DrawPaddles(PADDLE leftPaddle, PADDLE rightPaddle);
    void UpdatePaddles(PADDLE& leftPaddle, PADDLE& rightPaddle);

    void IncreasePaddleSpeed(PADDLE& leftPaddle, PADDLE& rightPaddle);
    void DefaultPaddleSpeed(PADDLE& leftPaddle, PADDLE& rightPaddle, float deltaTime);

}