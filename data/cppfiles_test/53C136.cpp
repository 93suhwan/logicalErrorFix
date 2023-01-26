#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int temp, prev, curr, i, j, k;
  long long int t, n;
  cin >> t;
  while (t-- > 0) {
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    long long int cnt = 0;
    vector<long long int> ans;
    bool ok = false;
    for (i = 0; i < n; i++) {
      if (s[i] != c) {
        ok = true;
        break;
      }
    }
    if (ok) {
      for (i = 1; i < n; i++) {
        if (s[i] == c) {
          bool flg = true;
          for (j = 2 * i + 1; j < n; j += (i + 1)) {
            if (s[j] != c) {
              flg = false;
              break;
            }
          }
          if (flg) {
            cnt = 1;
            ans.push_back(i + 1);
            break;
          }
        }
      }
      if (!cnt) {
        cnt = 2;
        ans.push_back(n);
        ans.push_back(n - 1);
      }
    }
    cout << cnt;
    cout << "\n";
    for (auto x : ans) {
      cout << x << " ";
    }
    if (cnt) cout << "\n";
  }
}
