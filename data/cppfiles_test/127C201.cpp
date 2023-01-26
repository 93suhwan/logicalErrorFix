#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1);
const double INF = 1e18;
using namespace std;
string s, t;
char a[30];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> s >> t;
    memset(a, 0, sizeof(a));
    int i, j;
    for (i = 0; i < s.size(); i++) a[s[i] - 'a']++;
    sort(s.begin(), s.end());
    if (t == "abc" && a[0] && a[1] && a[2]) {
      swap(a[1], a[2]);
      for (i = 0; i < 26; i++)
        for (j = 1; j <= a[i]; j++)
          cout << (i == 1 ? 'c' : (i == 2 ? 'b' : char(i + 'a')));
      cout << endl;
    } else
      cout << s << endl;
  }
  return 0;
}
