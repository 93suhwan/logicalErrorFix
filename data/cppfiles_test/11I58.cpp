#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int n;
  cin >> n;
  vector<int> a;
  for (auto i = 0; i < n; ++i) {
    int x;
    cin >> x, --x;
    if (x <= i) {
      x -= i;
      x = -x;
      auto it = lower_bound(a.begin(), a.end(), x);
      if (it == a.end()) {
        a.push_back(x);
      } else {
        *it = x;
      }
    }
  }
  cout << (int)a.size() << "\n";
  return 0;
}
