#include <bits/stdc++.h>
using namespace std;
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  file_i_o();
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    if (n > s) {
      cout << 0 << endl;
    } else if (n == 1) {
      cout << s << endl;
    } else {
      long double a = n / 2.0;
      if (a - floor(a) >= 0.5)
        a = ceil(a);
      else
        a = floor(a);
      int ans = floor(s / (n - a + 1));
      cout << ans << endl;
    }
  }
  return 0;
}
