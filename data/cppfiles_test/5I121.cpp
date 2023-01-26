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
      string a;
      cin >> a;
      string b;
      cin >> b;
      int cnt1 = count(a.begin(), a.end(), '1');
      int cnt2 = count(b.begin(), b.end(), '1');
      if (cnt2 == 0) {
        cout << '0' << '\n';
        return;
      }
      if (cnt1 == 0) {
        cout << cnt2 << '\n';
        return;
      }
      if (cnt1 == cnt2 && cnt1 == a.size()) {
        cout << cnt1 << '\n';
        return;
      }
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == '1' && b[i + 1] == '1') {
          b[i + 1] = '0';
          cnt++;
        } else if (a[i] == '1' && b[i - 1] == '1') {
          b[i - 1] = '0';
          cnt++;
        } else if (a[i] == '1' && b[i] == '0') {
          cnt++;
        }
      }
      cout << cnt << '\n';
    }();
  }
  return 0;
}
