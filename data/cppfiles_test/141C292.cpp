#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string a, b, ans;
    cin >> a >> b;
    bool f = true;
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 and j >= 0) {
      int x = a[i] - '0', y = b[j] - '0';
      if (x > y) {
        if (j == 0) {
          f = false;
          break;
        }
        j--;
        y = stoi(b.substr(j, 2));
      }
      if (!f or y - x > 9 or y < x) {
        f = false;
        break;
      }
      ans += to_string(y - x);
      i--;
      j--;
    }
    if (i >= 0) {
      f = false;
    } else if (j >= 0) {
      string x = b.substr(0, j + 1);
      reverse(x.begin(), x.end());
      ans += x;
    }
    if (f) {
      int n = ans.length() - 1;
      while (ans[n] == '0') {
        ans.pop_back();
        n--;
      }
      reverse(ans.begin(), ans.end());
      cout << ans << "\n";
    } else
      cout << -1 << "\n";
  }
}
