#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
void solve() {
  multiset<pair<int, int>> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x) s.insert(make_pair(x, i + 1));
  }
  vector<pair<int, int>> ans;
  pair<int, int> lst, secLst, f;
  while (s.size() > 1) {
    lst = *(prev(s.end()));
    s.erase(lst);
    secLst = *(prev(s.end()));
    s.erase(secLst);
    ans.push_back(make_pair(lst.second, secLst.second));
    lst.first -= 1, secLst.first -= 1;
    s.insert(lst);
    s.insert(secLst);
    while (s.size()) {
      f = *(s.begin());
      if (f.first == 0)
        s.erase(f);
      else
        break;
    }
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << min(x.first, x.second) << " " << max(x.second, x.first) << endl;
  }
}
int main() {
  int t = 1;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
