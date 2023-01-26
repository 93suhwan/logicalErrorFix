#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    int dem = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (s[i] == 'C') dem++;
    }
    cout << (dem % 2 == 0 ? "YES" : "NO") << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
