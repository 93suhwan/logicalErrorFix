#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (!a[n - 1])
      for (int i = 0; i < n + 1; i++) cout << i + 1 << ' ';
    else {
      bool ok = false;
      for (int i = 0; i < n - 1; i++)
        if (!a[i] && a[i + 1]) {
          for (int j = 0; j < i; j++) cout << j + 1 << ' ';
          cout << i + 1 << ' ' << n + 1 << ' ';
          for (int j = i + 1; j <= n - 1; j++) cout << j + 1 << ' ';
          ok = true;
        }
      if (!ok) cout << -1;
    }
    cout << endl;
  }
}
