#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5011;
int n, lcp[N][N];
string s;
struct Seg {
  int l, r;
  bool operator<(const Seg& o) const {
    int x = lcp[l][o.l];
    if (r < l + x || o.r < o.l + x) return r - l < o.r - o.l;
    return s[l + x] < s[o.l + x];
  }
};
void work() {
  cin >> n >> s;
  if (n < 0) {
    n = 4000;
    s = "";
    for (int i = 0; i < n; ++i) s += 'a' + rand() % 26;
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) lcp[i][j] = 0;
  for (int i = n - 1; i >= 0; --i)
    for (int j = 0; j < n; ++j)
      lcp[i][j] = (s[i] == s[j]) ? lcp[i + 1][j + 1] + 1 : 0;
  vector<Seg> f;
  for (int i = 0; i < n; ++i) {
    Seg mx{i, n};
    int ir = lower_bound(f.begin(), f.end(), mx) - f.begin();
    if (ir == f.size()) {
      f.push_back(mx);
    } else {
      f[ir] = mx;
    }
    int il = 0;
    for (int j = i; j < n; ++j) {
      Seg cur{i, j};
      if (il < ir)
        il = lower_bound(f.begin() + il, f.begin() + ir, cur) - f.begin();
      if (il == f.size())
        f.push_back(cur);
      else
        f[il] = cur;
      ++il;
    }
  }
  cout << f.size() << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) work();
}
