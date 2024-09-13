#include "paddles.h"
#include "constants.h"
#include "ball.h"

namespace PONG
{

    void InitPaddles(PADDLE& leftPaddle, PADDLE& rightPaddle, float deltaTime)
    {
        leftPaddle.rectangle.x = 100;
        leftPaddle.rectangle.y = 400;
        leftPaddle.rectangle.width = 20;
        leftPaddle.rectangle.height = 120;

        rightPaddle.rectangle.x = 1500;
        rightPaddle.rectangle.y = 400;
        rightPaddle.rectangle.width = 20;
        rightPaddle.rectangle.height = 120;
        
        DefaultPaddleSpeed(leftPaddle, rightPaddle, deltaTime);
    }

    void DrawPaddles(PADDLE leftPaddle, PADDLE rightPaddle)
    {
        //DrawRectangleRec(leftPaddle.rectangle, leftPaddle.paddleColor);
        //DrawRectangleRec(rightPaddle.rectangle, rightPaddle.paddleColor);
    }

    void UpdatePaddles(PADDLE& leftPaddle, PADDLE& rightPaddle)
    {
        if (slGetKey(SL_KEY_UP) != 0 && rightPaddle.rectangle.y >= 0)
            rightPaddle.rectangle.y -= rightPaddle.speedY;

        if (slGetKey(SL_KEY_DOWN) != 0 && rightPaddle.rectangle.y <= screenHeight - rightPaddle.rectangle.height)
            rightPaddle.rectangle.y += rightPaddle.speedY;



        if (slGetKey('W') != 0 && leftPaddle.rectangle.y >= 0)
            leftPaddle.rectangle.y -= leftPaddle.speedY;

        if (slGetKey('S') != 0 && leftPaddle.rectangle.y <= screenHeight - leftPaddle.rectangle.height)
            leftPaddle.rectangle.y += leftPaddle.speedY;
    }

    void IncreasePaddleSpeed(PADDLE& leftPaddle, PADDLE& rightPaddle)
    {
        leftPaddle.speedY *= 1.1f;
        rightPaddle.speedY *= 1.1f;
    }

    void DefaultPaddleSpeed(PADDLE& leftPaddle, PADDLE& rightPaddle, float deltaTime)
    {
        leftPaddle.speedY = 300.0f;
        rightPaddle.speedY = 300.0f;

        leftPaddle.speedY *= deltaTime;
        rightPaddle.speedY *= deltaTime;
    }

}
