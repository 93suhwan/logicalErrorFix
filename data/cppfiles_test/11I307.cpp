#include <bits/stdc++.h>
using namespace std;
void db() { cerr << endl; }
template <typename T, typename... U>
void db(T a, U... b) {
  cerr << a << ' ', db(b...);
}
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
const int N = 3e5 + 1;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int h = n * m / 2 - k;
    bool imp = 0;
    if (n % 2) {
      if (2 * k < m) imp = 1;
      k -= m / 2;
    } else if (m % 2) {
      if (2 * h < n) imp = 1;
      h -= n / 2;
    }
    if (k % 2 or h % 2) {
      imp = 1;
    }
    cout << (imp ? "NO\n" : "YES\n");
  }
}
