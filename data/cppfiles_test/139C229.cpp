#include <bits/stdc++.h>
long long int Powerof2(long long int x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return x ^ (x >> 1);
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.length();
    if (n % 2 != 0) {
      cout << "NO" << endl;
    } else {
      long long int a = 0;
      long long int b = n / 2;
      int flag = 0;
      while (b < n) {
        if (s[a] != s[b]) {
          flag = 1;
        }
        a++;
        b++;
      }
      if (flag == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
