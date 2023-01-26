#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int remove(string s, int i, int j, char ch) {
  int cnt = 0;
  while (i < j) {
    if (s[i] != s[j] && s[i] != ch && s[j] != ch) return INT_MAX;
    if (s[i] != s[j] && s[i] == ch) {
      cnt++;
      i++;
      continue;
    }
    if (s[i] != s[j] && s[j] == ch) {
      cnt++;
      j--;
      continue;
    }
    i++, j--;
  }
  return cnt;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0, j = n - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      break;
    }
    i++, j--;
  }
  int ans = min(remove(s, i, j, s[i]), remove(s, i, j, s[j]));
  if (ans == INT_MAX)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
