#include <bits/stdc++.h>
using namespace std;
void solve() {
  int i, j, k, mapp[27], cou = 0, cur;
  char str[27];
  string s;
  cin >> str;
  cin >> s;
  if (s.length() == 1) {
    cout << 0 << "\n";
    return;
  }
  for (i = 0; i < 26; i++) {
    mapp[str[i] - 97] = i;
  }
  cur = mapp[s[0] - 97];
  for (i = 1; i < s.length(); i++) {
    cou += abs(cur - mapp[s[i] - 97]);
    cur = mapp[s[i] - 97];
  }
  cout << cou << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, T = 1;
  cin >> T;
  for (t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
