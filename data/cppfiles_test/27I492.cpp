#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1;
int T;
long long n, m, k;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    long long edges = 1ll * n * (n - 1) / 2ll;
    if (k <= 1ll) {
      cout << "NO\n";
      continue;
    }
    if (m == 0ll) {
      cout << "YES\n";
      continue;
    }
    if (k == 2ll) {
      cout << "NO\n";
      continue;
    }
    if (m > edges) {
      cout << "NO\n";
      continue;
    }
    if (k == 3ll) {
      long long tt = edges * 2;
      long long now = (long long)sqrt(tt);
      if (now * (now + 1) / 2 == m)
        cout << "YES\n";
      else
        cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}
