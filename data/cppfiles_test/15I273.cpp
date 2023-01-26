#include <bits/stdc++.h>
using namespace std;
void solve();
void _print(long long x) { cerr << x; }
template <class T>
void _print(vector<T> v) {
  cout << " [ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
long long o = 0;
long long M = 1e9 + 7;
unsigned long long fac[101];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  chrono::high_resolution_clock::time_point t1 =
      chrono::high_resolution_clock::now();
  long long t;
  fac[0] = 1;
  for (int i = 1; i <= 101; i++) fac[i] = (fac[i - 1] * i) % M;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  chrono::high_resolution_clock::time_point t2 =
      chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> time_span = t2 - t1;
  return 0;
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<vector<long long> > edges(n + 1);
  for (long long i = (0); i < (n - 1); i++) {
    long long x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  if (k == 2) {
    cout << nCrModPFermat(n, 2, M);
    return;
  }
  vector<long long> deg(n + 1);
  vector<long long> temp;
  long long ans = 0;
  function<void(long long, long long, long long)> dfs =
      [&](long long a, long long p, long long d) {
        if (deg[a] == 1) {
          temp.push_back(d);
          return;
        }
        for (auto x : edges[a]) {
          if (x == p) continue;
          dfs(x, a, d + 1);
        }
        return;
      };
  for (long long i = (1); i < (n + 1); i++) {
    deg[i] = edges[i].size();
  }
  for (long long i = (1); i < (n + 1); i++) {
    if (deg[i] >= k) {
      temp.clear();
      dfs(i, -1, 0);
      sort((temp).begin(), (temp).end());
      long long p = 0;
      for (long long l = (0); l < (temp.size() - k + 1); l++) {
        ans += (nCrModPFermat((temp.size() - l), k, M) * (temp[l] - p)) % M;
        ans %= M;
        p = temp[l];
      }
    }
  }
  cout << ans;
}
