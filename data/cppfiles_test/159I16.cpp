#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int prime[maxn], np[maxn], tot = 0;
void init(int n) {
  np[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!np[i]) prime[++tot] = i;
    for (int j = 1; j <= tot; ++j) {
      if (i * prime[j] > n) break;
      np[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int f(int x, int p) {
  int ans = 0;
  while (x) ans += x /= p;
  return ans & 1;
}
int check(vector<int> b) {
  int mx = *max_element(b.begin(), b.end());
  for (int i = 1; i <= tot; ++i) {
    if (prime[i] > mx) break;
    int cnt = 0;
    for (int j : b) {
      cnt += f(j, prime[i]);
    }
    if (cnt & 1) return 0;
  }
  return 1;
}
vector<int> brute(int n) {
  int ans = n - 4;
  vector<int> a, b, del(n + 1);
  function<void(int, int)> dfs = [&](int p, int d) {
    if (n - d <= ans) return;
    if (p == n + 1) {
      if (check(b)) {
        ans = b.size();
        a = b;
      }
      return;
    }
    b.push_back(p);
    dfs(p + 1, d);
    b.pop_back();
    del[p] = 1;
    dfs(p + 1, d + 1);
    del[p] = 0;
  };
  dfs(1, 0);
  return a;
}
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
const int K = 30;
int tr[maxn * K + 5][2];
vector<int> solve(int n) {
  vector<int> ps(prime + 1, prime + 1 + tot);
  if (ps.size() > K) {
    shuffle(ps.begin() + K / 2, ps.end(), mrand);
    ps.resize(K);
  }
  int m = ps.size();
  bitset<K> s(m);
  vector<bitset<K>> a(n + 1);
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = f(i, ps[j]);
      if (a[i][j]) s[j].flip();
    }
  }
  if (!s.count()) {
    vector<int> ret;
    for (int j = 1; j <= n; ++j) {
      ret.push_back(j);
    }
    return ret;
  }
  for (int i = 2; i <= n; ++i) {
    if (s == a[i]) {
      vector<int> ret;
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        ret.push_back(j);
      }
      return ret;
    }
  }
  int cnt = 0;
  memset(tr, 0, sizeof(tr));
  for (int i = 2; i <= n; ++i) {
    int p = 0, ok = 1;
    for (int j = 0; j < m; ++j) {
      if (!tr[p][a[i][j] ^ s[j]]) {
        ok = 0;
        break;
      }
      p = tr[p][a[i][j] ^ s[j]];
    }
    if (ok) {
      int x = tr[p][0], y = i;
      vector<int> ret;
      for (int j = 1; j <= n; ++j) {
        if (y == j || x == j) continue;
        ret.push_back(j);
      }
      return ret;
    }
    p = 0;
    for (int j = 0; j < m; ++j) {
      if (!tr[p][a[i][j]]) tr[p][a[i][j]] = ++cnt;
      p = tr[p][a[i][j]];
    }
    tr[p][0] = i;
  }
  return solve(n - 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  init(n);
  if (n <= 50) {
    auto ans = brute(n);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << " ";
    cout << '\n';
  } else {
    auto ans = solve(n);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << " ";
    cout << '\n';
  }
}
