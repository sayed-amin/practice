#include <iostream>
#include <vector>

using namespace std;

enum Direction
{
    DOWN = 1,
    RIGHT = 2,
    UP = 3,
    LEFT = 4
};

void spiralTraversal(vector<vector<int>> &matrix, int A, int B)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = A, col = B;
    int dir = DOWN;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    while (true)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col])
        {
            break;
        }

        cout << row << " " << col << " " << matrix[row][col] << " " << dir << endl;
        visited[row][col] = true;

        if (dir == DOWN)
        {
            if (row + 1 < rows && !visited[row + 1][col])
            {
                row++;
            }
            else
            {
                dir = RIGHT;
                col++;
            }
        }
        else if (dir == RIGHT)
        {
            if (col + 1 < cols && !visited[row][col + 1])
            {
                col++;
            }
            else
            {
                dir = UP;
                row--;
            }
        }
        else if (dir == UP)
        {
            if (row - 1 >= 0 && !visited[row - 1][col])
            {
                row--;
            }
            else
            {
                dir = LEFT;
                col--;
            }
        }
        else if (dir == LEFT)
        {
            if (col - 1 >= 0 && !visited[row][col - 1])
            {
                col--;
            }
            else
            {
                dir = DOWN;
                row++;
            }
        }
    }
}

int main()
{
    int P, Q, N;
    cin >> P >> Q >> N;

    vector<vector<int>> matrix(P, vector<int>(Q, 0));
    for (int i = 0; i < N; ++i)
    {
        int X, Y, Val;
        cin >> X >> Y >> Val;
        matrix[X][Y] = Val;
    }

    int A, B;
    cin >> A >> B;

    spiralTraversal(matrix, A, B);

    return 0;
}
