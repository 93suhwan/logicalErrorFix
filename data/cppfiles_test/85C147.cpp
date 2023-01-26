#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int one = 0, zero = 0, idx = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0' && idx == -1) idx = i;
      if (s[i] == '0')
        zero++;
      else
        one++;
    }
    int ans = 0;
    if (one == n && zero == 0)
      ans = 0;
    else if (one == 0 && zero == n)
      ans = 1;
    else {
      int n_zero = 0;
      for (int i = idx; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '0')
          n_zero++;
        else
          break;
      }
      int temp = 2;
      ans = min(temp, zero);
      if (n_zero + 1 == zero) ans = 1;
    }
    cout << ans << "\n";
  }
}
