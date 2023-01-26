#include<bits/stdc++.h>
#define fi first
#define se second
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void IO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(5));
    for(auto &i : v)
    {
        for(auto &j : i) cin >> j;
    }
    vector<int> mth(n, 0);
    for(int i = 0; i < 5; i++)
    {
        // cout << i << "\n";
        map<int, int> mp;
        for(int j = 0; j < n; j++)
        {
            mp[v[j][i]] = j;
        }
        int sm = n - 1;
        for(auto &i : mp)
        {
            mth[i.se] += sm;
            sm--;
        }
        // for(auto &i : mth) cout << i << ' '; cout << '\n';
    }
    int mx = -1;
    int mxind = -1;
    for(int i = 0; i < n; i++)
    {
        if(mth[i] > mx)
        {
            mx = mth[i];
            mxind = i;
        }
    }
    vector<int> chk(n, 0);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j == mxind) continue;
            if(v[mxind][i] < v[j][i]) chk[j]++;
        }
    }
    bool chkf = true;
    for(int i = 0; i < n; i++)
    {
        if(i == mxind) continue;
        if(chk[i] < 3)
        {
            chkf = false;
            break;
        }
    }
    if(chkf)
    {
        cout << mxind + 1 << '\n';
    }
    else
    {
        cout << "-1\n";
    }
}

int main()
{
    IO("");
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}