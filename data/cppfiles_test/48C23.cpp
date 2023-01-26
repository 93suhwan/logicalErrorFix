#include <bits/stdc++.h>
using namespace std;
struct SparseTable {
  int n;
  vector<long long> a;
  vector<vector<long long>> v, m;
  void build() {
    for (int i = 0; i <= n; i++) v[i][0] = m[i][0] = a[i];
    for (int i = 1; (1 << i) <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (j - 1 + (1 << i) > n) break;
        v[j][i] = max(v[j][i - 1], v[j + (1 << (i - 1))][i - 1]);
        m[j][i] = min(m[j][i - 1], m[j + (1 << (i - 1))][i - 1]);
      }
    }
  }
  SparseTable(int n, vector<long long> &a) : n(n), a(a) {
    v.resize(n + 1, vector<long long>(25));
    m.resize(n + 1, vector<long long>(25));
    build();
  }
  long long maxi(int l, int r) {
    int lo = 31 - __builtin_clz(r - l + 1);
    return max(v[l][lo], v[r - (1 << lo) + 1][lo]);
  }
  long long mina(int l, int r) {
    int lo = 31 - __builtin_clz(r - l + 1);
    return min(m[l][lo], m[r - (1 << lo) + 1][lo]);
  }
};
void testCase() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) cin >> b[i];
  vector<long long> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i] - b[i];
  }
  SparseTable st(n, pref);
  while (q--) {
    int l, r;
    cin >> l >> r;
    long long sum = pref[r] - pref[l - 1];
    if (sum != 0 || st.maxi(l, r) - pref[l - 1] > 0) {
      cout << "-1\n";
    } else {
      cout << -st.mina(l, r) + pref[l - 1] << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  testCase();
  return 0;
}
