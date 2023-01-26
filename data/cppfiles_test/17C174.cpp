#include <bits/stdc++.h>
using namespace std;
vector<long long> segTree;
int ind;
long long query(int node, int nl, int nh, int ql, int qh) {
  if (nh < ql || qh < nl) return 0;
  if (ql <= nl && nh <= qh) return segTree[node];
  int mid = nl + (nh - nl) / 2;
  return query(2 * node, nl, mid, ql, qh) +
         query(2 * node + 1, mid + 1, nh, ql, qh);
}
void update(int pos) {
  segTree[ind + pos]++;
  for (int i = (ind + pos) / 2; i >= 1; i /= 2) {
    segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ind = 1;
  map<int, int> pos;
  vector<int> b = a;
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    if (pos[b[i]] == 0) {
      pos[b[i]] = ind++;
    }
  }
  ind++;
  while (__builtin_popcount(ind) != 1) ind++;
  segTree.assign(2 * ind, 0);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x = pos[a[i]];
    long long l = query(1, 0, ind - 1, 0, x - 1);
    long long r = query(1, 0, ind - 1, x + 1, ind - 1);
    ans += min(l, r);
    update(x);
  }
  cout << ans << "\n";
}
int main(void) {
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
