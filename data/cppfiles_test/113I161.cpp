#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD9 = 998244353;
long long MOD = 1000000007;
double eps = 1e-12;
void solve() {
  int n;
  cin >> n;
  long long a[n], sum = 0;
  for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
  sort(a, a + n);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    int p = lower_bound(a, a + n, x) - a;
    cout << min(p < n ? max(0LL, y - sum + a[p]) : INT_MAX,
                p > 0 ? x - a[p - 1] + max(0LL, y - sum + a[p - 1]) : INT_MAX)
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  chrono::time_point<chrono::high_resolution_clock> chrono_start =
      chrono::high_resolution_clock::now();
  solve();
  cerr << "Time taken: "
       << chrono::duration_cast<chrono::milliseconds>(
              chrono::high_resolution_clock::now() - chrono_start)
              .count()
       << " milliseconds"
       << "\n";
  return 0;
}
