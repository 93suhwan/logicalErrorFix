#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string arr;
  cin >> arr;
  for (int i = 0; i < n; i++) {
    if (arr[i] == '0') {
      if (n - i >= i + 1) {
        cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
      } else {
        cout << "1 " << i + 1 << " 1 " << i << "\n";
      }
      return;
    }
  }
  cout << "1 " << n << " 1 1\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
