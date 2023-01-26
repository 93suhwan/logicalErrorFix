#include <bits/stdc++.h>
using namespace std;
void SolveF();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  SolveF();
  return 0;
}
void SolveF() {
  int T;
  cin >> T;
  while (T--) {
    long long n;
    int k;
    cin >> n >> k;
    int currk[11];
    int minInt[11];
    int a[10];
    memset(a, 0, sizeof(a));
    string s = to_string(n);
    int lens = s.length();
    ++a[s[0] - '0'];
    currk[0] = 1;
    minInt[0] = s[0] - '0';
    for (int i = 1; i < lens; ++i) {
      if (a[s[i] - '0'] == 0) {
        currk[i] = currk[i - 1] + 1;
        minInt[i] =
            ((minInt[i - 1]) < (s[i] - '0') ? (minInt[i - 1]) : (s[i] - '0'));
      } else {
        currk[i] = currk[i - 1];
        minInt[i] = minInt[i - 1];
      }
      ++a[s[i] - '0'];
    }
    if (k == currk[lens - 1]) {
      cout << s << endl;
      continue;
    } else if (k > lens) {
      cout << s << endl;
    } else if (k > currk[lens - 1]) {
      cout << s << endl;
    } else {
      while (1) {
        int pos = 0;
        for (int i = 0; i < 10; ++i) {
          a[i] = 0;
          currk[i] = 0;
        }
        currk[0] = 1;
        a[s[0] - '0'] = 1;
        for (int i = 1; i < lens; ++i) {
          if (a[s[i] - '0'] == 0)
            currk[i] = currk[i - 1] + 1;
          else
            currk[i] = currk[i - 1];
          ++a[s[i] - '0'];
        }
        if (k >= currk[lens - 1]) break;
        for (int i = 0; i < lens; ++i) {
          if (currk[i] == k + 1) {
            pos = i;
            break;
          }
        }
        while (s[pos] == 9 + '0') --pos;
        ++s[pos];
        for (int i = pos + 1; i < lens; ++i) s[i] = '0';
      }
      cout << s << endl;
    }
  }
}
