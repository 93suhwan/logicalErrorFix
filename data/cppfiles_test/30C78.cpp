#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 13, M = 1e6 + 13;
long long p[N], d[N], who[M], a[N], f[M], n, q;
void build() {
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    d[i] = who[i] = 0;
  }
  for (int i = 2; i < M; i++) {
    if (!f[i]) {
      for (int j = i; j < M; j += i) {
        f[j] = i;
      }
    }
  }
}
long long get_par(long long x) {
  if (p[x] == x) {
    return x;
  }
  return p[x] = get_par(p[x]);
}
void unite(long long x, long long y) {
  x = get_par(x);
  y = get_par(y);
  if (x != y) {
    if (d[x] > d[y]) {
      swap(x, y);
    }
    p[x] = y;
    if (d[x] == d[y]) {
      d[y]++;
    }
  }
}
void add(int pos) {
  long long cur = a[pos];
  while (cur != 1) {
    int x = f[cur];
    if (!who[x]) {
      who[x] = pos;
    } else {
      unite(pos, who[x]);
    }
    while (cur % x == 0) {
      cur /= x;
    }
  }
}
int used[N];
int t = 1;
int cur[N], it = 0;
set<int> s[N];
void upd(int pos) {
  long long val = a[pos] + 1;
  it = 1;
  cur[0] = get_par(pos);
  used[get_par(pos)] = t;
  while (val != 1) {
    int x = f[val];
    if (used[get_par(who[x])] != t) {
      used[get_par(who[x])] = t;
      cur[it++] = get_par(who[x]);
    }
    while (val % x == 0) {
      val /= x;
    }
  }
  for (int i = 0; i < it; i++) {
    for (int j = 0; j < it; j++) {
      s[cur[i]].insert(cur[j]);
    }
  }
  t++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _ = 1;
  while (_--) {
    cin >> n >> q;
    build();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      add(i);
    }
    for (int i = 1; i <= n; i++) {
      upd(i);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      if (get_par(l) == get_par(r)) {
        cout << 0 << endl;
      } else if (s[get_par(l)].count(get_par(r))) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}
