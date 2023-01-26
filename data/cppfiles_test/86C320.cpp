#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;
const ll inf = 2 * 1e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i < n - 1) {
        if (s1[i] == '0' && s2[i] == '0') {
          if (s1[i + 1] == '1' && s2[i + 1] == '1') {
            ans += 2;
            ++i;
          } else {
            ++ans;
          }
          continue;
        }
        if (s1[i] == '1' && s2[i] == '1') {
          if (s1[i + 1] == '0' && s2[i + 1] == '0') {
            ans += 2;
            ++i;
          }
          continue;
        }
        ans += 2;
      } else {
        if (s1[i] == '0' && s2[i] == '0') {
          ++ans;
        } else if (s1[i] == '1' && s2[i] == '1') {
        } else {
          ans += 2;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
