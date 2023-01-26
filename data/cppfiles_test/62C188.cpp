#include <bits/stdc++.h>
using namespace std;
const long long nax = 100001;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
    }
    if (a[0]) {
      cout << n + 1 << ' ';
      for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
      }
      cout << '\n';
      continue;
    }
    if (!a.back()) {
      for (int i = 1; i <= n + 1; ++i) {
        cout << i << ' ';
      }
      cout << '\n';
      continue;
    }
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == 0 && a[i + 1] == 1) {
        for (int j = 1; j <= i + 1; ++j) {
          cout << j << ' ';
        }
        cout << n + 1 << ' ';
        for (int j = i + 2; j <= n; ++j) {
          cout << j << ' ';
        }
        cout << '\n';
        break;
      }
    }
  }
}
