#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const long long MOD = INF + 7;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = n / m;
  int b = n % m;
  int h = (a + 1) * b;
  assert(h < n);
  int j = 1;
  for (int i = 0; i < k; ++i) {
    for (int l = 0; l < b; ++l) {
      cout << a + 1 << " ";
      for (int q = 0; q < a + 1; ++q) {
        cout << j++ << " ";
        if (j == n + 1) j = 1;
      }
      cout << "\n";
    }
    int j2 = j;
    for (int l = b; l < m; ++l) {
      cout << a << " ";
      for (int q = 0; q < a; ++q) {
        cout << j2++ << " ";
        if (j2 == n + 1) j2 = 1;
      }
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
