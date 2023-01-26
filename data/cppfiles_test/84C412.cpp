#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long n, s;
    cin >> n >> s;
    if (n == 1) {
      cout << s << endl;
      continue;
    }
    long index = n % 2 == 0 ? n / 2 : n / 2 + 1;
    long p = n - index + 1;
    cout << s / p << endl;
  }
  return 0;
}
