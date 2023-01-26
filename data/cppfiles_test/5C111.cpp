#include <bits/stdc++.h>
using namespace std;
long long solve() {
  int n;
  cin >> n;
  string s, e;
  cin >> e >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (e[i] == '0')
        ans++;
      else {
        if (i && e[i - 1] == '1')
          ans++, e[i - 1] = '2';
        else if (i < n - 1 && e[i + 1] == '1')
          ans++, e[i + 1] = '2';
      }
    }
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) cout << solve() << endl;
  return 0;
}
