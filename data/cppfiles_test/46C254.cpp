#include <bits/stdc++.h>
using namespace std;
void testCase() {
  int n;
  cin >> n;
  vector<int> v(n);
  int mx = -1, j = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] >= mx) mx = v[i], j = i;
  }
  mx = -1;
  int cnt = 0;
  for (int i = n - 1; i > j; i--) {
    if (v[i] > mx)
      mx = v[i], cnt = 1;
    else if (v[i] == mx)
      cnt++;
  }
  if (!~mx) {
    cout << 0 << '\n';
    return;
  }
  int sol = 0;
  int mxx = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] == mx) cnt--;
    if (v[i] > mxx) sol++;
    mxx = max(mxx, v[i]);
    if (!cnt) break;
  }
  cout << sol << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) testCase();
  return 0;
}
