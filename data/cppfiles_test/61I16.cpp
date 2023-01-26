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
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        long long j = i;
        while (j + 1 < n) {
          if (s[j + 1] == '?' && s[j] == 'R')
            s[j + 1] = 'B';
          else if (s[j + 1] == '?' && s[j] == 'B')
            s[j + 1] = 'R';
          j++;
        }
        j = i;
        while (j >= 1) {
          if (s[j - 1] == '?' && s[j] == 'R')
            s[j - 1] = 'B';
          else if (s[j] == 'B' && s[j - 1] == '?')
            s[j - 1] = 'R';
          j--;
        }
      } else if (s[i] == 'B') {
        long long j = i;
        while (j + 1 < n) {
          if (s[j + 1] == '?' && s[j] == 'R')
            s[j + 1] = 'B';
          else if (s[j + 1] == '?' && s[j] == 'B')
            s[j + 1] = 'R';
          j++;
        }
        j = i;
        while (j >= 1) {
          if (s[j - 1] == '?' && s[j] == 'R')
            s[j - 1] = 'B';
          else if (s[j] == 'B' && s[j - 1] == '?')
            s[j - 1] = 'R';
          j--;
        }
      }
    }
    cout << s << "\n";
  }
}
