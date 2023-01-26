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
    long long zero = 0;
    long long count = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0' && count == 0) {
        count++;
        zero++;
      } else if (s[i] == '0')
        count++;
      else
        count = 0;
    }
    if (zero < 2)
      cout << zero;
    else
      cout << 2;
    cout << "\n";
  }
}
