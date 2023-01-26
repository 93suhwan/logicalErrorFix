#include <bits/stdc++.h>
using namespace std;
auto rng = bind(uniform_int_distribution<int>(1, 1000), mt19937(time(0)));
template <class T>
bool umin(T &a, const T &b) {
  return (a > b ? a = b, 1 : 0);
}
template <class T>
bool umax(T &a, const T &b) {
  return (a < b ? a = b, 1 : 0);
}
const int M = 998244353;
void add(int &a, int b) {
  a += b;
  if (a >= M)
    a -= M;
  else if (a < 0)
    a += M;
}
int mult(int a, int b) { return 1ll * a * b % M; }
int binpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = mult(ans, a);
    b >>= 1;
    a = mult(a, a);
  }
  return ans;
}
const int N = 3e5 + 1;
bool used[N];
int lft[N], rgt[N];
bool isr[N];
vector<int> pos[N];
bool bad[N];
vector<int> lengs;
int ways[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> vc(n, vector<int>());
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    vector<int> a(c);
    for (int j = 0; j < c; j++) {
      cin >> a[j], used[a[j]] = 1;
      if ((int)pos[a[j]].size() && pos[a[j]].back() == i) {
        bad[a[j]] = 1;
      }
      pos[a[j]].push_back(i);
    }
    vc[i] = a;
    for (int j = 0; j < c; j++) {
      if (j > 0) {
        if (!lft[a[j]] || lft[a[j]] == a[j - 1]) {
          lft[a[j]] = a[j - 1];
        } else
          bad[a[j]] = 1;
      }
      if (j + 1 < c) {
        if (!rgt[a[j]] || rgt[a[j]] == a[j + 1]) {
          rgt[a[j]] = a[j + 1];
          continue;
        } else
          bad[a[j]] = 1;
      }
    }
  }
  queue<int> q;
  for (int i = 1; i <= k; i++) {
    if (bad[i]) q.push(i);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto &j : pos[x]) {
      if (isr[j]) continue;
      isr[j] = 1;
      for (auto &v : vc[j]) {
        if (!bad[v]) {
          bad[v] = 1;
          q.push(v);
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    if (bad[i]) continue;
    if (!lft[i]) {
      int v = i;
      int cnt = 0;
      while (v) {
        cnt++;
        v = rgt[v];
      }
      lengs.push_back(cnt);
      ways[cnt]++;
    }
  }
  if (!(int)lengs.size()) {
    cout << 0;
    return 0;
  }
  vector<int> dp(m + 1, 0);
  sort(lengs.begin(), lengs.end());
  lengs.erase(unique(lengs.begin(), lengs.end()), lengs.end());
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (auto &j : lengs) {
      if (i >= j) add(dp[i], mult(ways[j], dp[i - j]));
    }
  }
  cout << dp[m];
  return 0;
}
