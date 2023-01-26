#include <bits/stdc++.h>
using namespace std;
void oggy() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v) cin >> it;
  string s;
  cin >> s;
  int z = 0, o = 0, j = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      z++;
    } else {
      o++;
    }
  }
  if (z == 0 || o == 0) {
    for (auto it : v) cout << it << " ";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      v[i] = j;
      j++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      v[i] = j;
      j++;
    }
  }
  for (auto it : v) cout << it << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    oggy();
    cout << "\n";
  }
  return 0;
}
