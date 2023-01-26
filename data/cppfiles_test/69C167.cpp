#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
vector<string> v;
int MI(int n) {
  string s = to_string(n);
  int mi = 100;
  string s2 = s;
  for (int i = 0; i < (55); i++) {
    int OP = 0;
    s = s2;
    for (int j = 0; j < min(v[i].size(), s.size()); j++) {
      if (v[i][j] != s[j]) {
        s.erase(j, 1);
        j--;
        OP++;
      }
    }
    int k = v[i].size() - s.size();
    if (k < 0) k *= -1;
    mi = min(mi, OP + k);
  }
  return mi;
}
void solve() {
  int n, ans = 0;
  cin >> n;
  cout << MI(n) << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < (55); i++) {
    long long ans = (1LL) << i;
    string s = to_string(ans);
    v.push_back(s);
  }
  while (t--) solve();
}
