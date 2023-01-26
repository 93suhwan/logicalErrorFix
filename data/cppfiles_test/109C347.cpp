#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll T = 0;
  cin >> T;
  while (T--) {
    ll N = 0, i = 0, ans = 0;
    cin >> N;
    string str;
    cin >> str;
    for (i = 0; i < N; i++) {
      if (i == (N - 1))
        ans += int(str[i]) - 48;
      else {
        if (int(str[i]) > 48) ans += int(str[i]) - 47;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
