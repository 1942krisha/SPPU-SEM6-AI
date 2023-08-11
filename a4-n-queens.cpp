#include <bits/stdc++.h>
using namespace std;

class nqueens
{
    int n;
    vector<vector<int>> board, ans;
    vector<bool> ud, ld, hr;

public:
    nqueens(int n)
    {
        this->n = n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            board.push_back(v);
        }
        ud = vector<bool>(2*n - 1, false);
        ld = vector<bool>(2*n - 1, false);
        hr = vector<bool>(n, false);
    }

    void solve(int c)
    {
        if(c >= n)
        {
            ans = board;
            display();
            cout << endl;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            int x = n - 1 + c - i;
            if(board[i][c] == 0 && !ud[x] && !ld[i+c] && !hr[i])
            {
                ud[x] = true;
                ld[i + c] = true;
                hr[i] = true;
                board[i][c] = 1;
                solve(c + 1);
                ud[x] = false;
                ld[i + c] = false;
                hr[i] = false;
                board[i][c] = 0;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    if(n > 3)
    {
        nqueens nq(n);
        nq.solve(0);
    }
    else
        cout << "No solution possible";

    return 0;
}