#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void prl(int x) { cout << x << "\n"; }
const int N = (int)(1 * 1e6 + 10);
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
      if (s[0] == '?') s[0] = 'B';
    }
    while (n--) {
      for (int i = 0; i < n; i++) {
        if (s[i] == 'R' || s[i] == 'B') {
          if (i + 1 < n) {
            if (s[i] == 'R' && s[i + 1] == '?')
              s[i + 1] = 'B';
            else if (s[i] == 'B' && s[i + 1] == '?')
              s[i + 1] = 'R';
          }
          if (i >= 1) {
            if (s[i] == 'R' && s[i - 1] == '?')
              s[i - 1] = 'B';
            else if (s[i] == 'B' && s[i - 1] == '?')
              s[i - 1] = 'R';
          }
        }
      }
    }
    if (s.size() >= 2) {
      long long n = s.size();
      if (s[n - 1] == '?') {
        if (s[n - 2] == 'B')
          s[n - 1] = 'R';
        else if (s[n - 2] == 'R')
          s[n - 1] = 'B';
      }
    }
    cout << s << "\n";
  }
}
