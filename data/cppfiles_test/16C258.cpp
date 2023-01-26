#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6, inf = 1e9;
long long tc, con, n, q, u, v;
inline void sol() {
  cin >> tc;
  string s, c;
  while (tc--) {
    cin >> n;
    cin >> s;
    c = s;
    con = 0;
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
      if (s[i] != c[i]) con++;
    }
    cout << con << "\n";
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  sol();
  return 0;
}
