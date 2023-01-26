#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    string s;
    cin >> n;
    cin >> s;
    unordered_map<long long, long long> ump;
    ump[1] = ump[4] = ump[6] = ump[8] = ump[9] = 2;
    long long flag = 0;
    for (long long i = 0; i < n; i++) {
      if (ump[s[i] - '0'] == 2) {
        flag = 1;
        cout << 1 << "\n";
        cout << s[i] - '0' << "\n";
        break;
      }
    }
    if (flag == 1) continue;
    long long a = s[0] - '0';
    if (a == 2 or a == 5 or a == 7) {
      long long b = s[1] - '0';
      if (b == 3) {
        long long c = s[2] - '0';
        if (c == 3) {
          long long f = b * 10 + c;
          cout << 2 << "\n";
          cout << f << "\n";
        } else {
          long long f = a * 10 + c;
          cout << 2 << "\n";
          cout << f << "\n";
        }
      } else {
        long long f = a * 10 + b;
        cout << 2 << "\n";
        cout << f << "\n";
      }
    } else {
      long long b = s[1] - '0';
      if (b == 7) {
        long long c = s[2] - '0';
        if (c == 7) {
          long long f = b * 10 + c;
          cout << 2 << "\n";
          cout << f << "\n";
        } else {
          long long f = a * 10 + c;
          cout << 2 << "\n";
          cout << f << "\n";
        }
      } else {
        long long f = a * 10 + b;
        cout << 2 << "\n";
        cout << f << "\n";
      }
    }
  }
  return 0;
}
