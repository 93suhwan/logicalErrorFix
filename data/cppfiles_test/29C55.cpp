#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
bool chmin(A& a, B b) {
  return b < a ? a = b, true : false;
}
template <typename A, typename B>
bool chmax(A& a, B b) {
  return b > a ? a = b, true : false;
}
const int inf = 1e09 + 5e3;
const long long linf = 2e18 + 5e3;
const int mod = 1e9 + 7;
const int mxn = 2e4 + 30;
struct fenwickTree {
  long long n;
  vector<long long> ft;
  fenwickTree(long long z) {
    ft.resize(z + 1);
    n = z;
  }
  void updateSum(long long idx, long long k) {
    while (idx <= n) {
      ft[idx] += k;
      idx += (idx & (-1 * idx));
    }
  }
  long long querySum(long long idx) {
    long long sum = 0;
    while (idx > 0) {
      sum += ft[idx];
      idx -= (idx & (-1 * idx));
    }
    return sum;
  }
  long long query(long long l, long long r) {
    return querySum(r) - querySum(l - 1);
  }
};
struct segmentTree {
  vector<long long> sTree, lazy;
  long long N;
  segmentTree(long long n) {
    N = 1;
    while (N < n) {
      N <<= 1;
    }
    sTree.resize(N << 1);
    lazy.resize(N << 1);
  }
  long long query(long long left, long long right) {
    return query(1, 1, N, left, right);
  }
  long long query(long long node, long long curLeft, long long curRight,
                  long long left, long long right) {
    if (curLeft > right || curRight < left) return 0;
    if (curLeft >= left && curRight <= right) {
      return sTree[node];
    }
    long long mid = (curLeft + curRight) >> 1;
    long long leftChild = node << 1, rightChild = node << 1 | 1;
    propagate(node, curLeft, mid, curRight);
    long long q1 = query(leftChild, curLeft, mid, left, right);
    long long q2 = query(rightChild, mid + 1, curRight, left, right);
    return q1 + q2;
  }
  long long query_poll(long long i) { return query_poll(1, 1, N, i); }
  long long query_poll(long long node, long long curLeft, long long curRight,
                       long long idx) {
    if (curLeft == curRight) {
      return sTree[node];
    }
    long long mid = (curLeft + curRight) >> 1;
    long long leftChild = node << 1, rightChild = node << 1 | 1;
    propagate(node, curLeft, mid, curRight);
    if (idx <= mid) {
      return query_poll(leftChild, curLeft, mid, idx);
    }
    return query_poll(rightChild, mid + 1, curRight, idx);
  }
  void update_range(long long i, long long j, long long val) {
    update_range(1, 1, N, i, j, val);
  }
  void update_range(long long node, long long curLeft, long long curRight,
                    long long left, long long right, long long val) {
    if (curLeft > right || curRight < left) return;
    if (curLeft >= left && curRight <= right) {
      sTree[node] += (curRight - curLeft + 1) * val;
      lazy[node] += val;
      return;
    }
    long long mid = (curLeft + curRight) >> 1;
    long long leftChild = node << 1, rightChild = node << 1 | 1;
    propagate(node, curLeft, mid, curRight);
    update_range(leftChild, curLeft, mid, left, right, val);
    update_range(rightChild, mid + 1, curRight, left, right, val);
    sTree[node] = sTree[leftChild] + sTree[rightChild];
  }
  void update_Poll(long long i, long long val) { update_Poll(1, 1, N, i, val); }
  void update_Poll(long long node, long long curLeft, long long curRight,
                   long long idx, long long val) {
    if (curLeft == curRight) {
      sTree[node] = val;
      lazy[node] = val;
      return;
    }
    long long mid = (curLeft + curRight) >> 1;
    long long leftChild = node << 1, rightChild = node << 1 | 1;
    propagate(node, curLeft, mid, curRight);
    if (idx <= mid)
      update_Poll(leftChild, curLeft, mid, idx, val);
    else
      update_Poll(rightChild, mid + 1, curRight, idx, val);
    sTree[node] = sTree[leftChild] + sTree[rightChild];
  }
  void propagate(long long node, long long b, long long mid, long long e) {
    lazy[node << 1] += lazy[node];
    lazy[node << 1 | 1] += lazy[node];
    sTree[node << 1] += (mid - b + 1) * lazy[node];
    sTree[node << 1 | 1] += (e - mid) * lazy[node];
    lazy[node] = 0;
  }
};
void solve() {
  long long n;
  cin >> n;
  long long in[n];
  for (long long i = 0; i < n; i++) cin >> in[i];
  long long maxn = 300000;
  fenwickTree ft(maxn + 1);
  fenwickTree vals(maxn + 1);
  vector<long long> ans(n);
  ft.updateSum(in[0], 1);
  vals.updateSum(in[0], in[0]);
  for (long long i = 1; i < n; i++) {
    for (long long j = 0, mul = 0; j <= maxn; mul++) {
      long long nxt = min(j + in[i] - 1, maxn);
      ans[i] += (vals.query(j, nxt) - mul * 1ll * ft.query(j, nxt) * in[i]);
      j = nxt + 1;
    }
    ft.updateSum(in[i], 1);
    vals.updateSum(in[i], in[i]);
  }
  segmentTree st(maxn + 1);
  segmentTree stvals(maxn + 1);
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = 0, mul = 0; j <= maxn; mul++) {
      long long nxt = min(j + in[i] - 1, maxn);
      st.update_range(j == 0 ? 1 : j, nxt, 1);
      stvals.update_range(j == 0 ? 1 : j, nxt, in[i] * 1ll * mul);
      j = nxt + 1;
    }
    st.update_Poll(in[i], 0);
    stvals.update_Poll(in[i], 0);
  }
  for (long long i = 0; i < n; i++) {
    ans[i] += (st.query_poll(in[i]) * 1ll * in[i] - stvals.query_poll(in[i]));
    if (i > 0) ans[i] += ans[i - 1];
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
}
