#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d;
  vector<tuple<int, int, int>> v(n);
  for (auto& i : v) {
    cin >> get<1>(i) >> get<2>(i);
    get<0>(i) = max(get<1>(i), get<2>(i));
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (auto& i : v) {
    if (get<1>(i) >= d) ans++, d = max(d, get<2>(i));
  }
  cout << ans;
}
