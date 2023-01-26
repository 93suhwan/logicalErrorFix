#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")
using namespace std;
using ll = long long;
using ld = double;
const bool TEST = true;
const bool DEBUG = false;
const ld PI = acosl(-1);
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt2 = 0;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    auto ch = s[i];
    cnt2 += '2' == ch;
    if (ch == '2') {
      b.push_back(i);
    }
  }
  if (cnt2 == 1 || cnt2 == 2) {
    cout << "NO\n";
    return;
  }
  vector<string> ans(n, string(n, '='));
  for (int i = 0; i < n; i++) ans[i][i] = 'X';
  for (int i = 0; i < b.size(); i++) {
    int from = b[i];
    int to = b[(i + 1) % b.size()];
    ans[from][to] = '+';
    ans[to][from] = '-';
  }
  cout << "YES\n";
  for (auto& s : ans) cout << s << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  if (TEST) {
    cin >> t;
  } else {
    t = 1;
  }
  while (t--) solve();
}
