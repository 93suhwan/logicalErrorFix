#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
constexpr int l = 'z' - 'a' + 1;
void solve() {
  int cnt[l]{};
  string s;
  cin >> s;
  for (char &c : s) cnt[c - 'a']++;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < l; i++)
    if (cnt[i] == 1)
      c1++;
    else if (cnt[i] > 0)
      c2++;
  cout << c2 + c1 / 2 << endl;
}
