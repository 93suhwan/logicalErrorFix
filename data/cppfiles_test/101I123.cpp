#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 200010;
int n;
char s[N];
int a[N];
void solve() {}
int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] <= 0 && s[i] == 'B') {
        puts("NO");
        return 0;
      }
      if (a[i] > n && s[i] == 'R') {
        puts("NO");
        return 0;
      }
    }
    vector<int> down(n + 1, 0), up(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (a[i] <= 0 || a[i] > n) continue;
      if (s[i] == 'B')
        down[a[i]]++;
      else if (s[i] == 'R')
        up[a[i]]++;
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (down[i] > i || up[i] > n - i + 1) {
        ok = false;
        break;
      }
    }
    if (ok)
      puts("YES");
    else
      puts("NO");
    if (i == 1210) {
      cout << n << '\n';
      for (int i = 1; i <= n; i++) cout << a[i] << ' ';
      cout << '\n';
      cout << s + 1 << '\n';
    }
  }
  return 0;
}
