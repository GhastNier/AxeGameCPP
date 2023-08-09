#include "raylib.h"

int main()
{
    int winWidth{800};
    int winHeight{450};
    InitWindow(winWidth, winHeight, "This is a window");
    
    int circleX{200};
    int circleY{200};
    int circleRadius{25};
    int moveCircle{5};
    int maxRight{winWidth - circleRadius - moveCircle};
    int maxLeft{circleRadius + moveCircle};
    int maxBottom{winHeight - circleRadius - moveCircle};
    int maxTop{circleRadius + moveCircle};

    // Axe
    int axeX{400};
    int axeY{0};
    int axeLength{50};

    // Edges circle
    int lCircleX{circleX + circleRadius};
    int rCircleX{circleX - circleRadius};
    int uCircleY{circleY + circleRadius};
    int bCircleY{circleY - circleRadius};
    // Edges Axe
    int lAxeX{axeX};
    int rAxeX{axeX + axeLength};
    int uAxeY{axeY};
    int bAxeY{axeY + axeLength};
    int moveAxe{10};
    bool collisionIsTrue;
    collisionIsTrue =
        (bAxeY >= uCircleY) &&
        (uAxeY <= bCircleY) &&
        (lAxeX <= rCircleX) &&
        (rAxeX >= lCircleX);
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        if (collisionIsTrue)
        {
            ClearBackground(BLACK);
            DrawText("Game Over... \nGIT GUD!", 300, 125, 40, RED);
        }
        else
        {
            ClearBackground(WHITE);

            lCircleX = circleX - circleRadius;
            rCircleX = circleX + circleRadius;
            uCircleY = circleY - circleRadius;
            bCircleY = circleY + circleRadius;
            lAxeX = axeX;
            rAxeX = axeX + axeLength;
            uAxeY = axeY;
            bAxeY = axeY + axeLength;
            if ((bAxeY >= uCircleY) &&
                (uAxeY <= bCircleY) &&
                (lAxeX <= rCircleX) &&
                (rAxeX >= lCircleX))
            {
                collisionIsTrue = true;
            }
            DrawCircle(circleX, circleY, circleRadius, BLUE);
            DrawRectangle(axeX, axeY, axeLength, axeLength, RED);

            axeY += moveAxe;
            if (axeY > winHeight - 50 || axeY < 5)
            {
                moveAxe = -moveAxe;
            }
            if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && circleX < maxRight)
            {
                circleX += moveCircle;
            }
            if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && circleX > maxLeft)
            {
                circleX -= moveCircle;
            }
            if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && circleY > maxTop)
            {
                circleY -= moveCircle;
            }
            if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && circleY < maxBottom)
            {
                circleY += moveCircle;
            }
            if (collisionIsTrue)
            {
                collisionIsTrue = true;
            }
            else
            {
                collisionIsTrue = false;
            }
        }
        EndDrawing();
    }
}