#include <iostream>
int chessbox[8][8] = {0};

bool secure(int x, int y)
{
    if (chessbox[x][y] == 0)
        return true;
    else
        return false;
}
void lock(int m, int n, int val)
{
    for (int i = n; i < 8; i++)
    { // lock horizontal boxes
        if (chessbox[m][i] == 0)
        {
            chessbox[m][i] = val;
        }
    }
    int p = m;
    int q = n;
    while (true)
    { // lock diagonal boxes above the taken queen
        if (p == 0 || q == 7)
            break;
        p--;
        q++;
        if (chessbox[p][q] == 0)
        {
            chessbox[p][q] = val;
        }
    }
    while (true)
    { // lock diagonal boxes below the taken queen
        if (m == 7 || n == 7)
            break;
        m++;
        n++;
        if (chessbox[m][n] == 0)
        {
            chessbox[m][n] = val;
        }
    }
}
void unlock(int z)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessbox[i][j] == z)
                chessbox[i][j] = 0;
        }
    }
}
void solve(int &solution)
{
    for (int a = 0; a < 8; a++)
    {
        lock(a, 0, 1);
        for (int b = 0; b < 8; b++)
        {
            if (!secure(b, 1))
                continue;
            lock(b, 1, 2);
            for (int c = 0; c < 8; c++)
            {
                if (!secure(c, 2))
                    continue;
                lock(c, 2, 3);
                for (int d = 0; d < 8; d++)
                {
                    if (!secure(d, 3))
                        continue;
                    lock(d, 3, 4);
                    for (int e = 0; e < 8; e++)
                    {
                        if (!secure(e, 4))
                            continue;
                        lock(e, 4, 5);
                        for (int f = 0; f < 8; f++)
                        {
                            if (!secure(f, 5))
                                continue;
                            lock(f, 5, 6);
                            for (int g = 0; g < 8; g++)
                            {
                                if (!secure(g, 6))
                                    continue;
                                lock(g, 6, 7);
                                for (int h = 0; h < 8; h++)
                                {
                                    if (!secure(h, 7))
                                        continue;
                                    solution++;
                                    std::cout << "A = " << a << "\tB = " << b << "\tC = " << c << "\tD = " << d << "\tE = " << e << "\tF = " << f << "\tG = " << g << "\tH = " << h << std::endl;
                                }
                                unlock(7);
                            }
                            unlock(6);
                        }
                        unlock(5);
                    }
                    unlock(4);
                }
                unlock(3);
            }
            unlock(2);
        }
        unlock(1);
    }
}
int main()
{
    int solutionCount = 0;
    solve(solutionCount);
    std::cout << solutionCount << " Solutions";
}
