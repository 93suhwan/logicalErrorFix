#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1e9 + 7;
pair<int, int> a[N];
int s[N];
int st[N];
void slove() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int t;
    cin >> t;
    a[i] = {t, i};
  }
  sort(a + 1, a + 1 + m);
  int res = 0;
  int resn = 1;
  for (int i = 1; i <= m; i++) {
    if (a[i].first == a[i - 1].first) {
      resn++;
    } else {
      res += resn * (resn - 1) / 2;
      resn = 1;
    }
    s[a[i].second] = i;
  }
  int ans = 0;
  memset(st, 0, sizeof st);
  st[s[1]] = 1;
  for (int i = 2; i <= m; i++) {
    int cnt = 0;
    st[s[i]] = 1;
    for (int j = 1; j < s[i]; j++) {
      if (st[j] == 1) cnt++;
    }
    ans += cnt;
  }
  ans -= res;
  cout << ans << endl;
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    slove();
  }
  return 0;
}
