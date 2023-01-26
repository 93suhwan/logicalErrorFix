#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 10;
const long long LOG = 22;
const long long INF = 8e18;
const long long MOD = 1e9 + 7;
int n, A[MAXN], B[MAXN], dp[MAXN], par[MAXN];
pair<int, int> seg[MAXN << 2];
void modify(int pos, int val, int id = 1, int l = 0, int r = n + 1) {
  if (r - l == 1) {
    seg[id] = {val, pos};
    return;
  }
  int mid = l + r >> 1;
  if (pos < mid)
    modify(pos, val, id << 1, l, mid);
  else
    modify(pos, val, id << 1 | 1, mid, r);
  seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}
pair<int, int> get(int ql, int qr, int id = 1, int l = 0, int r = n + 1) {
  if (qr <= l || r <= ql) return {MOD, MOD};
  if (ql <= l && r <= qr) return seg[id];
  int mid = l + r >> 1;
  return min(get(ql, qr, id << 1, l, mid), get(ql, qr, id << 1 | 1, mid, r));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> B[i];
    A[i] = A[i + B[i]] - B[i];
  }
  for (int i = 1; i <= n; i++) {
    pair<int, int> res = get(i - A[i], i);
    dp[i] = res.first + 1;
    par[i] = res.second;
    modify(i, dp[i]);
  }
  if (dp[n] >= MOD) {
    return cout << -1 << '\n', 0;
  }
  vector<int> ans;
  int cur = n;
  while (cur) {
    cur = par[cur];
    ans.push_back(cur);
  }
  cout << dp[n] << '\n';
  for (int i : ans) {
    cout << i << ' ';
  }
  return 0;
}
