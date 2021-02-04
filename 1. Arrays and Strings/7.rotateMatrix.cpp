#include <bits/stdc++.h>
using namespace std;

void transposeMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverseRow(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            swap(matrix[i][j], matrix[i][m - j - 1]);
        }
    }
}

void rotateMatrix1(vector<vector<int>> &matrix)
{
    transposeMatrix(matrix);
    reverseRow(matrix);
}

void rotateMatrix2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < m - i - 1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[m - j - 1][i];
            matrix[m - j - 1][i] = matrix[n - i - 1][m - j - 1];
            matrix[n - i - 1][m - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

void printmatrix(vector<vector<int>> matrix)
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

int main()
{
    vector<vector<int>> matrix = {{9, 5, 7}, {2, 6, 8}, {0, 3, 1}};
    printmatrix(matrix);
    rotateMatrix1(matrix);
    printmatrix(matrix);

    matrix = {{9, 5, 7}, {2, 6, 8}, {0, 3, 1}};
    rotateMatrix2(matrix);
    printmatrix(matrix);
}
