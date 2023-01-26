#include <bits/stdc++.h>
using namespace std;
const int64_t X = 1e9 + 7;
const int64_t inf = 1e18;
void prec(double n, int64_t d) {
  cout << fixed << setprecision(d) << n << endl;
}
int64_t prime[1000001];
void sieve(int64_t n) {
  for (int64_t i = 0; (0 <= n + 1) ? (i < n + 1) : (i >= n + 1);
       (0 <= n + 1) ? (i++) : (i--))
    prime[i] = 1;
  for (int64_t i = 2; i * i <= n; i++) {
    if (prime[i] != 1) continue;
    for (int64_t j = i * i; j <= n; j = j + i) {
      if (prime[j] == 1) {
        prime[j] = i;
      }
    }
  }
}
int64_t gcd(int64_t a, int64_t b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int64_t bin(int64_t a, int64_t n, int64_t m) {
  int64_t res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % m;
      n--;
    }
    a = (a * a) % m;
    n /= 2;
  }
  return res;
}
int64_t fact[1000001];
void precompute(int64_t n) {
  fact[0] = 1;
  for (int64_t i = 1; (1 <= n + 1) ? (i < n + 1) : (i >= n + 1);
       (1 <= n + 1) ? (i++) : (i--))
    fact[i] = (fact[i - 1] * i) % X;
}
int64_t ncr(int64_t n, int64_t r) {
  if (r == 0)
    return 1;
  else if (r > n)
    return 0;
  else
    return ((fact[n] * bin(fact[r], X - 2, X)) % X *
            bin(fact[n - r], X - 2, X)) %
           X;
}
int64_t my_rand() {
  int64_t x = rand();
  int64_t y = rand();
  int64_t ans = x * (RAND_MAX + y) + y;
  return ans;
}
void bfs(int64_t s, vector<int64_t> g[], int64_t n) {
  bool vis[n];
  for (int64_t i = 0; (0 <= n) ? (i < n) : (i >= n); (0 <= n) ? (i++) : (i--))
    vis[i] = false;
  vis[s] = true;
  deque<int64_t> q;
  q.push_back(s);
  while (!q.empty()) {
    s = q.front();
    q.pop_front();
    for (int64_t i = 0; i < (int64_t)g[s].size(); i++) {
      if (!vis[g[s][i]]) {
        vis[g[s][i]] = true;
        q.push_back(g[s][i]);
      }
    }
  }
}
void dfs(int64_t u, vector<int64_t> g[], bool *vis) {
  vis[u] = true;
  for (int64_t i = 0; i < (int64_t)g[u].size(); i++) {
    if (!vis[g[u][i]]) {
      dfs(g[u][i], g, vis);
    }
  }
}
void contest(int64_t tt) {
  int64_t n, m, r1, r2, c1, c2;
  cin >> n >> m >> r1 >> c1 >> r2 >> c2;
  int64_t ans = 0;
  int64_t x = 1;
  int64_t y = 1;
  while (true) {
    if (r1 == r2 || c1 == c2) {
      cout << ans << endl;
      return;
    }
    ans++;
    if (r1 == n) {
      x = -1;
    }
    if (c1 == m) {
      y = -1;
    }
    r1 += x;
    c1 += y;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t T = 1;
  cin >> T;
  for (int64_t tt = 0; (0 <= T) ? (tt < T) : (tt >= T);
       (0 <= T) ? (tt++) : (tt--)) {
    contest(tt);
  }
  return 0;
}
