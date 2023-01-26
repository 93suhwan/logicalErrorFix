#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
//const double eps = 1e-7;
ll lcm(ll a, ll b) { return (b / __gcd(a, b)) * a; }
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};


void solve()
{

    string s, t;
    cin >> s >>t;
    string tmp = s;

    sort(s.begin(),s.end());

//    if (!is_sorted(t.begin(),t.end()));
//    {
//        cout << s;
//        return;
//    }
    if (t=="abc" and s[0] == 'a')  // print a insted of b ..
    {
        for (auto ch : s)
        {
            if (ch !='b' )cout << ch;

        }
        for (auto ch : s)
        {
            if (ch == 'b')cout << ch;

        }

    }
    else
        cout << s;



}
int main()
{
    fast;
    //   freopen("cases.in", "r", stdin);
    int test;
    cin >>test;
    while (test--)
    {
        solve();
        cout << "\n";
    }

}