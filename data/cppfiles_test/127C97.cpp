#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 2050;
void solve() {
  int b = 0, c = 0, a = 0;
  char s[maxn];
  string t;
  cin >> s >> t;
  sort(s, s + strlen(s));
  if (t == "abc") {
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == 'b')
        b++;
      else if (s[i] == 'c')
        c++;
      else if (s[i] == 'a')
        a++;
    }
    if (a == 0 || b == 0 || c == 0) {
      cout << s << endl;
    } else {
      for (int i = 1; i <= a; i++) cout << 'a';
      for (int i = 1; i <= c; i++) cout << 'c';
      for (int i = 1; i <= b; i++) cout << 'b';
      for (int i = a + b + c; i < strlen(s); i++) cout << s[i];
      cout << endl;
    }
  } else
    cout << s << endl;
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
