#include <bits/stdc++.h>
using namespace std;
struct seg {
  int size = 1;
  vector<long long> sums;
  void init(int a) {
    size = 1;
    while (size < a) size *= 2;
    sums.assign(2 * size, 0LL);
  }
  void addval(int a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      sums[x] = 1;
      return;
    }
    int m = (rx + lx) / 2;
    if (a < m) {
      addval(a, 2 * x + 1, lx, m);
    } else {
      addval(a, 2 * x + 2, m, rx);
    }
    sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
  }
  void addval(int pos) { addval(pos, 0, 0, size); }
  long long getsum(int a, int b, int x, int lx, int rx) {
    if (lx >= b || a >= rx) return 0LL;
    if (lx >= a && rx <= b) return sums[x];
    int m = (rx + lx) / 2;
    long long s1 = getsum(a, b, 2 * x + 1, lx, m);
    long long s2 = getsum(a, b, 2 * x + 2, m, rx);
    return s1 + s2;
  }
  long long getsum(int a, int b) { return getsum(a, b, 0, 0, size); }
};
int arr[310];
pair<int, int> sorted[310];
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first > b.first) {
    return false;
  } else {
    if (a.second < b.second) {
      return false;
    } else {
      return true;
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    sorted[i] = {arr[i], i};
  }
  seg segtree;
  segtree.init(m);
  sort(sorted, sorted + m, compare);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int pos = -1;
    for (int j = 0; j < m; j++) {
      if (sorted[j].second == i) {
        pos = j;
        break;
      }
    }
    segtree.addval(pos);
    ans += segtree.getsum(0, pos);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
