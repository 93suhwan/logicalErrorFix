#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, q, ps[MAXN];
vector<int> ans[MAXN];
char s[MAXN];
struct Query {
  int l, r, idx;
  bool operator<(const Query &rhs) const { return r < rhs.r; }
};
void solve() {
  cin >> n >> q >> (s + 1);
  for (int i = (1); i <= (n); ++i) {
    ps[i] = s[i] == '+' ? 1 : -1;
    if ((i & 1) == 0) ps[i] = -ps[i];
    ps[i] += ps[i - 1];
  }
  vector<Query> qs(q + 1);
  for (int i = (1); i <= (q); ++i) {
    cin >> qs[i].l >> qs[i].r;
    qs[i].idx = i;
    ans[i].clear();
  }
  sort(qs.begin() + 1, qs.end());
  unordered_map<int, int> last;
  int cr = 1;
  last[ps[cr] + ps[cr - 1]] = cr;
  for (auto &q : qs) {
    while (cr < q.r) {
      ++cr;
      last[ps[cr] + ps[cr - 1]] = cr;
    }
    if (ps[q.r] - ps[q.l - 1] == 0) {
      continue;
    }
    if ((q.r - q.l + 1) & 1) {
      if (last.count(ps[q.r] + ps[q.l - 1])) {
        int p = last[ps[q.r] + ps[q.l - 1]];
        if (p >= q.l) {
          ans[q.idx].push_back(p);
        }
      }
      continue;
    }
    if (!((q.r - q.l + 1) & 1)) {
      ans[q.idx].push_back(q.r);
      if (last.count(ps[q.r - 1] + ps[q.l - 1])) {
        int p = last[ps[q.r - 1] + ps[q.l - 1]];
        if (p >= q.l && p < q.r) {
          ans[q.idx].push_back(p);
        }
      }
      continue;
    }
  }
  for (int i = (1); i <= (q); ++i) {
    cout << ans[i].size() << '\n';
    if (!ans[i].empty()) {
      for (auto x : ans[i]) cout << x << ' ';
      cout << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
