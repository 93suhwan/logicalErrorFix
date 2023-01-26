// Author: Vinay Khilwani
// Language: C++
 
// @vok8: Codeforces, AtCoder, LeetCode, HackerEarth, TopCoder, Google, FB, CSES, Spoj, GitHub, BinarySearch
// @vok_8: CodeChef, GFG
// @vok8_khilwani: HackerRank
 
// Never Stop Trying.
// Trying to be Better than Myself.
 
// while (true)
// {
//     if (AC)
//     {
//         break;
//     }
//     else if (Contest Over)
//     {
//         Try.
//         Check out Editorial.
//         Understand.
//         Find out your Mistake.
//         Learn the topic (if new).
//         Solve Problems on that topic (if new).
//         Upsolve that problem.
//         break;
//     }
//     else
//     {
//         Try.
//         Use Pen-Paper.
//         Find errors, edge cases, etc.
//         continue;
//     }
// }
 
// Optimizations
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#pragma GCC optimize ("Os")
 
// Libraries
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// Defines
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define sz(a) int (a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long int;
using ld = long double;
const ll mod = (ll) (1e9) + 7LL;
const ll M = 998244353LL;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ld pi = acos(-1);

// Global Variable(s)

// Solver Function(s)
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool z = false;
    for (auto ch : s)
    {
        if (ch == '0')
        {
            z = true;
        }
    }
    if (n == 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                cout << 1 << " " << 2 << " " << i + 1 << " " << i + 1 << "\n";
                return;
            }
        }
        return;
    }
    int s_req = n / 2;
    if (!z)
    {
        cout << 1 << " " << s_req << " " << 2 << " " << s_req + 1 << "\n";
        return;
    }
    for (int i = s_req - 1; i < n - 1; i++)
    {
        if (s[i] == '1' && s[i + 1] == '0')
        {
            cout << 1 << " " << i + 2 << " " << 1 << " " << i + 1 << "\n";
            return;
        }
        if (s[i] == '0' && s[i + 1] == '0')
        {
            cout << 1 << " " << i + 2 << " " << 1 << " " << i + 1 << "\n";
            return;
        }
    }
    for (int i = n - 1 - (s_req - 1); i >= 1; i--)
    {
        if (s[i - 1] == '0' && s[i] == '1')
        {
            cout << i << " " << n << " " << i + 1 << " " << n << "\n";
            return;
        }
        if (s[i - 1] == '0' && s[i] == '0')
        {
            cout << i << " " << n << " " << i + 1 << " " << n << "\n";
            return;
        }
    }
}
 
// Main Function
int main()
{
    fast
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
} 