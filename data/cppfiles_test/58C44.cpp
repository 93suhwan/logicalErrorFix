#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long mod1 = 998244353;
int main() {
  long long t;
  cin >> t;
  long long p1 = 0;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n][2];
    for (long long j = 0; j < 2; j++) {
      for (long long i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i][j] = (c == '1');
      }
    }
    long long p = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i][0] == 1 && a[i][1] == 1) {
        p = 1;
      }
    }
    if (p == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
