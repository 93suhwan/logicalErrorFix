#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, s;
    cin >> n >> s;
    long long int k = 0, p = 0, r = 0;
    if (n == 1 && s == 1)
      cout << 1 << endl;
    else if (n == 1 && s > 1)
      cout << s << endl;
    else if (n > 1 && s == 1)
      cout << 0 << endl;
    else {
      k = s / n;
      p = s % n;
      r = (k + p) - 1;
      cout << r << endl;
    }
  }
  return 0;
}
