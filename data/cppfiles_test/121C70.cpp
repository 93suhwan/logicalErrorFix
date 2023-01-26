#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    s += a[i];
    s += b[i];
    mp[s]++;
  }
  int ans = INT_MAX;
  if (mp["10"] == mp["01"]) {
    ans = mp["10"] + mp["01"];
  }
  if (mp["10"] > 0) {
    int new_00 = mp["10"] - 1;
    int new_01 = mp["11"];
    int new_11 = mp["01"];
    int new_10 = mp["00"] + 1;
    if (new_10 == new_01) {
      ans = min(ans, 1 + new_10 + new_01);
    }
  }
  if (mp["11"] > 0) {
    int new_00 = mp["10"];
    int new_01 = mp["11"] - 1;
    int new_11 = mp["01"] + 1;
    int new_10 = mp["00"];
    if (new_10 == new_01) {
      ans = min(ans, 1 + new_10 + new_01);
    }
  }
  if (ans == INT_MAX) {
    cout << -1;
    return;
  } else {
    cout << ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
