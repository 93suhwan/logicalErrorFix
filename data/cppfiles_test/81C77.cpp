#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> v(n);
  for (auto& i : v) {
    cin >> i.first >> i.second;
  }
  sort(v.begin(), v.end(),
       [&](const pair<int, int>& a, const pair<int, int>& b) {
         return make_tuple(max(a.first, a.second), a) <
                make_tuple(max(b.first, b.second), b);
       });
  int ans = 0;
  for (auto& i : v) {
    if (i.first >= d) ans++, d = max(d, i.second);
  }
  cout << ans;
}
