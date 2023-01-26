#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long int check(string s) {
  long long int c = 1;
  for (long long int i = 0; i < s.length(); i++)
    if (s[i] != s[0]) c++;
  if (c >= 2) return 0;
  return 1;
}
long long int check2(string s) {
  set<char> st;
  for (char c : s) st.insert(c);
  if (st.size() <= 2) return 1;
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  while (tt--) {
    long long int n, k;
    cin >> n >> k;
    string s = to_string(n);
    if (k == 1) {
      if (s.length() == 1)
        cout << n << "\n";
      else {
        if (check(s))
          cout << s << "\n";
        else {
          long long int fl = 0;
          for (long long int i = 0; i < s.length(); i++) {
            if (s[i] != s[0]) {
              if (s[i] > s[0]) fl = 1;
              break;
            }
          }
          if (fl) {
            char c = s[0];
            c++;
            for (long long int i = 0; i < s.length(); i++) cout << c;
            cout << "\n";
          } else {
            for (long long int i = 0; i < s.length(); i++) cout << s[0];
            cout << "\n";
          }
        }
      }
    } else {
      long long int l = s.length();
      if (check2(s))
        cout << n << "\n";
      else {
        string st = s, res = "9999999999";
        for (long long int i = 0; i < 10; i++) {
          for (long long int j = i + 1; j < 10; j++) {
            long long int fl = 0, y = 0;
            for (long long int m = 0; m < l; m++) {
              if (s[m] - '0' != i && s[m] - '0' != j) {
                if (s[m] - '0' > i && s[m] - '0' > j) {
                  break;
                } else if (s[m] - '0' > i && s[m] - '0' < j) {
                  s[m] = char(j + 48);
                  for (long long int o = m + 1; o < l; o++) s[o] = char(i + 48);
                  fl = 1;
                  break;
                } else {
                  for (long long int o = m; o < l; o++) s[o] = char(i + 48);
                  fl = 1;
                  break;
                }
              }
            }
            if (fl) res = min(res, s);
            s = st;
          }
        }
        cout << res << "\n";
      }
    }
  }
  return 0;
}
