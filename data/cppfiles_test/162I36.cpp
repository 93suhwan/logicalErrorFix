#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto &x : v) cout << x << ' ';
  return os;
}
int n;
bool simulate(vector<int> v, int x) {
  for (int i = 2; i < n; i++) {
    int a = max(0, x - v[i - 2]), b = max(0, x - v[i - 1]);
    int d = min(max((a + 1) / 2, b), v[i] / 3);
    v[i - 2] += 2 * d;
    v[i - 1] += d;
    v[i] -= 3 * d;
  }
  return *min_element(v.begin(), v.end()) >= x;
}
void solve() {
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int l = *min_element(v.begin(), v.end()),
      r = *max_element(v.begin(), v.end()), ans = l;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (simulate(v, mid)) {
      l = mid + 1;
      ans = max(ans, mid);
    } else
      r = mid - 1;
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int $i = 0; $i < t; $i++) solve();
}
