// wont pass test case since use global variables

#define getI(i, j) (i / 3 * 3 + j / 3)

int taken_h[9][9];
int taken_v[9][9];
int taken_q[9][9];
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

void try(int i, int j, char ** board)
{
    while (board[i][j] != '.')
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
            board[i][j] = k + 1 + 48;
            taken_h[i][k] = 1;
            taken_v[j][k] = 1;
            taken_q[getI(i, j)][k] = 1;
            int a = i, b = j;
            if (inc(&a, &b))
                try(a, b, board);
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
    board[i][j] = '.';
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                taken_h[i][board[i][j] - 48 - 1] = 1;
                taken_v[j][board[i][j] - 48 - 1] = 1;
                taken_q[getI(i, j)][board[i][j] - 48 - 1] = 1;
            }
        }
    try(0, 0, board);
}

