#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 200010, mod = 998244353;
int a[N], n;
char s[N];
int b[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], b[i] = 0;
  cin >> s + 1;
  vector<int> x, y;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      if (a[i] <= 0) {
        puts("NO");
        return;
      }
      x.push_back(a[i]);
    } else {
      if (a[i] > n) {
        puts("NO");
        return;
      }
      y.push_back(a[i]);
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end(), greater<int>());
  for (int i = 0; i < x.size(); i++)
    if (x[i] < i + 1) {
      puts("NO");
      return;
    }
  for (int i = 0, j = n; i < y.size(); i++, j--)
    if (y[i] > j) {
      puts("NO");
      return;
    }
  puts("YES");
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
