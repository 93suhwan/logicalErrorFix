#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
long long int MOD2 = 998244353;
void solve() {
  string s, t, rem;
  cin >> s >> t;
  rem = "";
  int cnt[3] = {0};
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' and s[i] <= 'c') {
      int x = s[i] - 'a';
      cnt[x] += 1;
    } else
      rem += s[i];
  }
  sort(rem.begin(), rem.end());
  if (t[0] == 'a' and cnt[0]) {
    for (int i = 0; i < cnt[0]; i++) cout << 'a';
    if (t[1] == 'b' and cnt[1]) {
      for (int i = 0; i < cnt[2]; i++) cout << 'c';
      for (int i = 0; i < cnt[1]; i++) cout << 'b';
    } else {
      for (int i = 0; i < cnt[1]; i++) cout << 'b';
      for (int i = 0; i < cnt[2]; i++) cout << 'c';
    }
  } else {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        char c = i + 'a';
        cout << c;
      }
    }
  }
  cout << rem << endl;
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
