#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(51);
const long long N = 8e5 + 10, INF = 1e18;
long long t[4 * N];
void update(long long v, long long l, long long r, long long pos,
            long long val) {
  if (l == r) {
    t[v] = min(t[v], val);
    return;
  }
  long long m = (l + r) / 2;
  if (pos <= m) {
    update(2 * v, l, m, pos, val);
  } else {
    update(2 * v + 1, m + 1, r, pos, val);
  }
  t[v] = min(t[v * 2], t[v * 2 + 1]);
}
long long get(long long v, long long tl, long long tr, long long l,
              long long r) {
  if (l > r) return INF;
  if (tl == l && tr == r) {
    return t[v];
  }
  long long tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, min(r, tm)),
             get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> u{INF, -INF};
  vector<long long> a(n);
  vector<pair<long long, long long>> q(m);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    u.push_back(a[i]);
  }
  a.push_back(-INF);
  a.push_back(INF);
  sort(a.begin(), a.end());
  for (long long i = 0; i < m; i++) {
    cin >> q[i].first >> q[i].second;
    u.push_back(q[i].first);
    u.push_back(q[i].second);
  }
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  long long k = u.size();
  for (long long i = 0; i < k * 4; i++) {
    t[i] = INF;
  }
  for (long long i = 0; i < a.size(); i++) {
    a[i] = lower_bound(u.begin(), u.end(), a[i]) - u.begin();
  }
  for (long long i = 0; i < m; i++) {
    q[i].first = lower_bound(u.begin(), u.end(), q[i].first) - u.begin();
    q[i].second = lower_bound(u.begin(), u.end(), q[i].second) - u.begin();
    update(1, 0, k - 1, q[i].first, u[q[i].second]);
  }
  long long not_move = 0, move = 0;
  for (long long i = 0; i + 1 < a.size(); i++) {
    long long j = a[i] + 1;
    long long d = max(0ll, u[a[i + 1]] - get(1, 0, k - 1, a[i] + 1, a[i + 1]));
    long long new_not_move = min(move, not_move) + d,
              new_move = min(not_move, move) + d * 2;
    while (j <= a[i + 1]) {
      long long d = u[j] - u[a[i]];
      long long dd = max(0ll, u[a[i + 1]] - get(1, 0, k - 1, j + 1, a[i + 1]));
      new_not_move = min(new_not_move, move + d + dd);
      new_move = min(new_move, move + d + dd * 2);
      j++;
    }
    not_move = new_not_move;
    move = new_move;
  }
  cout << min(move, not_move) << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
