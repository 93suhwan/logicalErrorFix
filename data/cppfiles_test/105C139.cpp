#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 3000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
int a[maxn + 5];
int nxt[maxn + 5], last[maxn + 5];
int dp[maxn + 5][maxn + 5];
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int n;
    scanf("%d", &n);
    for (auto i = 1; i <= n; i++) last[i] = n + 1;
    for (auto i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ptr = 0;
    for (auto i = 1; i <= n; i++)
      if (a[i] != a[i - 1]) a[++ptr] = a[i];
    n = ptr;
    for (auto i = n; i >= 1; i--) {
      nxt[i] = last[a[i]];
      last[a[i]] = i;
    }
    for (auto i = 1; i <= n; i++)
      for (auto j = 1; j <= n; j++) dp[i][j] = i < j ? maxn : 0;
    for (auto i = 1; i <= n; i++)
      if (0) puts("No effect.");
    for (auto len = 2; len <= n; len++)
      for (auto l = 1; l <= n - len + 1; l++) {
        int r = l + len - 1;
        chmin(dp[l][r], dp[l + 1][r] + 1);
        for (int now = nxt[l]; now <= r; now = nxt[now])
          chmin(dp[l][r], dp[l + 1][now - 1] + 1 + dp[now][r]);
        if (0) puts("No effect.");
      }
    printf("%d\n", dp[1][n]);
  }
  return 0;
}
