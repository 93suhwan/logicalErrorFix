#include <bits/stdc++.h>
long long n, k, m;
std::vector<long long> a[15];
struct dwd {
  long long a, x, y;
  dwd(long long _a, long long _x, long long _y) { a = _a, x = _x, y = _y; }
  bool operator<(dwd b) const { return a > b.a; }
};
struct twt {
  std::vector<long long> b;
  long long val;
  void push(long long x) {
    long long now = b.size();
    b.push_back(x), val += a[now + 1][x];
  }
  twt(long long x) {
    val = 0;
    b.clear();
    push(x);
  }
  twt() {
    b.clear();
    val = 0;
  }
  bool operator<(const twt &z) const {
    if (val != z.val)
      return val > z.val;
    else
      return b < z.b;
  }
  bool operator!=(const twt &z) {
    for (long long i = 0; i < n; i++)
      if (b[i] != z.b[i]) return true;
    return false;
  }
  void print() {
    for (long long i = 0; i < (long long)b.size(); i++)
      std::cout << a[i + 1][0] - b[i] + 1 << ' ';
  }
};
std::vector<twt> s, tmp, fo;
std::set<dwd> t;
void merge(long long q) {
  t.clear(), tmp.clear();
  t.insert(dwd(s[0].val + a[q][1], 0, 1));
  while (tmp.size() <= m + 1 && !t.empty()) {
    long long i = t.begin()->x, j = t.begin()->y;
    t.erase(t.begin());
    twt cur = s[i];
    cur.push(j);
    tmp.push_back(cur);
    if (i + 1 < (long long)s.size())
      t.insert(dwd(s[i + 1].val + a[q][j], i + 1, j));
    if (j + 1 <= a[q][0]) t.insert(dwd(s[i].val + a[q][j + 1], i, j + 1));
  }
  s = tmp;
}
signed main() {
  std::cin >> n;
  for (long long i = 1; i <= n; i++) {
    std::cin >> k;
    a[i].resize(k + 1), a[i][0] = k;
    for (long long j = 1; j <= k; j++) std::cin >> a[i][j];
    std::sort(std::next(a[i].begin()), a[i].end(), std::greater<long long>());
  }
  std::cin >> m;
  for (long long i = 1; i <= a[1][0]; i++) s.push_back(twt(i));
  std::sort(s.begin(), s.end());
  for (long long i = 2; i <= n; i++) {
    merge(i);
  }
  for (long long i = 1; i <= m; i++) {
    twt cur;
    for (long long j = 1; j <= n; j++) std::cin >> k, cur.push(a[j][0] - k + 1);
    fo.push_back(cur);
  }
  std::sort(fo.begin(), fo.end());
  long long j = 0;
  for (auto cur : s) {
    if (j >= (long long)fo.size() || cur != fo[j]) return cur.print(), 0;
    j++;
  }
}
