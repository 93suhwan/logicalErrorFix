#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const long long int NINF = -(1e18);
long long int mod = 998244353;
void solve_case() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int lo = n / m, bg = n % m;
  long long int st = 0;
  for (long long int bl = 0; bl < k; bl++) {
    long long int i = st;
    for (long long int j = 0; j < bg; j++) {
      cout << (lo + 1) << " ";
      for (long long int it = 0; it < (lo + 1); it++) {
        cout << i + 1 << " ";
        i = (i + 1) % n;
      }
      cout << "\n";
    }
    for (long long int j = 0; j < m - bg; j++) {
      cout << lo << " ";
      for (long long int it = 0; it < lo; it++) {
        cout << i + 1 << " ";
        i = (i + 1) % n;
      }
      cout << "\n";
    }
    st = (st + bg * (lo + 1)) % n;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  clock_t clk = clock();
  cout << fixed << setprecision(6);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve_case();
  }
  cerr << fixed << setprecision(6)
       << "Time: " << ((double)(clock() - clk)) / CLOCKS_PER_SEC << "\n";
  return 0;
}
