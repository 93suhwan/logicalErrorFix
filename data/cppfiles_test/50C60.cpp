#include <bits/stdc++.h>
using namespace std;
int a[500500], n;
struct SegmentTree {
  long long w, val, lazy;
} t[2000021];
stack<int> mn;
long long dp[500500];
void pushdown(int x) {
  if (t[x].lazy) {
    t[x * 2].w = (t[x * 2].val * t[x].lazy) % 998244353;
    t[x * 2 + 1].w = (t[x * 2 + 1].val * t[x].lazy) % 998244353;
    t[x * 2].lazy = t[x].lazy, t[x * 2 + 1].lazy = t[x].lazy;
  }
}
void update(int x, int l, int r, int a, int b, long long k) {
  if (l >= a && r <= b) {
    t[x].lazy = k, t[x].w = (t[x].val * k) % 998244353;
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= a) update(x * 2, l, mid, a, b, k);
  if (mid < b) update(x * 2 + 1, mid + 1, r, a, b, k);
  t[x].w = (t[x * 2].w + t[x * 2 + 1].w) % 998244353;
  t[x].val = (t[x * 2].val + t[x * 2 + 1].val) % 998244353;
}
void insert(int x, int l, int r, int loc, long long k) {
  if (l == r) {
    t[x].val = k, t[x].w = (t[x].val * t[x].lazy) % 998244353;
    return;
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  if (mid >= loc)
    insert(x * 2, l, mid, loc, k);
  else
    insert(x * 2 + 1, mid + 1, r, loc, k);
  t[x].w = (t[x * 2].w + t[x * 2 + 1].w) % 998244353;
  t[x].val = (t[x * 2].val + t[x * 2 + 1].val) % 998244353;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  mn.push(0);
  dp[0] = 1;
  insert(1, 0, n, 0, 998244353 - dp[0]);
  for (int i = (1); i <= (n); i++) {
    while (a[mn.top()] > a[i]) mn.pop();
    update(1, 0, n, mn.top(), i - 1, a[i]);
    mn.push(i);
    dp[i] = ((i & 1) ? 998244353 - t[1].w : t[1].w) % 998244353;
    insert(1, 0, n, i, (i & 1) ? dp[i] : 998244353 - dp[i]);
  }
  cout << dp[n] << endl;
  return 0;
}
