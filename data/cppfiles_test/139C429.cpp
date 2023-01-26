#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 10, INF = 0x3f3f3f3f;
void solve() {
  string s;
  cin >> s;
  if (s.size() & 1)
    cout << "NO" << endl;
  else {
    for (int i = 0; i < s.size() / 2; i++) {
      if (s[i] != s[i + s.size() / 2]) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
