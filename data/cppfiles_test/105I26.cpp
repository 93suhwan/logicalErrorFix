#include<iostream>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<cstdio>
#include<bitset>
#include<chrono>
#include<random>
#include<ext/rope>
/* ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/

#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e9;
int n, a[maxN], b[maxN], m[maxN];
int mark[maxN];
int res = 0;
inline void FastInput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
void ReadInput()
{
    res = 0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i] >> m[i];
        mark[a[i] + b[i] - m[i]] = oo;
    }
    for(int i=1; i<=n; i++)
    {
        if(mark[a[i] + b[i] - m[i]] == oo) res++;
        mark[a[i] + b[i] - m[i]] = min(mark[a[i] + b[i] - m[i]], a[i]);
    }
}
void Solve()
{
    cout << res << '\n';
    for(int i=1; i<=n; i++)
    {
        int t = m[i] - (a[i] - mark[a[i] + b[i] - m[i]]);
        int t1 = a[i] - mark[a[i] + b[i] - m[i]];
        if(t > b[i])
        {
            t1 -= (b[i] - t);
            t = b[i];
        }
        cout << t1 << " " << t << '\n';
    }
}
int main()
{
    FastInput();
    int test;
    cin >> test;
    while(test--)
    {
        ReadInput();
        Solve();
    }
}
