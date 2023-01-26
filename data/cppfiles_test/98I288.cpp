#include <bits/stdc++.h>
using namespace std;
void busted() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k = 2;
  int a = 0, b = 0;
  if (s[0] == 'a') a++;
  if (s[0] == 'b') b++;
  if (s[1] == 'a') a++;
  if (s[1] == 'b') b++;
  while (k <= n) {
    for (int i = 1; i < n - k; i++) {
      if (a == b) {
        cout << i + 1 << " " << i + k << '\n';
        return;
      }
      if (s[i - 1] == 'a') a--;
      if (s[i + k - 1] == 'b') b++;
      if (s[i - 1] == 'b') b--;
      if (s[i + k - 1] == 'a') a++;
    }
    k += 2;
  }
  cout << "-1 -1\n";
  return;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) busted();
  return 0;
}
