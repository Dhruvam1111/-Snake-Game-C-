#include <iostream> // For stdin and stdout functions
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep() and console cursor handling
#include <cstdlib> // For rand() function and system("cls") 
#include <list> // To generate linked list function for snake

using namespace std;

const int WIDTH = 20, HEIGHT = 20;
enum Direction // To define all directions of snake
{
    STOP = 0,
    UP, // 1 (Implicitly assigned)
    DOWN, // 2 (Implicitly assigned)
    LEFT, // 3 (Implicitly assigned)
    RIGHT // 4 (Implicitly assigned)
};

class SnakeGame 
{
private:
    bool gameOver;
    int score;
    int speed;
    pair<int, int> food;
    Direction dir;
    list<pair<int, int>> snake; // Linked List for Snake's body

    void moveCursorToTop()
    {
        COORD cursorPos;
        cursorPos.X = 0;
        cursorPos.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
    }

    void displayInstructions()
    {
        system("cls");
        cout << "========== SNAKE GAME ==========\n";
        cout << "Instructions:\n";
        cout << " - Use 'W' 'A' 'S' 'D' to move the snake.\n";
        cout << " - Eat 'F' (food) to grow and increase score.\n";
        cout << " - Avoid hitting the walls (#) and yourself.\n";
        cout << " - Press 'X' to exit the game.\n";
        cout << " - Press 'R' after Game Over to restart.\n";
        cout << " - Choose Difficulty Levels:\n";
        cout << " - Press '1' for Easy  (Slow Speed)\n";
        cout << " - Press '2' for Medium (Normal Speed)\n";
        cout << " - Press '3' for Hard  (Fast Speed)\n";
        cout << "================================\n\n";
        system("pause");
    }

public:
    SnakeGame()
    {
        displayInstructions();
        setDifficulty();
        resetGame();
    }

    void setDifficulty()
    {
        int choice;
        cout << "Select Difficulty Level:\n";
        cout << "1. Easy\n2. Medium\n3. Hard\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            speed = 150;
            break; // Slow
        case 2:
            speed = 100;
            break; // Normal
        case 3:
            speed = 50;
            break; // Fast
        default:
            speed = 100;
            break; // Default to Medium
        }
    }

    void resetGame()
    {
        gameOver = false;
        dir = STOP;
        score = 0;
        snake.clear();

        // Initialize Snake with 3 cells
        int startX = WIDTH / 2, startY = HEIGHT / 2;
        for (int i = 0; i < 3; i++)
        {
            snake.push_back({startY, startX - i});
        }

        spawnFood();
    }

    void spawnFood()
    {
        bool valid = false;
        while (!valid)
        {
            food.first = rand() % HEIGHT;
            food.second = rand() % WIDTH;
            valid = true;
            for (auto segment : snake)
            {
                if (segment == food)
                {
                    valid = false;
                    break;
                }
            }
        }
    }

    void drawBoard()
    {
        moveCursorToTop();

        // Top Wall
        for (int i = 0; i < WIDTH + 2; i++)
            cout << "\033[34m#\033[0m";
        cout << endl;

        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (x == 0)
                    cout << "\033[34m#\033[0m"; // Left wall

                if (make_pair(y, x) == snake.front())
                    cout << "\033[32mO\033[0m"; // Green Snake Head
                else if (make_pair(y, x) == food)
                    cout << "\033[31mF\033[0m"; // Red Food
                else
                {
                    bool printed = false;
                    for (auto segment : snake)
                    {
                        if (segment == make_pair(y, x))
                        {
                            cout << "\033[32mo\033[0m"; // Green Snake Body
                            printed = true;
                            break;
                        }
                    }
                    if (!printed)
                        cout << " ";
                }

                if (x == WIDTH - 1)
                    cout << "\033[34m#\033[0m"; // Right wall
            }
            cout << endl;
        }

        // Bottom Wall
        for (int i = 0; i < WIDTH + 2; i++)
            cout << "\033[34m#\033[0m";
        cout << "\nScore: " << score << endl;
    }

    void handleInput()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'w':
            case 'W':
                if (dir != DOWN)
                    dir = UP;
                break;
            case 's':
            case 'S':
                if (dir != UP)
                    dir = DOWN;
                break;
            case 'a':
            case 'A':
                if (dir != RIGHT)
                    dir = LEFT;
                break;
            case 'd':
            case 'D':
                if (dir != LEFT)
                    dir = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    void updateGame()
    {
        if (dir == STOP)
            return;

        pair<int, int> newHead = snake.front();

        switch (dir)
        {
        case UP:
            newHead.first--;
            break;
        case DOWN:
            newHead.first++;
            break;
        case LEFT:
            newHead.second--;
            break;
        case RIGHT:
            newHead.second++;
            break;
        default:
            break;
        }

        if (newHead.first < 0 || newHead.first >= HEIGHT ||
            newHead.second < 0 || newHead.second >= WIDTH)
        {
            gameOver = true;
            return;
        }

        for (auto segment : snake)
        {
            if (newHead == segment)
            {
                gameOver = true;
                return;
            }
        }

        snake.push_front(newHead);

        if (newHead == food)
        {
            score += 10;
            spawnFood();
        }
        else
        {
            snake.pop_back();
        }
    }

    void run()
    {
        system("cls");
        while (!gameOver)
        {
            drawBoard();
            handleInput();
            updateGame();
            Sleep(speed);
        }

        cout << "\nGame Over! Final Score: " << score << endl;
        cout << "Press R to Restart or X to Exit..." << endl;

        char choice;
        while (true)
        {
            choice = _getch();
            if (choice == 'r' || choice == 'R')
            {
                system("cls");
                displayInstructions();
                setDifficulty(); // Ask for difficulty again
                resetGame();
                run();
                return;
            }
            else if (choice == 'x' || choice == 'X')
            {
                exit(0);
            }
        }
    }
};

int main()
{
    SnakeGame game;
    game.run();
    return 0;
}
