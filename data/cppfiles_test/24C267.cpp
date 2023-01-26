#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, i;
  cin >> t;
  while (t--) {
    i = 0;
    cin >> n;
    if (n % 10 == 9) i++;
    n /= 10;
    cout << i + n << endl;
  }
  return 0;
}
