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
pair<int, int> ans[maxN];
struct TDish
{
    int total, a, idx;
} dish[maxN];
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
        dish[i] = {a[i] + b[i] - m[i], a[i], i};
    }
}
void Solve()
{
    sort(dish + 1, dish + n + 1, [](TDish p, TDish q)
    {
        return (p.total < q.total || (p.total == q.total && p.a < q.a));
    });
    dish[0].total = -oo;
    for(int i=1; i<=n; i++)
    {
        //cout << dish[i].total << " ";
        int id = dish[i].idx;
        int id1 = dish[i - 1].idx;
        if(dish[i].total > dish[i - 1].total)
        {
            res++;
            if(b[id] >= m[id])
            {
                b[id] -= m[id];
                ans[id] = {0, m[id]};
            }
            else
            {
                ans[id] = {m[id] - b[id], b[id]};
                a[id] -= m[id] - b[id];
                b[id] = 0;
            }
            continue;
        }
        if(a[id] - m[id] <= a[id1])
        {
            int t = a[id] - a[id1];
            ans[id] = {t, m[id] - t};
            b[id] -= (m[id] - t);
            a[id] -= t;
        }
        else res++;
    }
    cout << res << '\n';
    for(int i=1; i<=n; i++) cout << ans[i].fi << " " << ans[i].se << '\n';
}
int main()
{
   // freopen("x.inp", "r", stdin);
    FastInput();
    int test;
    cin >> test;
    while(test--)
    {
        ReadInput();
        Solve();
    }
}
