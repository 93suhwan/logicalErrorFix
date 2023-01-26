#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long f = 0;
    char c1, c2;
    long long i = 0, j = n - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        f = 1;
        c1 = s[i];
        c2 = s[j];
        break;
      }
      i++;
      j--;
    }
    if (f == 0)
      cout << 0 << endl;
    else {
      i = 0, j = n - 1;
      long long cnt1 = 0, cnt2 = 0, f1 = 0, f2 = 0;
      while (i < j) {
        if (s[i] != s[j]) {
          if (s[i] == c1) {
            i++;
            cnt1++;
          } else if (s[j] == c1) {
            j--;
            cnt1++;
          } else {
            f1 = 1;
            break;
          }
        } else {
          i++;
          j--;
        }
      }
      i = 0, j = n - 1;
      while (i < j) {
        if (s[i] != s[j]) {
          if (s[i] == c2) {
            i++;
            cnt2++;
          } else if (s[j] == c2) {
            j--;
            cnt2++;
          } else {
            f2 = 1;
            break;
          }
        } else {
          i++;
          j--;
        }
      }
      if (f1 == 0 && f2 == 0)
        cout << min(cnt1, cnt2) << endl;
      else if (f1 == 0)
        cout << cnt1 << endl;
      else if (f2 == 0)
        cout << cnt2 << endl;
      else
        cout << -1 << endl;
    }
  }
}
