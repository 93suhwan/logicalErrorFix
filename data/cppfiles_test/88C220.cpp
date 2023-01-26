#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    if (n % 2 == 0) {
      cout << "YES\n";
    } else {
      bool ok = false;
      for (int i = 0; i < n - 1; ++i) {
        if (a[i] >= a[i + 1]) {
          ok = true;
          break;
        }
      }
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}
