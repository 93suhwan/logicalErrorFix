#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

ll powmod(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const ll MOD = 1e9 + 7;
const int N = 500, M = 500;
int arr[N][M];
int pre[N][M];
int n, m;

// (x,y) => (row, col)

int calc_prefix_cost(int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

int calc_cost(int x1, int y1, int x2, int y2)  {
    int c1 = (y2 - y1 - 1) - calc_prefix_cost(x1, y1 + 1, x1, y2 - 1);
    int c4 = (y2 - y1 - 1) - calc_prefix_cost(x2, y1 + 1, x2, y2 - 1);
    int c2 = (x2 - x1 - 1) - calc_prefix_cost(x1 + 1, y1, x2 - 1, y1);
    int c3 = (x2 - x1 - 1) - calc_prefix_cost(x1 + 1, y2, x2 - 1, y2);
    int c5 = calc_prefix_cost(x1 + 1, y1 + 1 , x2 - 1, y2 - 1);
    int cost = c1 + c2 + c3 + c4 + c5;
    return cost;
}

void solve() {
    cin >> n >> m;
    memset(arr, 0, sizeof(arr));
    memset(pre, 0, sizeof(pre));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i + 1][j + 1] = s[j] - '0';
        }
    }

    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = arr[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    int ans = 1e9;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 4; j <= n; j++) {
            set<int> st;

            int left_col = 1, right_col = 4;
            while (right_col <= m) {
                if (right_col - left_col + 1 <= 3) {
                    right_col++;
                } else {
                    int c = calc_cost(i, left_col, j, right_col);
                    ans = min(ans, c);
                    int sm = *st.begin();
                    if (c < sm) {
                        right_col++;
                    } else {
                        left_col++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}
