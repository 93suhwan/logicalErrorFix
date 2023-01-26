#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long n, i, ans, a, b;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 2; i < n; i++) {
      ans = n / i;
      if (ans != 1 && ans == i) {
        a = ans;
        b = ans * ans;
      } else if (ans != 1 && ans != i) {
        a = i;
        b = ans;
      }
    }
    cout << a << ' ' << b << endl;
  }
}
