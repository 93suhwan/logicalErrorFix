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
long long findCountDiff(string str) {
  long long c1 = 0, c2 = 0;
  for (long long i = 0; i < str.length() - 1; i++) {
    if (str[i] == 'a' && str[i + 1] == 'b')
      c1++;
    else if (str[i] == 'b' && str[i + 1] == 'a')
      c2++;
  }
  return abs(c1 - c2);
}
int32_t main() {
  boost();
  long long t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    if (str[0] == str[str.length() - 1]) {
      cout << str << '\n';
    } else {
      if (str[0] == 'a')
        str[0] = 'b';
      else
        str[0] = 'a';
      cout << str << '\n';
    }
  }
  return 0;
}
