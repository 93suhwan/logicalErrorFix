#include <bits/stdc++.h>
using namespace std;
long long int N = 2, M;
bool fun(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  if ((a.first > b.first) || (a.first == b.first && a.second > b.second))
    return 1;
  return 0;
}
bool checkleft(int a, int i, string t, string s) {
  if (i == t.size()) return true;
  if (a >= 0 && a < s.size() && t[i] == s[a]) {
    return (checkleft(a - 1, i + 1, t, s));
  }
  return false;
}
bool check1(long long int i, long long int j, string s, string t) {
  if (j == t.size()) return true;
  if (i >= 0 && i < s.size() && s[i] == t[j]) {
    return (check1(i + 1, j + 1, s, t) || checkleft(i - 1, j + 1, t, s));
  }
  return false;
}
int check(string s) {
  long long int e = 0, o = 0;
  for (int i = 0; i < 10; i++) {
    if (s[i] == '?') s[i] = '1';
    if (i % 2 == 0)
      e += s[i] == '1' ? 1 : 0;
    else
      o += s[i] == '1' ? 1 : 0;
    if (e > o) {
      long long int x = i % 2 == 0 ? (10 - i) / 2 : (9 - i) / 2;
      if (e > o + x) {
        return i + 1;
      }
    } else if (o > e) {
      long long int y = i % 2 == 0 ? (9 - i) / 2 : (10 - i) / 2;
      if (o > e + y) {
        return i + 1;
      }
    }
  }
  return 10;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int i, j, t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> k;
    string s;
    cin >> s;
    if (s.size() == 1) {
      cout << 1 << endl;
      cout << s << endl;
    } else {
      for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++) {
          long long int x = 10 * (s[i] - '0') + (s[j] - '0');
          for (int k = 2; k < x; k++) {
            if (x % k == 0) {
              cout << 2 << endl;
              cout << x << endl;
              goto sos;
            } else if (s[i] == '1' || s[j] == '1') {
              cout << 1 << endl;
              cout << 1 << endl;
              goto sos;
            }
          }
        }
      }
    sos:;
    }
  }
}
