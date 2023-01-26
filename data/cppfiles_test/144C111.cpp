#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long p = n / m;
    long long c = n % m;
    long long ul = 0, st = 0;
    for (int _ = 0, ggdem = k; _ < ggdem; ++_) {
      ul = st;
      for (int j = 0, ggdem = c; j < ggdem; ++j) {
        cout << p + 1 << " ";
        for (int i = 0, ggdem = p + 1; i < ggdem; ++i) {
          ul = (ul + 1) % n;
          cout << ul + 1 << " ";
        }
        cout << "\n";
      }
      for (int j = 0, ggdem = m - c; j < ggdem; ++j) {
        cout << p << " ";
        for (int i = 0, ggdem = p; i < ggdem; ++i) {
          ul = (ul + 1) % n;
          cout << ul + 1 << " ";
        }
        cout << "\n";
      }
      st = (st + (p + 1) * c) % n;
    }
    cout << "\n";
  }
  return 0;
}
