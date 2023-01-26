#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long n, i, ans, a, b;
  cin >> t;
  while (t--) {
    cin >> n;
    ans = n / 2;
    if (ans == 2) {
      a = ans;
      b = ans * ans;
    } else if (ans != 2) {
      a = 2;
      b = ans;
    }
    cout << a << ' ' << b << endl;
  }
}
