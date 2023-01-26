#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct SGT {
  int n;
  struct node {
    long long sum;
    long long ccd[3];
    long long prem;
  } t[4 * MAXN];
  node unite(const node &a, const node &b) {
    node res;
    res.sum = a.sum + b.sum;
    res.ccd[0] = a.ccd[0];
    res.ccd[2] = b.ccd[2];
    res.ccd[1] = a.ccd[1];
    if (abs(b.ccd[1]) > abs(res.ccd[1])) res.ccd[1] = b.ccd[1];
    if (a.ccd[2] * b.ccd[0] > 0) {
      if (abs(res.ccd[1]) < abs(a.ccd[2] + b.ccd[0]))
        res.ccd[1] = a.ccd[2] + b.ccd[0];
    }
    res.prem = min(a.prem, a.sum + b.prem);
    return res;
  }
  void pull(int idx) { t[idx] = unite(t[idx << 1], t[idx << 1 | 1]); }
  void init(vector<int> &A, int l, int r, int idx) {
    if (l == r) {
      t[idx] = {A[l], A[l], A[l], A[l], max(0, A[l])};
      return;
    }
    int mid = (l + r) >> 1;
    init(A, l, mid, idx << 1);
    init(A, mid + 1, r, idx << 1 | 1);
    pull(idx);
  }
  node query(int ql, int qr, int l, int r, int idx) {
    if (ql <= l && r <= qr) return t[idx];
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(ql, qr, l, mid, idx << 1);
    if (ql > mid) return query(ql, qr, mid + 1, r, idx << 1 | 1);
    return unite(query(ql, qr, l, mid, idx << 1),
                 query(ql, qr, mid + 1, r, idx << 1 | 1));
  }
} T1;
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> A(n + 1), B(n + 1), C(n + 1);
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> B[i];
  for (int i = 1; i <= n; i++) C[i] = A[i] - B[i];
  T1.init(C, 1, n, 1);
  while (q--) {
    int ql, qr;
    cin >> ql >> qr;
    auto v = T1.query(ql, qr, 1, n, 1);
    if (v.sum == 0 && abs(v.prem) >= abs(v.ccd[1]))
      cout << abs(v.ccd[1]) << endl;
    else
      cout << -1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
