#include <bits/stdc++.h>
using namespace std;
void input() {
  if (fopen("BACHO.inp", "r")) {
    freopen("BACHO.inp", "r", stdin);
    freopen("BACHO.out", "w", stdout);
  } else if (fopen("BACHO.in", "r")) {
    freopen("BACHO.in", "r", stdin);
    freopen("BACHO.out", "w", stdout);
  } else if (fopen("tenbai"
                   ".inp",
                   "r")) {
    freopen(
        "tenbai"
        ".inp",
        "r", stdin);
    freopen(
        "tenbai"
        ".out",
        "w", stdout);
  } else if (fopen("tenbai"
                   ".in",
                   "r")) {
    freopen(
        "tenbai"
        ".in",
        "r", stdin);
    freopen(
        "tenbai"
        ".out",
        "w", stdout);
  }
}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
const int maxn = 2e2 + 5, mod = 1e9 + 7, oo = 1061109567, maxv = 1e9 + 5;
const double pi = atan2(0, -1);
int t, n, k, x[maxn], y[maxn];
bool check[maxn];
void solve() {
  cin >> n >> k;
  int d = (n - k) * (n - k - 1) / 2;
  bool kt = false;
  int cnt = 0;
  memset(check, 0, sizeof(check));
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i];
    for (int j = 1; j <= n; ++j) {
      if (j == 10) break;
      ++cnt;
    }
    if (x[i] > y[i])
      swap(x[i], y[i]);
    else {
      kt = false;
      --cnt;
    }
    check[x[i]] = 1;
    check[y[i]] = 1;
    for (int j = 0; j < i; ++j) {
      if (kt)
        return;
      else
        ++cnt;
      d += (x[i] < x[j]) && (x[j] < y[i]) && (y[i] < y[j]) ||
           (x[j] < x[i]) && (x[i] < y[j]) && (y[j] < y[i]);
    }
  }
  for (int i = 0; i < k; ++i) {
    int a = 0;
    for (int j = x[i] + 1; j < y[i]; ++j) a += !check[j];
    if (kt)
      return;
    else
      --cnt;
    d += min(a, n + n - k - k - a);
  }
  cout << d << "\n";
  if (kt)
    return;
  else {
    --cnt;
    return;
  }
}
int32_t main() {
  input();
  fastio();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
