#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
long long int power(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long int t = power(a, b / 2, m) % m;
  t = (t * t) % m;
  if (b & 1) t = ((t % m) * (a % m)) % m;
  return t;
}
long long int modInverse(long long int a, long long int m) {
  return power(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.length();
    long long int a = 0, b = 0, c = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == 'A')
        a++;
      else if (s[i] == 'B')
        b++;
      else
        c++;
    }
    if (a + c != b) {
      cout << "NO"
           << "\n";
    } else
      cout << "YES"
           << "\n";
  }
  return 0;
}
