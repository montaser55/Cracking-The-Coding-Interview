#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void nullify(vector<vector<int>> &matrix, int row)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        matrix[row][i] = 0;
    }
}

void nullifyCol(vector<vector<int>> &matrix, int col)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        matrix[i][col] = 0;
    }
}
void zeroMatrix(vector<vector<int>> &matrix)
{
    bool firstRowZero = false;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    for (int i = 1; i < n; i++)
    {
        bool nullifyThisRow = false;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                nullifyThisRow = true;
            }
        }
        if (nullifyThisRow)
            nullify(matrix, i);
    }
    //printMatrix(matrix);

    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            nullifyCol(matrix, j);
        }
    }
    //printMatrix(matrix);

    if (firstRowZero)
        nullify(matrix, 0);
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 3}, {0, 6, 7}, {2, 3, 1}};
    printMatrix(matrix);
    zeroMatrix(matrix);
    printMatrix(matrix);
}