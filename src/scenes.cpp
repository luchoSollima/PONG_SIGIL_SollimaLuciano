#include "scenes.h"
#include "gameutils.h"
#include "menuutils.h"
#include "constants.h"

namespace PONG
{

    int player1GamesWon = 0;
    int player2GamesWon = 0;

    void RunMenu(SCENES& nextScene)
    {
        BUTTON buttonPlay;
        BUTTON buttonRules;
        BUTTON buttonCredits;
        BUTTON buttonExit;

        buttonPlay = InitButton(205);
        buttonRules = InitButton(305);
        buttonCredits = InitButton(405);
        buttonExit = InitButton(505);


        DrawMenuElements(buttonPlay, buttonRules, buttonCredits, buttonExit);

        

        if (IsMouseHoveringOverButton(buttonExit) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT) != 0)
            nextScene = SCENES::Exit;

        else if (IsMouseHoveringOverButton(buttonPlay) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT) != 0)
            nextScene = SCENES::Game;

        else if (IsMouseHoveringOverButton(buttonRules) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT) != 0)
            nextScene = SCENES::Rules;

        else if (IsMouseHoveringOverButton(buttonCredits) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT) != 0)
            nextScene = SCENES::Credits;

    }

    void RunGame(SCENES& nextScene, BALL& ball, PADDLE& leftPaddle, PADDLE& rightPaddle, int& player1Score, int& player2Score, int winningScore, bool& isPaused, bool& gameFirstCall)
    {
        double deltaTime = slGetDeltaTime();

        if (gameFirstCall)
        {
            InitGame(ball, leftPaddle, rightPaddle, deltaTime);
            gameFirstCall = false;
        }

        if (player1Score == winningScore || player2Score == winningScore)
        {
            if (player1Score == winningScore)
                player1GamesWon++;
            else
                player2GamesWon++;

            gameFirstCall = true;

            nextScene = SCENES::EndScreen;
        }

        else
        {
            if (slGetKey('P') != 0)
            {
                if (!isPaused)
                    isPaused = true;
                else
                    isPaused = false;
            }

            if (!isPaused)
            {
                UpdateBall(ball, leftPaddle, rightPaddle, player1Score, player2Score, deltaTime);
                UpdatePaddles(leftPaddle, rightPaddle);
            }


            DrawGameElements(ball, leftPaddle, rightPaddle, player1Score, player2Score, player1GamesWon, player2GamesWon);


            if (isPaused)
            {
                slText(300.0, 200.0, "Game Paused");
                slText(290.0, 250.0, "Press P to resume");
                //DrawText("Game Paused", 300, 200, 40, LIGHTGRAY);
                //DrawText("Press P to resume", 290, 250, 30, LIGHTGRAY);

                slText(1050.0, 200.0, "Game Paused");
                slText(1040.0, 250.0, "Press P to resume");
                //DrawText("Game Paused", 1050, 200, 40, LIGHTGRAY);
                //DrawText("Press P to resume", 1040, 250, 30, LIGHTGRAY);
            }
        }

    }

    void ShowRules(SCENES& nextScene)
    {
        BUTTON buttonMainMenu;

        buttonMainMenu = InitButton(750);


        DrawRules(buttonMainMenu);

        if (IsMouseHoveringOverButton(buttonMainMenu) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT) != 0)
            nextScene = SCENES::Menu;
    }

    void ShowCredits(SCENES& nextScene)
    {
        BUTTON buttonMainMenu;

        buttonMainMenu = InitButton(750);


        DrawCredits(buttonMainMenu);

        if (IsMouseHoveringOverButton(buttonMainMenu) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT) != 0)
            nextScene = SCENES::Menu;
    }

    void ShowEndScreen(SCENES& nextScene, int player1Score, int winningScore)
    {
        BUTTON buttonMainMenu;

        buttonMainMenu = InitButton(750);


        DrawEndScreen(buttonMainMenu, player1Score, winningScore);

        if (IsMouseHoveringOverButton(buttonMainMenu) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT) != 0)
            nextScene = SCENES::Menu;
    }

}