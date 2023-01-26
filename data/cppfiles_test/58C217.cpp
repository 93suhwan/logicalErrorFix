#include <bits/stdc++.h>
using namespace std;
void testCase() {
  int n;
  cin >> n;
  vector<string> v(2);
  cin >> v[0] >> v[1];
  bool valid = 1;
  for (int i = 0; i < n; i++) {
    if (v[0][i] == '1' && v[1][i] == '1') valid = 0;
  }
  cout << (valid ? "YES" : "NO") << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    testCase();
  }
  return 0;
}
