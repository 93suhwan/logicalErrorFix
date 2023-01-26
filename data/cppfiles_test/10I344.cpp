#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define endl '\n';
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define len(x) int(x.size())
#define get_files ifstream cin("input.txt");ofstream cout("output.txt");

const ll BIG_INF = 2e18;
const ll INF = 2e9;
const int MAXN = 1e5 + 7;
const int alphabet = 26;
const ll mod = 1e9 + 7;//998244353
const int LOG = 30;

mt19937 engine;

int main()
{
    fast;
    engine.seed(time(0));
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        vector<vector<int> > pos(n);
        vector<int> sz(n,0);
        for(int i = 0;i < n; ++i)
        {
            cin >> a[i];
            a[i]--;
            pos[a[i]].push_back(i);
            sz[a[i]]++;
        }
        sort(sz.begin(),sz.end());
        int need_sz = -1,mx = -1;
        for(int i = 1;i <= n; ++i)
        {
            int kol = n - (lower_bound(sz.begin(),sz.end(),i) - sz.begin());
            if(kol * i >= mx)
            {
                need_sz = i;
                mx = kol * i;
            }
        }
        vector<int> ans(n,0);
        for(int i = 0;i < n; ++i)
        {
            if(int(pos[i].size()) >= need_sz) for(int idx = 0;idx < need_sz; ++idx) ans[pos[i][idx]] = idx + 1;
        }
        for(int x : ans) cout << x << ' ';
        cout << endl;
    }
    return 0;
}




















