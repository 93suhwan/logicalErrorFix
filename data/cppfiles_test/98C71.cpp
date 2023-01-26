#include <bits/stdc++.h>
using namespace std;
vector<int> go(vector<int> a) {
  int n = a.size();
  vector<int> b(n);
  for (auto i = 0; i < n; i++) b[a[i] - 1]++;
  for (auto i = 0; i < n; i++) a[i] = b[a[i] - 1];
  return a;
}
void solve() {
  int t;
  cin >> t;
  for (auto j = 0; j < t; j++) {
    string s, k;
    cin >> s >> k;
    map<char, int> key;
    for (auto i = 0; i < s.size(); i++) {
      key[s[i]] = i;
    }
    int ans = 0;
    for (auto i = 1; i < k.size(); i++) {
      ans += abs(key[k[i]] - key[k[i - 1]]);
    }
    cout << ans << endl;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
