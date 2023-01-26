#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(0);
}
bool isPrime(int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (int i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
bool BREAKTIME(long double v) { return 1.0 * clock() >= v * CLOCKS_PER_SEC; }
long long mod = 1e9 + 7;
const long long inf = 1e18;
long long n, k;
vector<long long> D;
void dfs(long long a, vector<vector<long long>>& adj, long long p) {
  D[a] = D[p] + 1;
  for (auto b : adj[a]) {
    if (b == p) continue;
    dfs(b, adj, a);
  }
}
int32_t main() {
  boostIO();
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vector<vector<long long>> adj(n + 1);
    for (long long i = 0; i < (n - 1); ++i) {
      long long a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    long long ans = 0;
    long long additional = 0;
    for (long long s = 1; s <= n; ++s) {
      vector<vector<long long>> A(n + 1);
      for (auto a : adj[s]) {
        D = vector<long long>(n + 1);
        dfs(a, adj, s);
        vector<long long> d(n + 1);
        for (long long i = 1; i <= n; ++i) {
          d[D[i]]++;
        }
        for (long long i = 1; i <= n; ++i) {
          if (d[i] != 0) A[i].push_back(d[i]);
        }
      }
      for (auto v : A) {
        if (v.size() == 0) continue;
        vector<long long> e(v.size());
        vector<long long> e2(v.size());
        for (long long i = 0; i < v.size(); ++i) {
          e[i] = v[i];
          if (i != 0) {
            e[i] += e[i - 1];
          }
        }
        for (long long j = 0; j < k - 1; ++j) {
          for (long long i = 0; i < v.size(); ++i) {
            if (i != 0) {
              e2[i] = e[i - 1] * v[i];
              e2[i] += e2[i - 1];
            }
          }
          e = e2;
        }
        ans += e.back();
        ans %= mod;
      }
      if (k == 2) {
        additional += A[1].size();
        additional %= mod;
      }
      long long kaka = 1;
    }
    cout << (ans + additional / 2) % mod << '\n';
  }
}
