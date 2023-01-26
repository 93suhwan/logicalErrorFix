#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string second;
    cin >> second;
    bool used = 0;
    for (int i = 0; i < n; i++) {
      if (second[i] == '0') {
        if ((n - i - 1) >= n / 2) {
          cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << "\n";
          used = 1;
          break;
        }
      }
    }
    if (used) continue;
    for (int i = 0; i < n; i++) {
      if (second[i] == '0') {
        cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << "\n";
        used = 1;
        break;
      }
    }
    if (used) continue;
    cout << 1 << ' ' << n / 2 << ' ' << 2 << ' ' << n / 2 + 1 << "\n";
  }
}
