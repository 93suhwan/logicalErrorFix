#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 1e16;
vector<long long int> segtree(1e5 + 5);
void build(vector<long long int>& ar, long long int node, long long int tl,
           long long int tr) {
  if (tl == tr) {
    segtree[node] = ar[tl];
    return;
  } else {
    long long int mid = (tl + tr) / 2;
    build(ar, 2 * node, tl, mid);
    build(ar, 2 * node + 1, mid + 1, tr);
    segtree[node] = min(segtree[2 * node], segtree[2 * node + 1]);
  }
}
long long int query(long long int node, long long int tl, long long int tr,
                    long long int ql, long long int qr) {
  if (ql > qr) {
    return INF;
  } else if ((ql == tl) and (qr == tr)) {
    return segtree[node];
  } else {
    long long int mid = (tl + tr) / 2;
    long long int l = query(2 * node, tl, mid, ql, min(qr, mid));
    long long int r = query(2 * node + 1, mid + 1, tr, max(ql, mid + 1), qr);
    return min(l, r);
  }
}
void Helper(long long int n) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<long long int> c(n);
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    if (i & 1ll) {
      c[i] = -1ll * x;
    } else {
      c[i] = x;
    }
  }
  long long int cnt = 0;
  vector<long long int> pre(n);
  pre[0] = c[0];
  for (long long int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + c[i];
  }
  build(pre, 1, 0, n - 1);
  for (long long int i = 0; i < n - 1; i++) {
    if (!(i & 1ll)) cnt += min(llabs(c[i]), llabs(c[i + 1]));
  }
  for (long long int i = 1; i < n - 1; i++) {
    for (long long int j = i; j < n - 1; j++) {
      if (((i - 1) % 2 == 0) and ((j + 1) % 2 == 1)) {
        long long int segment_sum = pre[j];
        if (i >= 1) segment_sum -= pre[i - 1];
        long long int range_min = query(1, 0, n - 1, i, j);
        long long int exp_min = 0;
        if (i >= 1) exp_min = pre[i - 1];
        if (range_min >= exp_min) {
          long long int a = c[i - 1], b = llabs(c[j + 1]);
          if (segment_sum < 0) {
            if (segment_sum > a) continue;
            cnt += min(b, max(a - segment_sum, 0ll));
          } else if (segment_sum > 0) {
            if (segment_sum > b) continue;
            cnt += min(a, max(b - segment_sum, 0ll));
          } else {
            cnt += min(a, b);
          }
        } else {
          long long int a = c[i - 1], b = llabs(c[j + 1]);
          long long int mn = exp_min - range_min;
          if (segment_sum < 0) {
            if ((mn > a) or (segment_sum > a)) continue;
            cnt += min(b, max(a - mn + 1, (a - segment_sum)));
          } else if (segment_sum > 0) {
            if ((mn > a) or ((mn + segment_sum) > b)) continue;
            cnt += min(a - mn + 1, (b - (mn + segment_sum) + 1));
          } else {
            if ((mn > a) or (mn > b)) continue;
            cnt += min((a - mn + 1), (b - mn + 1));
          }
        }
      }
    }
  }
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  Helper(n);
}
