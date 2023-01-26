#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct vertex {
  vertex *l, *r;
  long long sum;
  vertex(long long val) : l(NULL), r(NULL), sum(val) {}
  vertex(vertex* l, vertex* r) : l(l), r(r), sum(0) {
    if (l) sum += l->sum;
    if (r) sum += r->sum;
    sum %= MOD;
  }
};
vertex* build(long long tl, long long tr) {
  if (tl == tr) return new vertex(0);
  long long tm = (tl + tr) / 2;
  return new vertex(build(tl, tm), build(tm + 1, tr));
}
long long get_sum(vertex* t, long long tl, long long tr, long long l,
                  long long r) {
  if (l > r) return 0;
  if (l == tl && tr == r) return t->sum;
  long long tm = (tl + tr) / 2;
  return (get_sum(t->l, tl, tm, l, min(r, tm)) +
          get_sum(t->r, tm + 1, tr, max(l, tm + 1), r)) %
         MOD;
}
vertex* update(vertex* t, long long tl, long long tr, long long pos,
               long long new_val) {
  if (tl == tr) return new vertex(new_val);
  long long tm = (tl + tr) / 2;
  if (pos <= tm)
    return new vertex(update(t->l, tl, tm, pos, new_val), t->r);
  else
    return new vertex(t->l, update(t->r, tm + 1, tr, pos, new_val));
}
const long long N = 2e5 + 100;
struct In {
  long long first, second, i;
  friend bool operator<(In l, In r) { return l.second < r.second; }
};
In in[N];
long long where[N];
long long s[N];
vertex* tree[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++)
    cin >> in[i].first >> in[i].second, in[i].i = i;
  sort(in + 1, in + n + 1);
  for (long long i = 1; i <= n; i++) where[in[i].i] = i, in[i].i = i;
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) cin >> s[i], s[i] = where[s[i]];
  sort(s + 1, s + t + 1);
  tree[0] = build(1, 2 * n);
  for (long long i = 1; i <= n; i++) {
    long long first = in[i].first, second = in[i].second;
    long long res = (get_sum(tree[i - 1], 1, 2 * n, first, second) + 1) % MOD;
    tree[i] = update(tree[i - 1], 1, 2 * n, first, res);
  }
  vector<In> need{in[s[t]]};
  for (long long i = t - 1; i >= 1; i--)
    if (need.back().first < in[s[i]].first &&
        in[s[i]].second < need.back().second)
      need.push_back(in[s[i]]);
  long long ans = (get_sum(tree[need[0].i - 1], 1, 2 * n, 1, 2 * n) + 1) % MOD;
  for (long long q = 0; q + 1 < need.size(); q++) {
    auto [A, B, I] = need[q];
    auto [first, second, i] = need[q + 1];
    long long cur = get_sum(tree[i - 1], 1, 2 * n, A, B);
    ans += cur + 1;
    ans %= MOD;
  }
  cout << ans;
}
