#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
struct mt {
  int s, a;
} m[MAXN];
int n, d;
bool cmp(const mt& x, const mt& y) {
  return x.a == y.a ? (x.s < y.s) : (x.a < y.a);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> m[i].s >> m[i].a;
    if (m[i].s < d) {
      n--;
      i--;
      continue;
    }
  }
  sort(m + 1, m + n + 1, cmp);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (m[i].s >= d) {
      ans++;
      d = max(d, m[i].a);
    }
  }
  cout << ans;
  return 0;
}
