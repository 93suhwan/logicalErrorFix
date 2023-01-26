#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define x first
#define y second

using namespace __gnu_pbds;
using namespace std;

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;

const int N = 100 + 10;
const int M = 1000010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

char  ans[N][N];


int cnt[N][30];

int n;


void solve ()
{
    string str; cin >> str;

    int cnt[10] = {0};
    for (int i = 0; i < str.size(); i ++) 
    {
        cnt[str[i] - 'a'] ++;

    }

    if (cnt[1] != cnt[0] + cnt[2]) cout << "NO\n";
    else cout << "YES\n";

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(7);

    int T; cin >> T;
    for (int o = 1; o <= T; o ++)
    {
        solve ();
    }
    return 0;
}