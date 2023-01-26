#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l1 = s.length();
    char c = s[0];
    int cnt = 1;
    for (int i = 1; i < l1; i++) {
      if (s[i] != c) {
        cnt++;
        c = s[i];
      }
    }
    if (cnt == 2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
