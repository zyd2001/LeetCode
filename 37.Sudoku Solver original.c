// original from Huawei's interview problem

#include <stdlib.h>

#define getI(i, j) (i / 3 * 3 + j / 3)

int taken_h[9][9];
int taken_v[9][9];
int taken_q[9][9];
int board[9][9];
int done = 0;

int inc(int * i, int * j)
{
    (*j)++;
    if (*j == 9)
    {
        *j = 0;
        (*i)++;
        if (*i == 9)
            return 0;
    }
    return 1;
}

void try(int i, int j)
{
    while (board[i][j] != 0)
    {
        if (!inc(&i, &j))
        {
            done = 1;
            return;
        }
    }
    int tested = -1;
    for (int k = 0; k < 9; k++)
    {
        if (done)
            return;
        if (tested != -1)
        {
            taken_h[i][tested] = 0;
            taken_v[j][tested] = 0;
            taken_q[getI(i, j)][tested] = 0;
            tested = -1;
        }
        if (!(taken_h[i][k] || taken_v[j][k] || taken_q[getI(i, j)][k]))
        {
            tested = k;
            board[i][j] = k + 1;
            taken_h[i][k] = 1;
            taken_v[j][k] = 1;
            taken_q[getI(i, j)][k] = 1;
            int a = i, b = j;
            if (inc(&a, &b))
                try(a, b);
            else
                done = 1;
        }
    }
    if (tested != -1)
    {
        taken_h[i][tested] = 0;
        taken_v[j][tested] = 0;
        taken_q[getI(i, j)][tested] = 0;
    }
    if (done)
        return;
    board[i][j] = 0;
}

int main()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            taken_q[i][j] = 0;
            taken_h[i][j] = 0;
            taken_v[i][j] = 0;
        }
    for (int i = 0; i < 8; i++)
        scanf("{%d,%d,%d,%d,%d,%d,%d,%d,%d}\n", &board[i][0], &board[i][1], &board[i][2], &board[i][3], &board[i][4],
             &board[i][5], &board[i][6], &board[i][7], &board[i][8]);
    scanf("{%d,%d,%d,%d,%d,%d,%d,%d,%d}", &board[8][0], &board[8][1], &board[8][2], &board[8][3], &board[8][4],
        &board[8][5], &board[8][6], &board[8][7], &board[8][8]);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != 0)
            {
                taken_h[i][board[i][j] - 1] = 1;
                taken_v[j][board[i][j] - 1] = 1;
                taken_q[getI(i, j)][board[i][j] - 1] = 1;
            }
        }
    try(0, 0);
    for (int i = 0; i < 9; i++)
        printf("{%d,%d,%d,%d,%d,%d,%d,%d,%d}\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4],
             board[i][5], board[i][6], board[i][7], board[i][8]);
}