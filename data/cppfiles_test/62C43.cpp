#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto &x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cout << endl; }
void show() { cout << endl; }
void pret() {
  cout << endl;
  exit(0);
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
template <typename Head, typename... Tail>
void show(Head H, Tail... T) {
  cout << H << " ";
  show(T...);
}
template <typename Head, typename... Tail>
void pret(Head H, Tail... T) {
  cout << H << " ";
  pret(T...);
}
const long long MOD = 1e9 + 7;
const long long maxn = 1000 + 10;
long long n, m, q;
bool a[maxn][maxn];
long long dp[maxn][maxn][2];
long long find(long long x, long long y, long long t) {
  long long &ans = dp[x][y][t];
  if (ans != -1) return ans;
  ans = 0;
  if (t == 0) {
    if (x + 1 > n) {
      ans = 0;
    } else
      ans = 1 + find(x + 1, y, 1 - t);
  } else {
    if (y + 1 > m)
      ans = 0;
    else
      ans = 1 + find(x, y + 1, 1 - t);
  }
  return ans;
}
long long leftt(long long x, long long y) {
  long long i = x, j = y;
  bool flag = 0;
  long long curr = 0, temp = 0;
  while (i >= 1 and j >= 1) {
    if (a[i][j]) break;
    curr++;
    if (!flag)
      j--;
    else
      i--;
    flag = 1 - flag;
  }
  flag = 0;
  i = x, j = y;
  while (i <= n and j <= m) {
    if (a[i][j]) break;
    temp++;
    if (!flag)
      i++;
    else
      j++;
    flag = 1 - flag;
  }
  return curr * temp;
}
long long upp(long long x, long long y) {
  long long i = x, j = y;
  bool flag = 0;
  long long curr = 0, temp = 0;
  while (i >= 1 and j >= 1) {
    if (a[i][j]) break;
    curr++;
    if (!flag)
      i--;
    else
      j--;
    flag = 1 - flag;
  }
  flag = 0;
  i = x, j = y;
  while (i <= n and j <= m) {
    if (a[i][j]) break;
    temp++;
    if (!flag)
      j++;
    else
      i++;
    flag = 1 - flag;
  }
  return curr * temp;
}
int32_t main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n >> m >> q;
  long long ans = 0;
  for (long long i = 1; i <= (long long)n; i++) {
    for (long long j = 1; j <= (long long)m; j++) {
      dp[i][j][0] = -1;
      dp[i][j][1] = -1;
    }
  }
  for (long long i = 1; i <= (long long)n; i++) {
    for (long long j = 1; j <= (long long)m; j++) {
      ans += find(i, j, 0ll);
      ans += find(i, j, 1ll);
      ans += 1;
    }
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    long long flag = a[x][y];
    a[x][y] = 0;
    long long curr = leftt(x, y) + upp(x, y) - 1;
    if (flag) {
      ans += curr;
    } else {
      ans -= curr;
    }
    a[x][y] = 1 - flag;
    show(ans);
  }
  return 0;
}
