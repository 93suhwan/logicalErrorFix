#include <bits/stdc++.h>
using namespace std;
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  file_i_o();
  long long t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    if (n > s) {
      cout << 0 << endl;
    } else if (n == 1) {
      cout << s << endl;
    } else {
      long long a = lround(n / 2.0);
      long long ans = lround(s / (n - a + 1));
      cout << ans << endl;
    }
  }
  return 0;
}
