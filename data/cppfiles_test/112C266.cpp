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
  sort(v.rbegin(), v.rend());
  if (v[0] > v[1] + v[2]) {
    int cnt = v[0] - v[1] - v[2] - 1;
    cout << (m >= cnt ? "YES\n" : "NO\n");
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
