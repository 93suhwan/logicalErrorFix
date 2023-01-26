#include <bits/stdc++.h>
using namespace std;
const int Maxx = 1e5 + 99;
long long mod = 998244353;
int poss, ps, sam;
int ans;
string s;
vector<string> ss;
int solve(string a, string b) {
  poss = 0, ps = 0, sam = 0;
  while (poss < a.size() && ps < b.size()) {
    if (a[poss] == b[ps]) {
      ++sam;
      ++ps;
    }
    ++poss;
  }
  return (a.size() - sam + b.size() - sam);
}
int main() {
  int t;
  long long j = 1;
  for (int i = 0; i < 64; ++i, j = 1ll << (1ll * i)) {
    ss.push_back(to_string(j));
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> s;
    ans = 111;
    for (int i = 0; i < ss.size(); i++) {
      ans = min(solve(s, ss[i]), ans);
    }
    cout << ans << endl;
  }
  return 0;
}
