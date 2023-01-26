#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, a;
  cin >> s >> a;
  map<char, int> ans;
  for (int i = 0; i < s.size(); i++) {
    ans[s[i]] = i;
  }
  long long rem = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    rem += abs(ans[a[i]] - ans[a[i + 1]]);
  }
  cout << rem << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
