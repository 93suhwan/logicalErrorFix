#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1);
const double INF = 1e18;
using namespace std;
string s, t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> s >> t;
    sort(s.begin(), s.end());
    if (s == t) swap(s[2], s[1]);
    cout << s << endl;
  }
  return 0;
}
