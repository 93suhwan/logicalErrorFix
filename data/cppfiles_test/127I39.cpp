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
    if (t == "abc") {
      int p1 = -1, p2 = -1, f = 0, i;
      for (i = 0; i < s.size(); i++) {
        if (s[i] == 'a') f = 1;
        if (s[i] == 'b' && p1 == -1) p1 = i;
        if (s[i] == 'c' && p2 == -1) p2 = i;
      }
      if (f && p1 != -1 && p2 != -1) swap(s[p1], s[p2]);
    }
    cout << s << endl;
  }
  return 0;
}
