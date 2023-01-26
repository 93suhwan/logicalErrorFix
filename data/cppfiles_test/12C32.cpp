#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int maxn = 4040;
char s[maxn][maxn];
int up[maxn][maxn], down[maxn][maxn];
using ll = long long;
int head, tail;
int q[maxn];
int n, m;
void build(vector<pair<ll, ll> > &lst) {
  sort(lst.begin(), lst.end());
  head = 1, tail = 0;
  auto g = [&](int j, int i) { return lst[i].first - lst[j].first; };
  auto f = [&](int j, int i) { return lst[i].second - lst[j].second; };
  for (int i = 0; i < lst.size(); i += 1) {
    while (head < tail && f(q[tail - 1], q[tail]) * g(q[tail], i) >=
                              f(q[tail], i) * g(q[tail - 1], q[tail])) {
      tail -= 1;
    }
    q[++tail] = i;
  }
}
int res[maxn][maxn];
void solve(int dx, vector<pair<ll, ll> > &point) {
  vector<pair<ll, ll> > lst;
  for (auto [x, y] : point) {
    lst.emplace_back(y, (x - dx) * (x - dx) + y * y);
  }
  build(lst);
  auto g = [&](int j, int i) { return lst[i].first - lst[j].first; };
  auto f = [&](int j, int i) { return lst[i].second - lst[j].second; };
  for (int i = 1; i <= m; i += 1) {
    while (head < tail &&
           f(q[head], q[head + 1]) <= 2 * g(q[head], q[head + 1]) * i) {
      head += 1;
    }
    res[dx][i] = lst[q[head]].second +
                 (i - lst[q[head]].first) * (i - lst[q[head]].first) -
                 lst[q[head]].first * lst[q[head]].first;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  scanf("%d %d", &n, &m);
  n += 1;
  m += 1;
  for (int i = 1; i <= n; i += 1) {
    scanf("%s", s[i] + 1);
  }
  for (int j = 1; j <= m; j += 1) {
    int last = 0;
    for (int i = 1; i <= n; i += 1) {
      if (s[i][j] == '1') last = i;
      up[i][j] = last;
    }
    last = n + 1;
    for (int i = n; i >= 1; i -= 1) {
      if (s[i][j] == '1') last = i;
      down[i][j] = last;
    }
  }
  for (int i = 1; i <= n; i += 1) {
    vector<pair<ll, ll> > lst;
    for (int j = 1; j <= m; j += 1) {
      if (up[i][j]) lst.emplace_back(up[i][j], j);
      if (down[i][j] <= n) lst.emplace_back(down[i][j], j);
    }
    solve(i, lst);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i += 1) {
    for (int j = 1; j <= m; j += 1) {
      ans += res[i][j];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
