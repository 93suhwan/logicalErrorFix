#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long inf = 1e9 + 228;
const long long infll = 1e18;
const long long mod = 1e9 + 7;
const long double eps = 1e-5;
const long long mod2 = 998244353;
const long double PI = atan2l(0, -1);
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int buben = 300;
const int maxn = 2e5 + 228;
int ans[maxn];
int lol[3001][3001];
void add(int l, int r, int x) {
  ans[l] += x;
  ans[r + 1] -= x;
}
void build() {
  for (int i = 1; i < maxn; i++) ans[i] += ans[i - 1];
}
void add2(int i, int a, int b) {
  int cur = i + a;
  cur %= a + b;
  for (int j = 0; j < b; j++) {
    lol[a + b][cur]++;
    cur++;
    if (cur >= a + b) cur -= a + b;
  }
}
void del(int i, int a, int b) {
  int cur = i + a;
  cur %= a + b;
  for (int j = 0; j < b; j++) {
    lol[a + b][cur]--;
    cur++;
    if (cur >= a + b) cur -= a + b;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > kek(n);
  vector<vector<int> > seg(n);
  for (pair<int, int> &i : kek) {
    cin >> i.first >> i.second;
  }
  vector<pair<int, int> > st(m);
  for (int i = 0; i < m; i++) {
    int t, k;
    cin >> t >> k;
    k--;
    st[i] = make_pair(t, k);
    seg[k].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (seg[i].size() & 1) {
      seg[i].push_back(m);
    }
  }
  for (int i = 0; i < n; i++) {
    if (kek[i].first + kek[i].second >= buben) {
      for (int j = 0; j < seg[i].size(); j += 2) {
        for (int l = seg[i][j] + kek[i].first; l < seg[i][j + 1];
             l += kek[i].first + kek[i].second) {
          add(l, min(seg[i][j + 1] - 1, l + kek[i].second - 1), 1);
        }
      }
    }
  }
  vector<int> lst_open(n);
  for (int i = 0; i < m; i++) {
    if (kek[st[i].second].first + kek[st[i].second].second < buben) {
      if (st[i].first == 1) {
        lst_open[st[i].second] = i;
        add2(i, kek[st[i].second].first, kek[st[i].second].second);
      } else {
        del(lst_open[st[i].second], kek[st[i].second].first,
            kek[st[i].second].second);
      }
    }
    for (int j = 1; j <= buben; j++) {
      add(i, i, lol[j][i % j]);
    }
  }
  build();
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}
signed main() {
  fast_io();
  int q = 1;
  while (q--) solve();
  return 0;
}
