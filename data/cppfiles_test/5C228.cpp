#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < 2; i++) {
    string str;
    cin >> str;
    v.push_back(str);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (v[1][i] == '0') continue;
    if (v[0][i] == '0') {
      cnt++;
      v[0][i] = 'z';
      continue;
    } else if (i - 1 >= 0 && v[0][i - 1] == '1') {
      cnt++;
      v[0][i - 1] = 'z';
      continue;
    } else if (i + 1 < n && v[0][i + 1] == '1') {
      cnt++;
      v[0][i + 1] = 'z';
      continue;
    }
  }
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
