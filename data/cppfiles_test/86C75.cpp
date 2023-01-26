#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MAX_SIZE = 1000005;
const long long int MAXN = 100000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    string c1;
    string c2;
    cin >> c1 >> c2;
    long long int ans = 0;
    long long int p = 0;
    for (long long int i = 0; i < n; i++) {
      if (c1[i] != c2[i]) {
        ans += 2;
        if (p == 1) {
          ans += 1;
        }
        p = 0;
      } else {
        if (c1[i] == '0') {
          if (p == -1) {
            ans += 2;
            p = 0;
          } else if (p == 0) {
            p = 1;
          } else {
            ans += 1;
            p = 1;
          }
        } else {
          if (p == 1) {
            ans += 2;
            p = 0;
          } else {
            p = -1;
          }
        }
      }
    }
    if (p == 1) {
      ans += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
