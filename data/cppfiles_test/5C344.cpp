#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    []() {
      int n;
      cin >> n;
      string b;
      cin >> b;
      string a;
      cin >> a;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == '1' && b[i] == '0') {
          cnt++;
        } else if (a[i] == '1' && b[i - 1] == '1') {
          b[i - 1] = '0';
          cnt++;
        } else if (a[i] == '1' && b[i + 1] == '1') {
          b[i + 1] = '0';
          cnt++;
        }
      }
      cout << cnt << '\n';
    }();
  }
  return 0;
}
