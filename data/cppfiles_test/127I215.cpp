#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  sort(s.begin(), s.end());
  if (t == "abc") {
    sort(s.begin(), s.end(), [&](const char &i, const char &j) {
      return (i == 'c' && j == 'b') || i < j;
    });
  }
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
