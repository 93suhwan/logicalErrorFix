#include <bits/stdc++.h>
using namespace std;
void swap(long long int x, long long int y) { x = x + (y - (y = x)); }
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int one = 0, sec = 0;
    for (long long int i = 0; i < s.length(); i++) {
      if (s[i] == 'E')
        one++;
      else
        sec++;
    }
    sec == 1 ? cout << "NO"
                    << "\n"
             : cout << "YES"
                    << "\n";
  }
  return 0;
}
