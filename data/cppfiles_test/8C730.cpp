#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a = n / 3, b = n / 3;
    if (n % 3 != 0) {
      if (n % 3 == 1)
        a++;
      else
        b++;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
