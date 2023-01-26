#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int cnt[26] = {0};
  for (auto x : s) {
    cnt[x - 'a']++;
  }
  string ans = "";
  int c, b, a;
  for (int i = 0; i < 3; i++) {
    if (t[i] == 'c') c = i;
    if (t[i] == 'b') b = i;
    if (t[i] == 'a') a = i;
  }
  if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0 || a > 0) {
    sort(s.begin(), s.end());
    cout << s << "\n";
    return;
  }
  if (c < b) {
    for (int i = 0; i < 26; i++) {
      while (cnt[i]--) cout << (char)(i + 'a');
    }
    cout << "\n";
  } else {
    while (cnt[0]--) cout << 'a';
    while (cnt[2]--) cout << 'c';
    while (cnt[1]--) cout << 'b';
    for (int i = 3; i < 26; i++) {
      while (cnt[i]--) cout << (char)(i + 'a');
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
