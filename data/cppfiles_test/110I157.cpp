#include <bits/stdc++.h>
using namespace std;

#define int int long long
#define fr(i, n) for (int i = 0; i < n; i++)
#define fr1(i, n) for (int i = 1; i <= n; i++)
#define S second
#define F first
#define pb(n) push_back(n)
#define endl "\n"
#define pr pair<int, int>
#define so(a) sort(a.begin(), a.end())
#define intv vector<int>
int mod = 1e9 + 7;
// vector<int> v[1000001], tr[1000001];
// int level[1000001] = {0};
// int in[1000001] = {0};
// int out[1000001] = {0};
// int low[1000001] = {0};
// int vis[1000001] = {0};
// int visit[1001][1001] = {0};
// int dis[1001][1001] = {0};
// int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
// int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int timer = 0, n, m, t, k, eq = 0;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v[n + 1];
        int in[n + 1] = {0};
        fr1(i, n)
        {
            cin >> k;
            fr(j, k)
            {
                int x;
                cin >> x;
                v[x].pb(i);
                in[i]++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        queue<int> ans;
        fr1(i, n)
        {
            if (in[i] == 0)
            {
                pq.push(i);
            }
        }
        while (pq.size())
        {
            int ele = pq.top();
            pq.pop();
            ans.push(ele);
            for (auto child : v[ele])
            {
                in[child]--;
                if (in[child] == 0)
                {
                    pq.push(child);
                }
            }
        }
        if (ans.size() != n)
        {
            cout << -1 << endl;
        }
        else
        {
            int cnt = 1;
            int ele = ans.front();
            ans.pop();
            fr(i, n - 1)
            {
                int temp = ans.front();
                ans.pop();
                if (temp < ele)
                {
                    cnt++;
                    ele = temp;
                }
            }
            cout << cnt << endl;
        }
    }
}