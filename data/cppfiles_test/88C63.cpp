#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    if (n % 2 == 0) {
      cout << "YES\n";
    } else {
      bool ok = true;
      for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
          ok = false;
          break;
        }
      }
      cout << (ok ? "NO\n" : "YES\n");
    }
  }
  return 0;
}
