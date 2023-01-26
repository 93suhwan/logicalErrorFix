#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') w = -1;
  for (; isdigit(ch); ch = getchar()) s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * w;
}
const long long N = 1e7 + 7;
const double eps = 1e-6;
const long long mod = 1e9 + 7;
const long long dir[][2] = {{0, 1}, {1, 0},  {0, -1}, {-1, 0},
                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const long long inf = 0x3f3f3f3f;
const long long _inf = 0xc0c0c0c0;
const long long inf_ll = 0x3f3f3f3f3f3f3f3f;
long long a[500];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    string s;
    cin >> s;
    for (long long i = 0; i < s.size(); i++) {
      a[s[i] - 'a']++;
    }
    long long sum = 0;
    long long sum1 = 0;
    for (long long i = 0; i < 26; i++) {
      if (a[i] >= 2)
        sum++;
      else if (a[i] >= 1)
        sum1++;
    }
    cout << sum + sum1 / 2 << "\n";
  }
}
