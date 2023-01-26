#include <bits/stdc++.h>
using namespace std;
void testCase() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  if (m > a + b + c - 3) {
    cout << "NO\n";
    return;
  }
  vector<int> v = {a, b, c};
  int mn = min({a, b, c});
  for (int &i : v) i -= mn;
  sort(v.rbegin(), v.rend());
  v[0] -= v[1];
  if (m < v[0]) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
  return 0;
}
