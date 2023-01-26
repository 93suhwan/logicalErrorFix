#include <bits/stdc++.h>
using namespace std;
struct Comparator {
  bool operator()(const pair<long long, long long>& lhs,
                  const pair<long long, long long>& rhs) const {
    if (lhs.first == rhs.first) return lhs.second < rhs.second;
    return lhs.first < rhs.first;
  }
  bool operator()(long long a, long long b) const { return a > b; }
};
struct streeMin {
  long long n;
  vector<long long> tree;
  vector<long long> pushMem;
  const long long inf = 9999999999999999;
  streeMin(long long n) { tree.resize(4 * n); }
  void build(vector<long long>& arr, long long v = 0, long long l = 0,
             long long r = -1) {
    if (r == -1) r = arr.size() - 1;
    if (l == r) {
      tree[v] = arr[l];
      return;
    }
    long long mid = (l + r) / 2;
    build(arr, 2 * v + 1, l, mid);
    build(arr, 2 * v + 2, mid + 1, r);
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
  }
  void push(long long v, long long l, long long r) {
    tree[2 * v + 1] += pushMem[v];
    tree[2 * v + 2] += pushMem[v];
    pushMem[2 * v + 1] += pushMem[v];
    pushMem[2 * v + 2] += pushMem[v];
    pushMem[v] = 0;
  }
  void change(long long l, long long r, long long val, long long v = 0,
              long long vL = 0, long long vR = -1) {
    if (vR == -1) vR = tree.size() / 4 - 1;
    if (vR < l || vL > r) return;
    if (vL >= l && vR <= r) {
      tree[v] += val;
      pushMem[v] += val;
      return;
    }
    long long mid = (vL + vR) / 2;
    change(l, r, val, 2 * v + 1, vL, mid);
    change(l, r, val, 2 * v + 2, mid + 1, vR);
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
  }
  long long get(long long l, long long r, long long v = 0, long long vL = 0,
                long long vR = -1) {
    if (vR == -1) vR = tree.size() / 4 - 1;
    if (vR < l || vL > r) return inf;
    if (vL >= l && vR <= r) {
      return tree[v];
    }
    long long mid = (vL + vR) / 2;
    return min(get(l, r, 2 * v + 1, vL, mid),
               get(l, r, 2 * v + 2, mid + 1, vR));
  }
};
struct streeMax {
  long long n;
  vector<long long> tree;
  vector<long long> pushMem;
  const long long inf = 99999999999999999;
  streeMax(long long n) { tree.resize(4 * n); }
  void build(vector<long long>& arr, long long v = 0, long long l = 0,
             long long r = -1) {
    if (r == -1) r = arr.size() - 1;
    if (l == r) {
      tree[v] = arr[l];
      return;
    }
    long long mid = (l + r) / 2;
    build(arr, 2 * v + 1, l, mid);
    build(arr, 2 * v + 2, mid + 1, r);
    tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
  }
  void push(long long v, long long l, long long r) {
    tree[2 * v + 1] += pushMem[v];
    tree[2 * v + 2] += pushMem[v];
    pushMem[2 * v + 1] += pushMem[v];
    pushMem[2 * v + 2] += pushMem[v];
    pushMem[v] = 0;
  }
  void change(long long l, long long r, long long val, long long v = 0,
              long long vL = 0, long long vR = -1) {
    if (vR == -1) vR = tree.size() / 4 - 1;
    if (vR < l || vL > r) return;
    if (vL >= l && vR <= r) {
      tree[v] += val;
      pushMem[v] += val;
      return;
    }
    long long mid = (vL + vR) / 2;
    change(l, r, val, 2 * v + 1, vL, mid);
    change(l, r, val, 2 * v + 2, mid + 1, vR);
    tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
  }
  long long get(long long l, long long r, long long v = 0, long long vL = 0,
                long long vR = -1) {
    if (vR == -1) vR = tree.size() / 4 - 1;
    if (vR < l || vL > r) return -inf;
    if (vL >= l && vR <= r) {
      return tree[v];
    }
    long long mid = (vL + vR) / 2;
    return max(get(l, r, 2 * v + 1, vL, mid),
               get(l, r, 2 * v + 2, mid + 1, vR));
  }
};
void solve() {
  long long n, q;
  cin >> n >> q;
  streeMax sMax(n + 1);
  streeMin sMin(n + 1);
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  vector<long long> sum(n + 1);
  sum[0] = 0;
  for (long long i = 0; i < n; i++) {
    long long t;
    cin >> t;
    sum[i + 1] = arr[i] - t + sum[i];
  }
  sMax.build(sum);
  sMin.build(sum);
  while (q--) {
    long long l, r;
    cin >> l >> r;
    l--, r--;
    if (sum[l] != sum[r + 1]) {
      cout << "-1\n";
      continue;
    }
    if (sMax.get(l, r) > sum[l]) {
      cout << "-1\n";
      continue;
    }
    cout << sum[l] - sMin.get(l, r) << '\n';
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  solve();
  return 0;
}
