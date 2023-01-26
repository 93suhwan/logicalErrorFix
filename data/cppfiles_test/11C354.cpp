#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t, n;
  vector<string> str(200005);
  vector<int> v(200005);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> str[i];
    }
    int ans = INT_MIN, cnt = 0, s = 0, x;
    for (char ch = 'a'; ch <= 'e'; ch++) {
      cnt = 0;
      s = 0;
      x = 0;
      for (int j = 0; j < n; j++) {
        x = 0;
        for (int k = 0; k < str[j].length(); k++) {
          if (str[j][k] == ch) x++;
        }
        v[j] = 2 * x - str[j].length();
      }
      sort(v.begin(), v.begin() + n);
      for (int i = n - 1; i >= 0; i--) {
        if (s + v[i] > 0) {
          s += v[i];
          cnt++;
        }
      }
      ans = max(ans, cnt);
    }
    cout << ans << "\n";
  }
  return 0;
}
