#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &f) {
  f = 0;
  T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fu = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + 48);
  else
    print(x / 10), putchar(x % 10 + 48);
}
template <typename T>
void print(T x, char t) {
  print(x);
  putchar(t);
}
const int N = 55, INF = 2e9;
mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
vector<pair<int, int> > vec[505];
int a[N][N], d[N], res[N], f[N], cnt[N];
int n, k, ans, st;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int solve() {
  memset(cnt, 0, sizeof(cnt));
  int ans = 0;
  for (int i = 0; i <= 500; i++) vec[i].clear();
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int val = a[i][j] + res[i] + res[j] + 200;
      vec[val].push_back(make_pair(i, j));
    }
  }
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 0; i <= 500; i++) {
    for (int j = 0; j < (int)vec[i].size(); j++) {
      int x = find(vec[i][j].first), y = find(vec[i][j].second);
      if (x != y) {
        f[x] = y;
        ++cnt[vec[i][j].first];
        ++cnt[vec[i][j].second];
        ans += i - res[vec[i][j].first] - res[vec[i][j].second] - 200;
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    if (cnt[i] > d[i]) {
      ans = INF;
    }
  }
  return ans;
}
void SA(double T, double endT, double coef) {
  for (int i = 1; i <= k; i++) res[i] = 100;
  int now = solve();
  ans = min(ans, now);
  while (T > endT) {
    if (clock() - st > 5.9 * CLOCKS_PER_SEC) {
      print(ans, '\n');
      exit(0);
    }
    int x = rng() % k + 1,
        det = (T >= 1 ? rng() % 15 - rng() % 15 : rng() % 4 - rng() % 4);
    while (res[x] + det < -100 || res[x] + det > 100)
      det = (T >= 1 ? rng() % 15 - rng() % 15 : rng() % 4 - rng() % 4);
    res[x] += det;
    int go = solve();
    if (go != INF && (go <= now || exp((now - go) / T)) * UINT_MAX > rng()) {
      now = go;
    } else {
      res[x] -= det;
    }
    ans = min(ans, now);
    T *= coef;
  }
}
int main() {
  ans = 1e9;
  read(n);
  read(k);
  for (int i = 1; i <= k; i++) read(d[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) read(a[i][j]);
  }
  st = clock();
  while (1) {
    SA(10, 1e-3, 0.9996);
    SA(1000, 1e-6, 0.999);
    SA(100, 1e-7, 0.998);
    SA(1000, 1e-6, 0.997);
  }
  return 0;
}
