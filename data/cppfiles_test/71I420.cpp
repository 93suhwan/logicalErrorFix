#include <bits/stdc++.h>
using namespace std;
const double pai = acos(-1.0);
const long long maxn = 1e6 + 10;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const long long N = 5e3 + 10;
inline long long read() {
  long long k = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) k = (k << 1) + (k << 3) + c - 48, c = getchar();
  return k * f;
}
long long t, n, k, cnt[110];
bool vis[100];
string s;
long long check(string s) {
  for (long long i = 0; i <= 9; i++) vis[i] = 0;
  long long sum = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (!vis[s[i] - '0']) {
      vis[s[i] - '0'] = 1;
      sum++;
    }
  }
  return sum;
}
signed main() {
  cin >> t;
  while (t--) {
    for (long long i = 0; i <= 9; i++) cnt[i] = 0;
    cin >> s >> k;
    long long sum = check(s);
    if (sum <= k)
      cout << s << endl;
    else {
      long long len = s.size();
      if (k == 1) {
        long long pos = 1;
        while (s[pos] == s[0]) pos++;
        if (s[0] > s[pos]) {
          for (long long i = 0; i < len; i++) s[i] = s[0];
          cout << s << endl;
        } else if (s[0] < s[pos]) {
          s[0] = s[0] + 1;
          for (long long i = 0; i < len; i++) s[i] = s[0];
          cout << s << endl;
        }
      } else {
        long long a1, a2, a3, pos = 0, p1, p2, p3;
        a1 = s[0];
        while (s[pos] == a1) pos++;
        a2 = s[pos], p1 = pos;
        while (s[pos] == a2) pos++;
        a3 = s[pos], p2 = pos;
        if (a1 > a2) {
          if (a2 > a3) {
            for (long long i = p1; i < len; i++) s[i] = (char)(a2);
            cout << s << endl;
          } else {
            for (long long i = p1; i < len; i++) s[i] = (char)(a2 + 1);
            cout << s << endl;
          }
        } else {
          if (a2 == '9') {
            s[0] = s[0] + 1;
            for (long long i = 1; i < len; i++) s[i] = '1';
            cout << s << endl;
          } else {
            s[p1] = s[p1] + 1;
            for (long long i = p1 + 1; i < len; i++) s[i] = '1';
            cout << s << endl;
          }
        }
      }
    }
  }
  return 0;
}
