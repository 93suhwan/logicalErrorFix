#include <bits/stdc++.h>
using namespace std;
const int SI = 1e5 + 7;
long long INF = 8e18 + 7;
int MOD = 1e9 + 7;
int T = 1;
long long n;
string s, s2;
void solver() {
  cin >> n >> s >> s2;
  bool is = 0, c = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' || s2[i] == '0') is = 1;
    long long sum = s[i] - '0' + s2[i] - '0';
    if (sum == 0 && c == 1) {
      c = 0;
      ans += 2;
    } else if (sum == 0) {
      ans++;
      c = 0;
    } else if (sum == 1) {
      ans += 2;
      c = 0;
    } else if (sum == 2)
      c = 1;
  }
  if (is == 0 || n == 1)
    cout << ans << "\n";
  else
    cout << max(ans, 2ll) << "\n";
}
int main() {
  cin >> T;
  while (T--) solver();
  return 0;
}
