#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int a[26];
void solve() {
  for (int i = 0; i < 26; i++) a[i] = 0;
  int ans = 0;
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (a[s[i] - 'a'] < 2) {
      ans++;
      a[s[i] - 'a']++;
    }
  }
  cout << ans / 2 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
