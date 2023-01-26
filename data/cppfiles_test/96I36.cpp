#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 2e5;
int a[N + 1], len[N + 1];
int n, q;
set<int> s;
ll bit[N + 1];
void update(int i, ll x) {
  for (; i <= n; i += i & -i) bit[i] += x;
}
ll get(int i) {
  ll res = 0;
  for (; i; i -= i & -i) res += bit[i];
  return res;
}
ll calc(ll x) { return x * (x + 1) / 2; }
ll query(int l, int r) {
  ll res = get(r) - get(l - 1);
  int u = *s.lower_bound(l);
  res -= calc(len[u]);
  res += calc(u - l + 1);
  int v = *(--s.upper_bound(r)) + 1;
  res += calc(r - v + 1);
  return res;
}
void erase(int i) {
  auto u = s.lower_bound(i);
  int r = *u, l = *(--u) + 1;
  if (l == r) {
    update(r, -calc(len[r]));
    len[r] = 0;
    s.erase(r);
  } else if (i == l) {
    update(r, -calc(len[r]));
    len[r] = len[r] - 1;
    update(r, calc(len[r]));
  } else if (i == r) {
    update(r, -calc(len[r]));
    len[r - 1] = len[r] - 1;
    update(r - 1, calc(len[r - 1]));
    len[r] = 0;
    s.erase(r);
    s.insert(r - 1);
  } else {
    update(r, -calc(len[r]));
    len[r] -= i - l;
    update(r, calc(len[r]));
    len[i - 1] = i - l;
    update(i - 1, calc(len[i - 1]));
    s.insert(i - 1);
  }
}
void insert(int i, int x) {
  a[i] = x;
  if (a[i - 1] <= a[i] && a[i] <= a[i + 1]) {
    auto u = s.upper_bound(i);
    int r = *u;
    update(r, -calc(len[r]));
    len[r] = len[r] + len[i - 1] + 1;
    update(r, calc(len[r]));
    update(i - 1, -calc(len[i - 1]));
    len[i - 1] = 0;
    s.erase(i - 1);
  } else if (a[i - 1] <= a[i] && a[i] > a[i + 1]) {
    len[i] = len[i - 1] + 1;
    update(i, calc(len[i]));
    s.insert(i);
    update(i - 1, -calc(len[i - 1]));
    len[i - 1] = 0;
    s.erase(i - 1);
  } else if (a[i - 1] > a[i] && a[i] <= a[i + 1]) {
    auto u = s.upper_bound(i);
    int r = *u;
    update(r, -calc(len[r]));
    len[r] = len[r] + 1;
    update(r, calc(len[r]));
  } else {
    len[i] = 1;
    update(i, calc(len[i]));
    s.insert(i);
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  int l, r, t, i, x;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  a[0] = oo;
  a[n + 1] = -oo;
  s.insert(0);
  for (int i = 2; i <= n + 1; ++i)
    if (a[i] < a[i - 1]) {
      l = *s.rbegin() + 1, r = i - 1;
      s.insert(r);
      len[r] = r - l + 1;
      update(r, calc(len[r]));
    }
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> i >> x;
      erase(i);
      insert(i, x);
    } else {
      cin >> l >> r;
      cout << query(l, r) << '\n';
    }
  }
  return 0;
}
