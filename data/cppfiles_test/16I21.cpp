#include <bits/stdc++.h>
using namespace std;
struct AC {
  char ch;
  int pos;
  bool friend operator<(AC m1, AC m2) {
    if (m1.ch != m2.ch)
      return m1.ch < m2.ch;
    else
      return m1.pos < m2.pos;
  }
} v[50];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    char s[50];
    cin >> s + 1;
    for (int i = 1; i <= n; i++) {
      v[i].ch = s[i];
      v[i].pos = i;
    }
    sort(v + 1, v + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (v[i].pos != i) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
