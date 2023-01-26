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

// ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//

#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int maxN = 1e6 + 1;
const int mod = 1e9 + 7;
const ll oo = 1e18;
string s, t;
inline void FastInput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
void ReadInput()
{
    cin >> s >> t;
}
void Solve()
{
    int n = s.size();
    int m = t.size();
    int cnt = 0;
    if(n < m)
    {
        cout << "NO" << '\n';
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(s[i] == t[cnt]) cnt++;
        else if(cnt > 0) i++;
        if(cnt == m) break;
    }
    int cnt1 = 0, l = -1;
    for(int i=0; i<n; i++)
    {
        if(s[i] == t[cnt1])
        {
            cnt1++;
            if(l == -1)
            l = i;
        }
        else
        {
            if(cnt > 0)
            {
                if(i == l + 1)
                {
                    i--;
                    cnt1--;
                }
                else i++;
            }
        }
        if(cnt1 == m) break;
    }
    cout << ((cnt == m || cnt1 == m) ? "YES" : "NO") << '\n';
}
int main()
{
    freopen("x.inp", "r", stdin);
    FastInput();
    int test;
    cin >> test;
    while(test--)
    {
        ReadInput();
        Solve();
    }
}

