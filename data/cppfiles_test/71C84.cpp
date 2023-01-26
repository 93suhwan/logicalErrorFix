#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
long long int M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1, i, j, num;
  cin >> t;
  while (t--) {
    long long int n, k, m, cnt = 1;
    cin >> n >> k;
    string ss = to_string(n);
    if (k == 1 && n < 10) {
      cout << n << "\n";
      continue;
    }
    for (i = 1; i < ss.size(); i++) {
      if (ss[i] == ss[0]) {
        cnt++;
      }
    }
    if (cnt == ss.size() && k == 2) {
      cout << n << "\n";
      continue;
    }
    if (k == 1) {
      string s = to_string(n);
      num = s.size();
      string kk(num, '1');
      long long int n1 = stoll(kk);
      long long int k2 = ceil((long double)n / n1);
      long long int ans = k2 * n1;
      cout << ans << "\n";
      continue;
    } else if (k == 2) {
      long long int ans = 0, diff = 1e13;
      string s = to_string(n);
      for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
          char c1 = '0' + i;
          char c2 = '0' + j;
          string anu = "";
          m = 0;
          long long int flg = 0, fllg = 0, loc = -1;
          for (m = 0; m < s.size(); m++) {
            if (flg == 1 || s[m] == c1) {
              anu += c1;
              fllg = 1;
              loc = m;
            } else if (s[m] < c1) {
              anu += c1;
              flg = 1;
            } else if (s[m] == c2) {
              anu += c2;
            } else if (s[m] > c2) {
              if (fllg == 0) {
                break;
              } else {
                long long int n6 = loc;
                anu[n6] = c2;
                for (long long int kk1 = n6 + 1; kk1 < m; kk1++) {
                  anu[kk1] = c1;
                }
                for (long long int kk1 = m; kk1 < s.size(); kk1++) {
                  anu += c1;
                }
                break;
              }
            } else if (s[m] > c1 && s[m] < c2) {
              anu += c2;
              flg = 1;
            }
          }
          if (anu.size() == 0) {
            continue;
          }
          long long int n3 = stoll(anu);
          if (n3 < n) {
            continue;
          }
          long long int n4 = n3 - n;
          if (n4 < diff) {
            diff = n4;
            ans = n3;
          }
        }
      }
      cout << ans << "\n";
      continue;
    }
  }
}
