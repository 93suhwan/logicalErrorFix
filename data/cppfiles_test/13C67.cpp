#include <bits/stdc++.h>
using namespace std;
long long t, a[5];
string s;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> s;
    memset(a, 0, sizeof(a));
    for (auto i : s) a[i - 'A']++;
    cout << (a[1] == a[0] + a[2] ? "YES\n" : "NO\n");
  }
  return 0;
}
