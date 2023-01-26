#include <bits/stdc++.h>
#pragma GCC optimization("fast-math")
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
long double eps = 1e-8;
const long long INF = 100000000000;
long long cnt[1000001];
long long nums;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long ans;
    long long zero = 0;
    long long one = 0;
    long long smena = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i > 0 && s[i] != s[i - 1]) smena++;
      if (s[i] == '0')
        zero++;
      else
        one++;
    }
    if (smena >= 2 && zero >= 2)
      cout << 2;
    else if (zero > 0 && one == 0)
      cout << 1;
    else if (zero == 0 && one > 0)
      cout << 0;
    else
      cout << 1;
    cout << "\n";
  }
}
