#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
void TEST_CASES() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string tmp = a.substr(i, 1) + b.substr(i, 1);
    mp[tmp]++;
  }
  const int INF = 1e9;
  int ans = INF;
  if (mp["11"] - mp["00"] == 1) {
    ans = mp["11"] + mp["00"];
  }
  if (mp["01"] == mp["10"]) {
    ans = min(ans, mp["01"] * 2);
  }
  if (ans == INF) ans = -1;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
