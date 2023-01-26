#include <bits/stdc++.h>
using namespace std;
void solvetask() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) s[i] -= 'a';
  int ans = n + 1;
  for (int c = 0; c < 26; c++) {
    int i = 0, j = n - 1;
    bool can = true;
    int cur = 0;
    while (i < j) {
      if (s[i] != s[j]) {
        if (s[i] != c && s[j] != c) {
          can = false;
          break;
        } else if (s[i] == c) {
          i++;
          cur++;
        } else if (s[j] == c) {
          j--;
          cur++;
        }
      } else {
        i++;
        j--;
      }
    }
    if (can) {
      ans = min(ans, cur);
    }
  }
  cout << (ans == n + 1 ? -1 : ans) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solvetask();
}
