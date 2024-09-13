#include "menuutils.h"
#include "raylib.h"
#include "constants.h"

namespace PONG
{

	BUTTON InitButton(int positionY)
	{
		BUTTON button;

		button.rectangle.width = 250;
		button.rectangle.height = 50;
		button.rectangle.x = (screenWidth / 2) - (button.rectangle.width / 2);
		button.rectangle.y = positionY;

		return button;
	}

	bool IsMouseHoveringOverButton(BUTTON button)
	{
		Vector2 mousePosition;

		mousePosition = GetMousePosition();


		bool hoveringOverButton = mousePosition.x > button.rectangle.x && mousePosition.x < button.rectangle.x + button.rectangle.width && mousePosition.y > button.rectangle.y && mousePosition.y < button.rectangle.y + button.rectangle.height;

		return hoveringOverButton;
	}

	void DrawMenuElements(BUTTON buttonPlay, BUTTON buttonRules, BUTTON buttonCredits, BUTTON buttonExit)
	{
		BeginDrawing();

		ClearBackground(BLACK);


		DrawRectangle((screenWidth / 2) - 200, 50, 400, 50, WHITE);

		DrawText("SPEED PONG", (screenWidth / 2) - 160, 55, 50, BLACK);



		DrawRectangleRec(buttonPlay.rectangle, buttonPlay.buttonColor);

		DrawRectangleRec(buttonRules.rectangle, buttonRules.buttonColor);

		DrawRectangleRec(buttonCredits.rectangle, buttonCredits.buttonColor);

		DrawRectangleRec(buttonExit.rectangle, buttonExit.buttonColor);



		DrawText("PLAY", buttonPlay.rectangle.x + 60, 205, 50, BLACK);

		DrawText("RULES", buttonRules.rectangle.x + 40, 305, 50, BLACK);

		DrawText("CREDITS", buttonCredits.rectangle.x + 10, 405, 50, BLACK);

		DrawText("EXIT", buttonExit.rectangle.x + 60, 505, 50, BLACK);



		EndDrawing();
	}

	void DrawRules(BUTTON buttonMainMenu)
	{
		BeginDrawing();

		ClearBackground(BLACK);


		DrawRectangle(200, 100, 1200, 560, WHITE);

		DrawText("Instructions:", 250, 150, 20, BLACK);

		DrawText("Player 1 uses the 'W' key to move the left paddle up and the 'S' key to move it down.", 250, 250, 20, BLACK);

		DrawText("Player 2 uses the UP arrow key to move the right paddle up and the DOWN arrow key to move it down.", 250, 350, 20, BLACK);

		DrawText("Every collision with the paddles speeds them up as well as the ball. It's going to get really fast!", 250, 450, 20, BLACK);

		DrawText("First to 5 points wins!", 250, 550, 20, BLACK);


		DrawRectangleRec(buttonMainMenu.rectangle, buttonMainMenu.buttonColor);

		DrawText("Main Menu", 720, 760, 30, BLACK);


		EndDrawing();
	}

	void DrawCredits(BUTTON buttonMainMenu)
	{
		BeginDrawing();

		ClearBackground(BLACK);


		DrawRectangle(200, 100, 1200, 560, WHITE);

		DrawText("Credits:", 250, 150, 20, BLACK);

		DrawText("Luciano Sollima", 250, 250, 20, BLACK);


		DrawRectangleRec(buttonMainMenu.rectangle, buttonMainMenu.buttonColor);

		DrawText("Main Menu", 720, 760, 30, BLACK);


		EndDrawing();
	}

	void DrawEndScreen(BUTTON buttonMainMenu, int player1Score, int winningScore)
	{
		BeginDrawing();

		ClearBackground(BLACK);


		DrawRectangle(200, 100, 1200, 560, WHITE);

		if (player1Score == winningScore)
			DrawText("Player 1 wins!", 600, 400, 50, BLACK);
		else
			DrawText("Player 2 wins!", 600, 400, 50, BLACK);


		DrawRectangleRec(buttonMainMenu.rectangle, buttonMainMenu.buttonColor);

		DrawText("Main Menu", 720, 760, 30, BLACK);


		EndDrawing();
	}

}