#include <bits/stdc++.h>
using namespace std;
void write(vector<int> &v) {
  for (auto i : v) cout << i << " ";
  cout << "\n";
}
void read(vector<int> &v) {
  for (auto &i : v) cin >> i;
}
const int INF = 1e9;
const int64_t INFF = 1e18;
const int N = 1e6 + 69;
int k;
string s;
string calc(int index, string ans) {
  set<char> st((ans).begin(), (ans).end());
  if ((int)(st).size() > k) return "";
  if (ans.substr(0, index) < s.substr(0, index)) return "";
  if (index >= s.length()) {
    return ans;
  }
  for (char c = '0'; c <= '9'; c++) {
    ans.push_back(c);
    string pos = calc(index + 1, ans);
    ans.pop_back();
    if (pos.length() == s.length()) return pos;
  }
}
void solve() {
  cin >> s;
  cin >> k;
  cout << calc(0, "") << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
