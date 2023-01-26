#include <bits/stdc++.h>
using namespace std;
const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const long long INF = 2e18;
const int maxN = 5e5 + 1;
double getTime() { return clock() / (double)CLOCKS_PER_SEC; }
inline int add(const int &a, const int &b) {
  return a + b >= md ? a + b - md : a + b;
}
inline int sub(const int &a, const int &b) {
  return a - b < 0 ? a - b + md : a - b;
}
inline int mul(const int &a, const int &b) { return (1ll * a * b) % md; }
int binpow(int a, int b) {
  if (b <= 0) return 1;
  if (b % 2) return mul(a, binpow(a, b - 1));
  int m = binpow(a, b / 2);
  return mul(m, m);
}
int rev(int a) { return binpow(a, md - 2); }
int n, k;
vector<int> d;
vector<vector<long long>> g;
vector<int> deg;
long long last = 0;
void solve1() {
  last = 0;
  deg.assign(n, 0);
  vector<bool> was(n);
  vector<long long> mn(n, INF);
  vector<int> fr(n, -1);
  mn[0] = 0;
  for (int _ = 0; _ < (n); ++_) {
    int x = -1;
    for (int j = 0; j < (n); ++j) {
      if (was[j]) continue;
      if (mn[j] < mn[x] || x == -1) {
        x = j;
        continue;
      }
      if (mn[j] == mn[x] && fr[j] >= k && j >= k) {
        x = j;
      }
    }
    if (fr[x] != -1) {
      deg[x]++;
      deg[fr[x]]++;
    }
    last += mn[x];
    was[x] = true;
    for (int j = 0; j < (n); ++j) {
      if (was[j]) continue;
      if (mn[j] > g[x][j]) {
        mn[j] = g[x][j];
        fr[j] = x;
      } else if (mn[j] == g[x][j] && x >= k) {
        fr[j] = x;
      }
    }
  }
}
void go(int i) {
  if (i == k) {
    solve1();
    return;
  }
  int l = 0, r = 110;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    for (int j = 0; j < (n); ++j) {
      g[i][j] += mid;
      g[j][i] += mid;
    }
    go(i + 1);
    for (int j = 0; j < (n); ++j) {
      g[i][j] -= mid;
      g[j][i] -= mid;
    }
    if (deg[i] <= d[i]) {
      r = mid;
    } else {
      l = mid;
    }
  }
  for (int j = 0; j < (n); ++j) {
    g[i][j] += r;
    g[j][i] += r;
  }
  go(i + 1);
  for (int j = 0; j < (n); ++j) {
    g[i][j] -= r;
    g[j][i] -= r;
  }
  last -= deg[i] * r;
}
void solve() {
  cin >> n >> k;
  d.resize(k);
  for (int i = 0; i < (k); ++i) cin >> d[i];
  g.resize(n, vector<long long>(n));
  vector<int> ord(n);
  vector<long long> d2(n, n);
  for (int i = 0; i < (k); ++i) d2[i] = d[i];
  iota((ord).begin(), (ord).end(), 0ll);
  sort((ord).begin(), (ord).end(), [&](const int &i, const int &j) {
    return make_pair(d2[i], i) < make_pair(d2[j], j);
  });
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  for (int l = 0, r = 0; l < n; l = r) {
    while (r < n && d2[ord[r]] == d2[ord[l]]) r++;
    if (l < k) r = min(r, k);
    shuffle(ord.begin() + l, ord.begin() + r, rng);
  }
  vector<int> pos(n);
  for (int i = 0; i < (n); ++i) pos[ord[i]] = i;
  for (int i = 0; i < (n); ++i) {
    for (int j = i + 1; j < n; ++j) {
      cin >> g[pos[i]][pos[j]];
      g[pos[j]][pos[i]] = g[pos[i]][pos[j]];
    }
  }
  for (int i = 0; i < (k); ++i) d[i] = d2[ord[i]];
  go(0);
  cout << last << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tests = 1;
  for (int _ = 0; _ < (tests); ++_) {
    solve();
  }
  return 0;
}
