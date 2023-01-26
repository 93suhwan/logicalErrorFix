#include <bits/stdc++.h>

#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(x, y) for(auto& x : y)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple

#define pw(x) (1LL << (x))
#define sqr(x) (1LL * (x) * (x))
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T>
using ve = vector<T>;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo find_by_order
#define ook order_of_key

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

template<typename T>
bool umn(T& a, T b) { return a > b ? a = b, 1 : 0; }
template<typename T>
bool umx(T& a, T b) { return a < b ? a = b, 1 : 0; }

const int N = 8e5 + 5;

int n;
int cnt_[20][N];
int pos_[20][N];
int last[20];
int mn[20];
string s[20];

int dp[pw(20)];

int& cnt(int i, int bal) {
    return cnt_[i][bal + 400001];
}

int& pos(int i, int bal) {
    return pos_[i][bal + 400001];
}

int main() {
#ifndef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    cin >> n;

    fr(i, 0, n - 1) {
        cin >> s[i];
        int bal = 0;
        mn[i] = 1;
        fr(j, 0, sz(s[i]) - 1) {
            if(s[i][j] == '(') bal++;
            else bal--;
            
            if(cnt(i, bal) == 0) {
                pos(i, bal) = cnt(i, bal + 1);
            }
            cnt(i, bal)++;
            umn(mn[i], bal);
        }
        last[i] = bal;
    }

    int best = 0;
    fr(mask, 0, pw(n) - 1) {
        int bal = 0;
        fr(i, 0, n - 1) {
            if(mask & pw(i)) {
                bal += last[i];
            }
        }

        fr(i, 0, n - 1) {
            if(!(mask & pw(i))) {
                if(mn[i] + bal >= 0) {
                    umx(dp[mask | pw(i)], dp[mask] + cnt(i, -bal));
                } else {
                    umx(best, dp[mask] + pos(i, -bal - 1));
                }
            }
        }
    }

    fr(mask, 0, pw(n) - 1) {
        umx(best, dp[mask]);
    }

    cout << best << "\n";

    return 0;
}