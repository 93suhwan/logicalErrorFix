#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
const long long mod = 998244353;
const long long MAXL = 60;
long long n;
long long a[N], dp[N];
struct ty {
  long long f, sum;
  long long lz;
} tr[N << 2];
vector<long long> st;
void pushup(long long p, long long l, long long r) {
  tr[p].sum = (tr[p << 1].sum + tr[p << 1 | 1].sum) % mod;
  tr[p].f = (tr[p << 1].f + tr[p << 1 | 1].f) % mod;
}
void pushdown(long long p, long long l, long long r) {
  long long x = tr[p].lz;
  tr[p].lz = 0;
  tr[p << 1].lz = tr[p << 1 | 1].lz = x;
  tr[p << 1].f = tr[p << 1].sum * x % mod;
  tr[p << 1 | 1].f = tr[p << 1 | 1].sum * x % mod;
}
void insert(long long p, long long l, long long r, long long pos,
            long long val) {
  if (l == r) {
    tr[p].f = val * tr[p].lz % mod;
    tr[p].sum = val;
    return;
  }
  if (tr[p].lz) pushdown(p, l, r);
  long long mid = (l + r) >> 1;
  if (pos <= mid)
    insert(p << 1, l, mid, pos, val);
  else
    insert(p << 1 | 1, mid + 1, r, pos, val);
  pushup(p, l, r);
}
void change(long long p, long long l, long long r, long long x, long long y,
            long long val) {
  if (x <= l && r <= y) {
    tr[p].lz = val;
    tr[p].f = tr[p].sum * val % mod;
    return;
  }
  if (tr[p].lz) pushdown(p, l, r);
  long long mid = (l + r) >> 1;
  if (y <= mid)
    change(p << 1, l, mid, x, y, val);
  else if (x >= mid + 1)
    change(p << 1 | 1, mid + 1, r, x, y, val);
  else {
    change(p << 1, l, mid, x, mid, val),
        change(p << 1 | 1, mid + 1, r, mid + 1, y, val);
  }
  pushup(p, l, r);
}
void de() {
  cout << " de " << endl;
  for (long long i = (1); i <= (n); i++) cout << dp[i] << " ";
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  insert(1, 1, n, 1, 1);
  for (long long i = (1); i <= (n); i++) {
    while (!st.empty() && a[i] < a[st.back()]) st.pop_back();
    long long x = (st.empty()) ? 1 : st.back() + 1;
    st.push_back(i);
    change(1, 1, n, x, i, a[i]);
    dp[i] = ((i & 1) ? tr[1].f : (mod - tr[1].f) % mod);
    if (i < n) insert(1, 1, n, i + 1, (i & 1) ? (mod - dp[i]) % mod : dp[i]);
  }
  cout << dp[n] << endl;
  return 0;
}
