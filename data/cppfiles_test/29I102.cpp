#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <bitset>
using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define int long long
#define float long double
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define mod 1000000007
#define inf INT_MAX
#define ninf INT_MIN
#define sz(x) ((int)(x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define vrep(x, v) for (auto x : v)
#define all(n) n.begin(), n.end()
#define prec(n, i) cout << fixed << setprecision(n) << i << '\n';
#define print(array) vrep(i, array) { cout << i << ' '; }cout << endl;
#define printMat(memo) vrep(i, memo) {vrep(j, i) cout << j << ' ';cout << endl;}

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct pair_hash
{
    inline std::size_t operator()(const std::pair<int, int> &v) const
    {
        return v.first * 31 + v.second;
    }
};

int pow(int a, int p, int m = mod)
{
    int res = 1;
    while (p > 0)
    {
        if (p & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    c_p_c();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        rep(i, n)cin >> v[i];
        int sum = 0, oneCnt = 0, zeroCnt = 0;
        vrep(i, v) {
            sum += i;
            if (i == 1)oneCnt++;
            if (i == 0)zeroCnt++;
        }
        // cout << oneCnt << ' ' << (sum == 0) << ' ' << zeroCnt << endl;
        cout << (1 << oneCnt) - 1 + (sum == 0) + (1 << zeroCnt) - 1 << endl;
    }
    return 0;
}