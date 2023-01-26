#include <bits/stdc++.h>
using namespace std;
const int sz = 1 << 18;
int tree[sz << 1];
void update(int x) {
  x |= sz;
  while (x) {
    tree[x]++;
    x >>= 1;
  }
}
int count(int l, int r) {
  l |= sz, r |= sz;
  int ans = 0;
  while (l <= r) {
    if (l & 1) ans += tree[l++];
    if (~r & 1) ans += tree[r--];
    l >>= 1, r >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    memset(tree, 0, sizeof(int) * (sz << 1));
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> temp = v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> p;
    for (int x : temp)
      p.push_back(lower_bound(v.begin(), v.end(), x) - v.begin());
    update(p[0]);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      int x = count(0, p[i] - 1);
      int y = count(p[i] + 1, sz - 1);
      if (x > y) {
        update(p[i]);
        ans += y;
      } else {
        update(p[i]);
        ans += x;
      }
    }
    cout << ans << '\n';
  }
}
