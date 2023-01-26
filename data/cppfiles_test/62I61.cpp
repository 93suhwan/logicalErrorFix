#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
int n, m, q;
int sz[N + 2];
int off[N + 2][N + 2];
set<pair<int, int> > st[N + 2];
vector<pair<int, int> > lab[N + 2][N + 2];
bool valid(int r, int c) { return 1 <= r && r <= n && 1 <= c && c <= m; }
int get(int x) { return x * (x + 1) / 2; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    int r = i, c = 1;
    for (int j = 1; valid(r, c); j++) {
      sz[i]++;
      lab[r][c].push_back({i, j});
      r += j & 1, c += j & 1 ^ 1;
    }
    ans += get(sz[i]);
    st[i].insert({1, sz[i]});
  }
  for (int i = 1; i <= m - 1; i++) {
    int r = 1, c = i;
    for (int j = 1; valid(r, c); j++) {
      sz[n + i]++;
      lab[r][c].push_back({n + i, j});
      r += j & 1 ^ 1, c += j & 1;
    }
    ans += get(sz[n + i]);
    st[n + i].insert({1, sz[n + i]});
  }
  int on = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      on += (lab[i][j].size() == 2);
    }
  }
  while (q--) {
    int r, c;
    cin >> r >> c;
    for (auto i : lab[r][c]) {
      int str = i.first, idx = i.second;
      if (!off[r][c]) {
        auto it = st[str].lower_bound({idx + 1, 0});
        it--;
        int l = it->first, r = it->second;
        ans -= get(r - l + 1);
        st[str].erase(it);
        if (l <= idx - 1) {
          ans += get(idx - l);
          st[str].insert({l, idx - 1});
        }
        if (idx + 1 <= r) {
          ans += get(r - idx);
          st[str].insert({idx + 1, r});
        }
      } else {
        int a, b, c, d, l, r;
        a = b = c = d = -1;
        l = r = idx;
        auto rg = st[str].lower_bound({idx, 0});
        auto lf = rg;
        if (rg != st[str].end()) c = rg->first, d = rg->second;
        if (rg != st[str].begin()) {
          lf = --rg;
          rg++;
          a = lf->first, b = lf->second;
        }
        if (b + 1 == idx) {
          ans -= get(b - a + 1);
          st[str].erase(lf);
          l = a;
        }
        if (c - 1 == idx) {
          ans -= get(d - c + 1);
          st[str].erase(rg);
          r = d;
        }
        ans += get(r - l + 1);
        st[str].insert({l, r});
      }
    }
    off[r][c] ^= 1;
    if (lab[r][c].size() == 2) {
      if (off[r][c])
        on--;
      else
        on++;
    }
    cout << ans - on << '\n';
  }
  return 0;
}
