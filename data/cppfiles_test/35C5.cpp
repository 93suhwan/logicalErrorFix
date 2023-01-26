#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double eps = (double)1e-9;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 1000500;
long long ans;
vector<pair<int, int> > pr[N];
int n, a[N], lp[N], pref[N];
int pw1[N], t[N][20];
inline void build() {
  for (int i = 2; i <= n; i++) pw1[i] = pw1[i >> 1] + 1;
  for (int j = 0; (1 << j) <= n; j++)
    for (int i = 1; i <= n; i++) t[i][j] = n;
}
inline void upd(int l, int r, int val) {
  if (l > r) return;
  int st = pw1[r - l + 1];
  t[l][st] = min(t[l][st], val);
  t[r - (1 << st) + 1][st] = min(t[r - (1 << st) + 1][st], val);
}
int main() {
  for (int i = 2; i * i < N; i++) {
    if (!lp[i]) {
      for (int j = i * i; j < N; j += i)
        if (!lp[j]) lp[j] = i;
    }
  }
  for (int i = 2; i < N; i++)
    if (!lp[i]) lp[i] = i;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  getchar();
  for (int i = 1; i <= n; i++) {
    char c = getchar();
    int x = a[i];
    while (x > 1) {
      int p = lp[x], pw = 0;
      while (x % p == 0) {
        pw++;
        x /= p;
      }
      pr[p].push_back({i, (c == '*' ? pw : -pw)});
    }
  }
  build();
  for (int i = 2; i < N; i++) {
    if (pr[i].empty()) continue;
    int m = (int)pr[i].size();
    for (int j = 1; j <= m; j++) pref[j] = pref[j - 1] + pr[i][j - 1].second;
    stack<int> st;
    st.push(m);
    for (int j = m; j >= 1; j--) {
      while (!st.empty() && pref[j - 1] <= pref[st.top()]) st.pop();
      int lim = n;
      if (!st.empty()) {
        int cur = st.top() - 1;
        lim = pr[i][cur].first - 1;
      }
      int beg = (j >= 2 ? pr[i][j - 2].first + 1 : 1);
      upd(beg, pr[i][j - 1].first, lim);
      st.push(j - 1);
    }
  }
  int mx = 0;
  while ((1 << mx) <= n) mx++;
  mx--;
  for (int j = mx; j > 0; j--) {
    for (int l = 1; l <= n - (1 << j) + 1; l++) {
      t[l][j - 1] = min(t[l][j - 1], t[l][j]);
      t[l + (1 << (j - 1))][j - 1] = min(t[l + (1 << (j - 1))][j - 1], t[l][j]);
    }
  }
  for (int i = 1; i <= n; i++) ans += t[i][0] - i + 1;
  printf("%lld", ans);
  return 0;
}
