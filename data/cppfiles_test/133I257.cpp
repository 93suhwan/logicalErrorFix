#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int t, n;
string s;
string s1;
void solve() {
  cin >> n;
  s = "";
  for (int i = 1; i <= n - 2; i++) {
    cin >> s1;
    if (i == 1) {
      s += s1;
    } else
      s += s1[1];
  }
  s += 'a';
  cout << s << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
