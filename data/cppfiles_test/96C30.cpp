#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 13;
long long f[2][N];
int n, q;
long long a[N], d[N], val[N];
void add(int t, int pos, long long x) {
  if (t == 0) {
    d[pos] += x;
  } else {
    val[pos] += x;
  }
  for (; pos < N; pos = (pos | (pos + 1))) {
    f[t][pos] += x;
  }
}
long long get(int t, int r) {
  long long res = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    res += f[t][r];
  }
  return res;
}
long long get(int t, int l, int r) {
  if (l > r) {
    return 0;
  }
  return get(t, r) - (l - 1 < 0 ? 0 : get(t, l - 1));
}
int get_pos(int k) {
  int l = -1, r = n + 2;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (get(0, m) < k) {
      l = m;
    } else {
      r = m;
    }
  }
  return r;
}
int get_l(int pos) { return get_pos(get(0, pos - 1)); }
int get_r(int pos) { return get_pos(get(0, pos) + 1); }
pair<int, int> get_lr(int pos) { return make_pair(get_l(pos), get_r(pos)); }
void upd(int pos, long long r) {
  int new_state = (r < a[pos - 1]);
  a[pos] = r;
  if (new_state == d[pos]) return;
  pair<int, int> cur = get_lr(pos);
  if (new_state && !d[pos]) {
    long long len = pos - cur.first;
    add(1, cur.first, -val[cur.first]);
    add(1, cur.first, len * (len + 1) / 2);
    len = cur.second - pos;
    add(1, pos, len * (len + 1) / 2);
    add(0, pos, 1);
  } else if (!new_state && d[pos]) {
    long long len = cur.second - cur.first;
    add(1, cur.first, -val[cur.first]);
    add(1, cur.first, len * (len + 1) / 2);
    add(1, pos, -val[pos]);
    add(0, pos, -1);
  }
}
void print() {
  for (int i = 1; i <= n; i++) {
    cout << setw(2) << i << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << setw(2) << a[i] << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << setw(2) << d[i] << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << setw(2) << val[i] << " ";
  }
  cout << endl;
}
long long get_ans(long long l, long long r) {
  int tl = get_r(l);
  int tr = get_l(r + 1);
  if (tl > tr) {
    long long len = r - l + 1;
    return len * (len + 1) / 2;
  }
  long long res = get(1, tl, tr - 1);
  long long len = tl - l;
  res += len * (len + 1) / 2;
  len = r - tr + 1;
  res += len * (len + 1) / 2;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _ = 1;
  while (_--) {
    cin >> n >> q;
    a[0] = -1;
    a[n + 1] = -1;
    add(0, 0, 1);
    add(0, n + 1, 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] < a[i - 1]) {
        add(0, i, 1);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!d[i]) continue;
      int cur = get_r(i);
      long long len = cur - i;
      add(1, i, len * (len + 1) / 2);
    }
    while (q--) {
      int t, l, r;
      cin >> t >> l >> r;
      if (t == 1) {
        upd(l, r);
        upd(l + 1, a[l + 1]);
      } else {
        cout << get_ans(l, r) << "\n";
      }
    }
  }
}
