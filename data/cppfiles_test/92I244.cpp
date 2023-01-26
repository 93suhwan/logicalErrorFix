#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long pow(long long n, long long m) {
  if (m % 2 == 0) {
    long long pro = pow(n, m / 2);
    return ((pro) % 1000000007 * (pro) % 1000000007) % 1000000007;
  } else {
    return ((n) % 1000000007 * (pow(n, m - 1)) % 1000000007) % 1000000007;
  }
}
int32_t main() {
  boost();
  long long t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    vector<long long> in(str.length(), 0);
    for (long long i = 1; i < str.length() - 1; i++) {
      if (str[i] == 'a') {
        if (str[i - 1] == 'b' && str[i + 1] == 'b') {
          in[i] = 1;
        }
      } else {
        if (str[i - 1] == 'a' && str[i + 1] == 'a') {
          in[i] = 1;
        }
      }
    }
    long long c1 = 0, c2 = 0;
    for (long long i = 0; i < str.length() - 1; i++) {
      if (str[i] == 'a' && str[i + 1] == 'b') {
        c1++;
      }
      if (str[i] == 'b' && str[i + 1] == 'a') {
        c2++;
      }
    }
    long long ans = 0;
    if (c1 > c2) {
      for (long long i = 0; i < str.length() - 1 && c1 - c2 > 0; i++) {
        if (in[i] == 0 && str[i] == 'a' && str[i + 1] == 'b') {
          str[i] = 'b';
        }
      }
    } else {
      for (long long i = 0; i < str.length() - 1 && c2 - c1 > 0; i++) {
        if (in[i] == 0 && str[i] == 'b' && str[i + 1] == 'a') {
          str[i] = 'a';
        }
      }
    }
    cout << str << '\n';
  }
  return 0;
}
