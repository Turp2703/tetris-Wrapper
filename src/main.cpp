#include "raylib-cpp.hpp"
#include "Game.h"
#include "Colors.h"

double lastUpdateTime = 0;
bool shouldUpdate(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    const int kScreenWidth = 500;
    const int kScreenHeight = 620;
    RWindow window(kScreenWidth, kScreenHeight, "Tetris-Wrapper");
    SetExitKey(KEY_NULL);
    window.SetTargetFPS(60);

    Game game;

    RText scoreText(GetFontDefault(), "Score", 38.f, 5.f, WHITE);
    RRectangle scoreRect(320, 55, 170, 60);
    RText scoreNumText(GetFontDefault(), "-", 38.f, 5.f, WHITE);
    RText nextText(GetFontDefault(), "Next", 38.f, 5.f, WHITE);
    RRectangle nextRect(320, 215, 170, 180);
    RText gameOverText1(GetFontDefault(), "GAME", 38.f, 5.f, WHITE);
    RText gameOverText2(GetFontDefault(), "OVER", 38.f, 5.f, WHITE);

    while (!window.ShouldClose())
    {
        game.HandleInput();

        scoreNumText.SetText(std::to_string(game.m_Score));

        if (shouldUpdate(0.2)) {
            game.MoveBlockDown();
        }

        window.BeginDrawing();
            window.ClearBackground(darkBlue);
            scoreText.Draw(345, 15);
            scoreRect.DrawRounded(0.3f,6,lightBlue);
            scoreNumText.Draw(320 + (170 - MeasureText(scoreNumText.GetText().c_str(), 38))/2, 64);
            nextText.Draw(350, 175);
            nextRect.DrawRounded(0.3f,6,lightBlue);
            if (game.m_GameOver)
            {
                gameOverText1.Draw(350, 450);
                gameOverText2.Draw(350, 480);
            }
            game.Draw();
        window.EndDrawing();
    }

    return 0;
}