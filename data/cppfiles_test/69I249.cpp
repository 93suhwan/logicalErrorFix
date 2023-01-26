#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 1e9;
    string a = to_string(n);
    for (long long m = 1; m < (1LL << 40); m <<= 1LL) {
      string b = to_string(m);
      int c = 0, p = 0;
      for (int i = 0; i < a.size(); i++)
        if (p < b.size() && a[i] == b[p]) ++c, ++p;
      c = (int)a.size() - c + (int)b.size() - c;
      ans = min(ans, c);
    }
    cout << ans << '\n';
  }
  return 0;
}
