#include <bits/stdc++.h>
using namespace std;
inline void io() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
long long I() {
  long long a;
  cin >> a;
  return a;
}
void PV(vector<long long> v) {
  for (long long i = 0; i < (long long)v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
void PA(long long v[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cout << v[i] << " ";
  cout << "\n";
}
void IA(long long a[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cin >> a[i];
}
const long long N = 1e9 + 7, N1 = 1e7, MOD = 998244353, INF = (1e17 + 7);
void solve() {
  long long n, s;
  cin >> n >> s;
  long long nf = n - (n - 1) / 2;
  cout << max(n - n, s / nf) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t1 = 1, x0 = 1;
  cin >> t1;
  while (t1--) {
    solve();
  }
}
