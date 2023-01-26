#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = -1, r = -1;
  for (int i = 0; i < n; i++) {
    int cnt1 = 0, cnt2 = 0;
    if (s[i] == 'a')
      ++cnt1;
    else
      ++cnt2;
    for (int j = i + 1; j < n; j++) {
      if (s[j] == 'a')
        ++cnt1;
      else
        ++cnt2;
      if (cnt1 == cnt2) {
        l = i + 1, r = j + 1;
        break;
      }
    }
  }
  cout << l << " " << r << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
