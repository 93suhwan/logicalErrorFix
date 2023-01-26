#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, t, k;
int s[N], dp[N], f[N];
unordered_map<int, int> ma;
string str;
vector<int> vec;
void solve() {
  ma.clear();
  int d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) scanf("%d", &s[i]);
  for (int i = 0; i < n; i++) {
    if (s[i] == 0) {
      int j = i;
      while (s[(j + d) % n] == 1) {
        if (ma[(j + d) % n]) break;
        ma[(j + d) % n] = ma[j] + 1;
        j = (j + d) % n;
      }
    }
  }
  int ans = 0;
  unordered_map<int, int>::iterator it;
  for (int i = 0; i < n; i++) {
    if (s[i] == 1) {
      if (ma[i]) {
        ans = max(ans, ma[i]);
      } else {
        puts("-1");
        return;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
