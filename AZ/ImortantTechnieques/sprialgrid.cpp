#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateSpiral(int n) {
    vector<vector<int>> grid(n, vector<int>(n, 0));
    int num = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Move left to right
        for (int i = left; i <= right; ++i)
            grid[top][i] = num++;
        top++;

        // Move top to bottom
        for (int i = top; i <= bottom; ++i)
            grid[i][right] = num++;
        right--;

        // Move right to left
        for (int i = right; i >= left; --i)
            grid[bottom][i] = num++;
        bottom--;

        // Move bottom to top
        for (int i = bottom; i >= top; --i)
            grid[i][left] = num++;
        left++;
    }

    return grid;
}

int main() {
    int n = 4; // Change n as needed
    vector<vector<int>> spiral = generateSpiral(n);

    for (const auto& row : spiral) {
        for (int val : row)
            cout << val << "\t";
        cout << endl;
    }

    return 0;
}
