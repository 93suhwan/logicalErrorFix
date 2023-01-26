#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int pos, val, curr = 0;

    bool operator<(const Node &p)
    {
        if (p.val == val)
            return pos > p.pos;
        return val < p.val;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t, n, m;
    cin >> t;
    // cout << "ij" << endl;

    Node arr[100005];

    while (t--)
    {
        cin >> n >> m;
        int size = n * m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i * m + j].val;
                arr[i * m + j].pos = i * m + j;
            }
        }

        sort(arr, arr + size);

        long long res = 0, tmp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = j + 1; k < m; k++)
                {
                    if (arr[i * m + j].pos < arr[i * m + k].pos)
                    {
                        res++;
                    }
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}