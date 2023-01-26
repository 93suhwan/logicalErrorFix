//木の葉舞う所に，火は燃ゆる。
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <bitset>
#include <ext/rope>
#include <unordered_set>
#include <unordered_map>
#define int long long
#define inf 0x3f3f3f3f
#define debug printf("Hello World\n")
#define ios ios::sync_with_stdio(false)
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int mod1 = 1e9 + 7, mod2 = 998244353;
const double PI = 3.1415926535898, Ee = 2.718281828459;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
inline int read()
{
    int x = 0, f = 1;char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
const int N = 2000 + 10, M = 1e6 + 10;

int vis[N];

void solve()
{
    int n, k, x; cin>>n>>k>>x;
    for(int i = 0;i <= n;i ++) vis[i] = 0;
    string s, t; cin>>s;

    for(int i = 0;i < s.size();i ++)
    {
        t += s[i];
        if(s[i] == '*')
        {
            int j = i;
            while(j < s.size() && s[j] == '*') j ++;
            vis[(int)t.size() - 1] = (j - i) * k;
            i = j - 1;
        }
    }

    string ans;
    int sum = 1;
    for(int i = (int)t.size() - 1;i >= 0;i --)
    {
        if(t[i] == 'a') continue;

        if(vis[i] >= (x + sum - 1) / sum - 1)
        {
            for(int j = 0;j < i;j ++) if(t[j] == 'a') ans += t[j];
            for(int j = i;j < t.size();j ++)
            {
                if(t[j] == 'a') ans += t[j];
                else
                {
                    if(j != i) sum /= vis[j] + 1;
//                    cout<<x<<" "<<sum<<endl;
                    int tot = (x + sum - 1) / sum - 1;
                    x -= tot * sum;
                    for(int tt = 1;tt <= tot;tt ++) ans += 'b';
                }
            }
            break;
        }
        else sum *= vis[i] + 1;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios;
    int t = 1;  cin>>t;
    while(t --) solve();
    return 0;
}