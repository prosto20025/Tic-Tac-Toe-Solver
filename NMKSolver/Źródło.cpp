#include <iostream>
#include <string.h>
#define FIRST_PLAYER_WON -10
#define SECOND_PLAYER_WON 10
#define DRAW 0
using namespace std;
int GameEndDiagonally(int N, int M, int K, char ActivePlayer, char** gameBoard)
{
    int repetationsDiagonallyP1 = 0;
    int repetationsDiagonallyP2 = 0;
    for (int i = 0; i <= M - K; i++)
    {
        for (int j = 0; j <= N - K; j++)
        {
            for (int k = 0; k < K; k++)
            {
                if (gameBoard[j + k][i + k] == '1')
                {
                    repetationsDiagonallyP1++;
                    repetationsDiagonallyP2 = 0;
                }
                else if (gameBoard[j + k][i + k] == '2')
                {
                    repetationsDiagonallyP2++;
                    repetationsDiagonallyP1 = 0;
                }
                else
                {
                    break;
                }
            }
            if (repetationsDiagonallyP1 == K)
                return 1;
            if (repetationsDiagonallyP2 == K)
                return 2;
            repetationsDiagonallyP1 = 0;
            repetationsDiagonallyP2 = 0;
        }
    }
    return 0;
}
int GameEndAntiDiagonally(int N, int M, int K, char ActivePlayer, char** gameBoard)
{
    int repetationsAntiDiagonallyP1 = 0;
    int repetationsAntiDiagonallyP2 = 0;
    for (int i = 0; i <= M - K; i++)
    {
        for (int j = 0; j <= N - K; j++)
        {
            for (int k = 0; k < K; k++)
            {
                if (gameBoard[N - 1 - k - j][i + k] == '1')
                {
                    repetationsAntiDiagonallyP1++;
                    repetationsAntiDiagonallyP2 = 0;
                }
                else if (gameBoard[N - 1 - k - j][i + k] == '2')
                {
                    repetationsAntiDiagonallyP2++;
                    repetationsAntiDiagonallyP1 = 0;
                }
                else
                {
                    break;
                }
            }
            if (repetationsAntiDiagonallyP1 == K)
                return 1;
            if (repetationsAntiDiagonallyP2 == K)
                return 2;
            repetationsAntiDiagonallyP1 = 0;
            repetationsAntiDiagonallyP2 = 0;
        }
    }
    return 0;
}

int GameEndVertically(int N, int M, int K, char ActivePlayer, char** gameBoard)
{
    int repetationsVerticallyP1 = 0;
    int repetationsVerticallyP2 = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j <= N - K; j++)
        {
            for (int k = j; k < K + j; k++)
            {
                if (gameBoard[k][i] == '1')
                {
                    repetationsVerticallyP1++;
                    repetationsVerticallyP2 = 0;
                }
                else if (gameBoard[k][i] == '2')
                {
                    repetationsVerticallyP2++;
                    repetationsVerticallyP1 = 0;
                }
                else
                {
                    break;
                }

            }
            if (repetationsVerticallyP1 == K)
                return 1;
            if (repetationsVerticallyP2 == K)
                return 2;
            repetationsVerticallyP1 = 0;
            repetationsVerticallyP2 = 0;
        }
    }
    return 0;
}
bool emptySpace(int N, int M, int K, int ActivePlayer, char** gameBoard) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (gameBoard[i][j] == '0')return true;
        }
    }
    return false;
}
int GameEndHorizontally(int N, int M, int K, char ActivePlayer, char** gameBoard)
{
    int repetationsHorizontalyP1 = 0;
    int repetationsHorizontalyP2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= M - K; j++)
        {
            for (int k = j; k < K + j; k++)
            {
                if (gameBoard[i][k] == '1')
                {
                    repetationsHorizontalyP1++;
                    repetationsHorizontalyP2 = 0;
                }
                else if (gameBoard[i][k] == '2')
                {
                    repetationsHorizontalyP2++;
                    repetationsHorizontalyP1 = 0;
                }
                else
                {
                    break;
                }
            }
            if (repetationsHorizontalyP1 == K)
                return 1;
            if (repetationsHorizontalyP2 == K)
                return 2;
            repetationsHorizontalyP1 = 0;
            repetationsHorizontalyP2 = 0;
        }
    }
    return 0;
}
bool isGameEnd(int N, int M, int K, char ActivePlayer, char** gameBoard)
{
    if (GameEndAntiDiagonally(N, M, K, ActivePlayer, gameBoard))
        return true;
    if (GameEndDiagonally(N, M, K, ActivePlayer, gameBoard))
        return true;
    if (GameEndHorizontally(N, M, K, ActivePlayer, gameBoard))
        return true;
    if (GameEndVertically(N, M, K, ActivePlayer, gameBoard))
        return true;
    return false;
}
void printBoard(int N, int M, char** gameBoard)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}
int max(int a, int b)
{
    return (a < b) ? b : a;
}
int min(int a, int b)
{
    return (b < a) ? b : a;
}
int minMax(int N, int M, int K, char ActivePlayer, int alpha, int beta, bool maximise, char** gameBoard)
{
    int result;
    if (maximise)
    {
        if (isGameEnd(N, M, K, ActivePlayer, gameBoard))
        {
            if (GameEndAntiDiagonally(N, M, K, ActivePlayer, gameBoard) == 1 || GameEndDiagonally(N, M, K, ActivePlayer, gameBoard) == 1 || GameEndHorizontally(N, M, K, ActivePlayer, gameBoard) == 1 || GameEndVertically(N, M, K, ActivePlayer, gameBoard) == 1)
                result = 1;
            if (result == 1)
            {
                result = FIRST_PLAYER_WON;
                return result;
            }
        }
    }
    else
    {
        if (isGameEnd(N, M, K, ActivePlayer, gameBoard))
        {
            if (GameEndAntiDiagonally(N, M, K, ActivePlayer, gameBoard) == 2 || GameEndDiagonally(N, M, K, ActivePlayer, gameBoard) == 2 || GameEndHorizontally(N, M, K, ActivePlayer, gameBoard) == 2 || GameEndVertically(N, M, K, ActivePlayer, gameBoard) == 2)
                result = 2;
            if (result == 2)
            {
                result = SECOND_PLAYER_WON;
                return result;
            }
        }
    }
    if (!emptySpace(N, M, K, ActivePlayer, gameBoard))
    {
        if (isGameEnd)
        {
            if (GameEndAntiDiagonally(N, M, K, ActivePlayer, gameBoard) == 1 || GameEndDiagonally(N, M, K, ActivePlayer, gameBoard) == 1 || GameEndHorizontally(N, M, K, ActivePlayer, gameBoard) == 1 || GameEndVertically(N, M, K, ActivePlayer, gameBoard) == 1)
                return FIRST_PLAYER_WON;
            else if (GameEndAntiDiagonally(N, M, K, ActivePlayer, gameBoard) == 2 || GameEndDiagonally(N, M, K, ActivePlayer, gameBoard) == 2 || GameEndHorizontally(N, M, K, ActivePlayer, gameBoard) == 2 || GameEndVertically(N, M, K, ActivePlayer, gameBoard) == 2)
                return SECOND_PLAYER_WON;
            return DRAW;
        }
    }
    if (maximise)
    {
        int best = -1000;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (gameBoard[j][i] == '0')
                {
                    gameBoard[j][i] = '2';
                    int value = minMax(N, M, K, ActivePlayer, alpha, beta, !maximise, gameBoard);
                    gameBoard[j][i] = '0';
                    best = max(best, value);
                    alpha = max(alpha, best);
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for (int k = 0; k < M; k++)
        {
            for (int l = 0; l < N; l++)
            {
                if (gameBoard[l][k] == '0')
                {
                    gameBoard[l][k] = '1';
                    int value = minMax(N, M, K, ActivePlayer, alpha, beta, !maximise, gameBoard);
                    gameBoard[l][k] = '0';
                    best = min(best, value);
                    beta = min(beta, best);
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return best;
    }
}
int main()
{
    char buffer[100];
    while (cin >> buffer)
    {
        int N, M, K;
        char ActivePlayer;
        cin >> N >> M >> K >> ActivePlayer;
        char** gameBoard = new char* [N];
        for (int i = 0; i < N; i++) {
            gameBoard[i] = new char[M];
        }
        if (strcmp(buffer, "GEN_ALL_POS_MOV") == 0)
        {
            int possibleMoves = 0;
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    cin >> gameBoard[j][k];
                    if (gameBoard[j][k] == '0')
                        possibleMoves++;
                }
            }
            if (possibleMoves != 0 && !(isGameEnd(N, M, K, ActivePlayer, gameBoard)))
            {
                cout << possibleMoves << endl;
                for (int y = 0; y < N; y++)
                {
                    for (int x = 0; x < M; x++)
                    {
                        if (gameBoard[y][x] == '0')
                        {
                            gameBoard[y][x] = ActivePlayer;
                            printBoard(N, M, gameBoard);
                            gameBoard[y][x] = '0';
                        }
                    }
                }
            }
            else
                cout << '0' << endl;

        }
        else if (strcmp(buffer, "GEN_ALL_POS_MOV_CUT_IF_GAME_OVER") == 0)
        {
            bool end = false;
            int possibleMov = 0;
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    cin >> gameBoard[j][k];
                    if (gameBoard[j][k] == '0')
                        possibleMov++;
                }
            }
            if (possibleMov != 0 && !(isGameEnd(N, M, K, ActivePlayer, gameBoard)))
            {
                for (int y = 0; y < N; y++)
                {
                    for (int x = 0; x < M; x++)
                    {
                        if (gameBoard[y][x] == '0')
                        {
                            gameBoard[y][x] = ActivePlayer;


                            if (possibleMov != 0 && isGameEnd(N, M, K, ActivePlayer, gameBoard))
                            {
                                cout << '1' << endl;
                                printBoard(N, M, gameBoard);
                                end = true;
                            }
                            else
                                gameBoard[y][x] = '0';
                        }
                        if (end)
                            break;
                    }
                    if (end)
                        break;
                }
                if (!end)
                {
                    if (possibleMov != 0 && !(isGameEnd(N, M, K, ActivePlayer, gameBoard)))
                    {
                        cout << possibleMov << endl;
                        for (int y = 0; y < N; y++)
                        {
                            for (int x = 0; x < M; x++)
                            {
                                if (gameBoard[y][x] == '0')
                                {
                                    gameBoard[y][x] = ActivePlayer;
                                    printBoard(N, M, gameBoard);
                                    gameBoard[y][x] = '0';
                                }
                            }
                        }
                    }
                }
            }
            else
                cout << '0' << endl;
        }
        else if (strcmp(buffer, "SOLVE_GAME_STATE") == 0)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    cin >> gameBoard[j][k];
                }
            }
            int result;
            bool maximise = true;
            int alpha = -1000;
            int beta = 1000;
            if (ActivePlayer == '1')
                maximise = false;
            result = minMax(N, M, K, ActivePlayer, alpha, beta, maximise, gameBoard);
            if (result == FIRST_PLAYER_WON)
                cout << "FIRST_PLAYER_WINS" << endl;
            else if (result == SECOND_PLAYER_WON)
                printf("SECOND_PLAYER_WINS\n");
            else if (result == DRAW)
                printf("BOTH_PLAYERS_TIE\n");
        }
        for (int l = 0; l < N; l++)
            delete[] gameBoard[l];
        delete[] gameBoard;
    }
    return 0;
}