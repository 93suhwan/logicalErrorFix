#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int n, a[N + 9];
char s[N + 9];
void into() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%s", s + 1);
}
struct factor {
  int x, c;
  factor(int X = 0, int C = 0) : x(X), c(C) {}
};
vector<factor> d[N + 9];
void Get_d() {
  for (int i = 2; i <= N; ++i) {
    if (!d[i].empty()) continue;
    for (int j = i; j <= N; j += i) {
      int t = j, c = 0;
      for (; t % i == 0; t /= i) ++c;
      d[j].emplace_back(i, c);
    }
  }
}
int uni[N + 9];
int Query_uni(int k) { return k == uni[k] ? k : uni[k] = Query_uni(uni[k]); }
struct state {
  int l, r, v;
  state(int L = 0, int R = 0, int V = 0) : l(L), r(R), v(V) {}
  bool operator<(const state &p) const { return v < p.v; }
};
priority_queue<state> q[N + 9];
int last[N + 9], cnt[N + 9];
long long ans;
void Get_ans() {
  for (int i = 0; i <= n; ++i) uni[i] = i;
  for (int i = 1, now = 0; i <= n; ++i) {
    ++now;
    for (auto [x, c] : d[a[i]]) {
      q[x].emplace(last[x] + 1, i, cnt[x]);
      cnt[x] += (s[i] == '*' ? 1 : -1) * c;
      last[x] = i;
      for (; !q[x].empty() && q[x].top().v > cnt[x];) {
        auto [l, r, rub] = q[x].top();
        q[x].pop();
        for (int i = Query_uni(r); i >= l; uni[i] = i - 1, i = Query_uni(i))
          --now;
      }
    }
    if (s[i] == '/' && a[i] > 1 && uni[i] == i) uni[i] = i - 1, --now;
    ans += now;
  }
}
void work() {
  Get_d();
  Get_ans();
}
void outo() { printf("%lld\n", ans); }
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
