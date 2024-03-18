#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

const int HEIGHT = 28;
const int WIDTH = 19;

char field[HEIGHT][WIDTH];

int currentPieceX = WIDTH / 2;
int currentPieceY = 28;

char currentPiece[4][4];


char tetrominoes[7][4][4] = {

    {
        {' ', ' ', ' ', ' '},
        {' ', '0', '0', '0'},
        {' ', ' ', '0', ' '},
        {' ', ' ', ' ', ' '}
    },
  
    {
        {' ', ' ', ' ', ' '},
        {' ', '0', '0', ' '},
        {' ', '0', '0', ' '},
        {' ', ' ', ' ', ' '}
    },

    {
        {' ', ' ', ' ', ' '},
        {' ', '0', '0 ',' '},
        {' ', ' ', '0', '0'},
        {' ', ' ', ' ', ' '}
    },
   
    {
        {' ', ' ', ' ', ' '},
        {'0', '0', '0', '0'},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    },
  
    {
        {' ', ' ', ' ', ' '},
        {'0', '0', '0', ' '},
        {'0', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    },
  
    {
        {' ', ' ', ' ', ' '},
        {'0', '0', '0', ' '},
        {' ', ' ', '0', ' '},
        {' ', ' ', ' ', ' '}
    },
  
    {
        {' ', ' ', ' ', ' '},
        {' ', ' ', '0', '0'},
        {' ', '0', '0', ' '},
        {' ', ' ', ' ', ' '}
    }
};

void Init() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            field[i][j] = ' ';
        }
    }
}

void Draw() {
    
    system("cls");
    cout << "=======================" << endl;
    for (int i = 0; i < HEIGHT; i++) {
        cout << "||";
        for (int j = 0; j < WIDTH; j++) {
            if (i >= currentPieceY && i < currentPieceY + 4 && j >= currentPieceX && j < currentPieceX + 4 &&
                currentPiece[i - currentPieceY][j - currentPieceX] != ' ') {
                cout << currentPiece[i - currentPieceY][j - currentPieceX];
            }
            else {
                cout << field[i][j];
            }
        }
        cout << "||";

        cout << endl;
    }
    cout << "=======================" << endl;
}
void RotatePiece() {

    // Создаем временный массив для сохранения повернутой фигуры
    char tempPiece[4][4];

    // Копируем текущую фигуру во временный массив
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tempPiece[i][j] = currentPiece[i][j];
        }
    }

    // Поворачиваем фигуру
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            currentPiece[i][j] = tempPiece[3 - j][i]; // Поворот на 90 градусов по часовой стрелке
        }
    }
}

bool CheckCollision(int xOffset, int yOffset) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (currentPiece[i][j] != ' ') {
                int newX = currentPieceX + xOffset + j;
                int newY = currentPieceY + yOffset + i;
                if (newX < 0 || newX >= WIDTH || newY >= HEIGHT || field[newY][newX] != ' ') {
                    return true;
                }
            }
        }
    }
    return false;

}

void Update() {

    if (!CheckCollision(0, 1)) {
        currentPieceY++;
    }
    else {
        // Фиксация фигуры на поле
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (currentPiece[i][j] != ' ') {
                    field[currentPieceY + i][currentPieceX + j] = currentPiece[i][j];
                }
            }
        }

        // Сброс текущей позиции фигуры
        currentPieceX = WIDTH / 2 - 2; // Изменено с WIDTH / 2
        currentPieceY = 0;

        // Генерация случайного индекса фигуры
        srand(time(NULL));
        int randomIndex = rand() % 7;

        // Копирование выбранной фигуры в текущую фигуру
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                currentPiece[i][j] = tetrominoes[randomIndex][i][j];
            }
        }
    }
}

void MovePiece(char direction) {

    switch (direction) {
    case 'a':
        if (!CheckCollision(-1, 0)) {
            currentPieceX--;
        }
        break;
    case 'd':
        if (!CheckCollision(1, 0)) {
            currentPieceX++;
        }
        break;

    case 's':
        if (!CheckCollision(0, 1)) {
            currentPieceY++;
        }

    }


}
void gameOver() {
    cout<<endl << "игра закончена !";
    return exit(0);
}


int main() {
    setlocale(LC_ALL, "");
    system("color 3F");
    Init();
    while (true) {
        Draw();
        if (_kbhit()) {
            char key = _getch();
            if (key == 'a' || key == 'd' || key == 'w') {
                MovePiece(key);
            }
            if (key == 'w') {
                RotatePiece();
            }
            if (key == 's') {
                MovePiece(key);
            }
            if (key == 'o') {
                gameOver();
            }
        }

        Update();
        Sleep(10);
    }
    return 0;

}