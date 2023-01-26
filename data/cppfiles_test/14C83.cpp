#include <bits/stdc++.h>
using namespace std;
int const N = 5e5 + 5, mod = 1e9 + 7, oo = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> v2;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
      int minnIndex = min_element(v.begin() + i, v.end()) - v.begin();
      if (minnIndex != i) {
        v2.push_back({i + 1, minnIndex + 1, minnIndex - i});
        for (int k = minnIndex - 1; k >= i; k--) {
          swap(v[k], v[k + 1]);
        }
      }
    }
    cout << v2.size() << "\n";
    for (auto vv : v2) cout << vv[0] << " " << vv[1] << " " << vv[2] << "\n";
  }
  return 0;
}
