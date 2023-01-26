#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a1, a2;
    cin >> n;
    a1 = n / 3;
    a2 = n / 3;
    if (n % 3 == 2) a2++;
    if (n % 3 == 1) a1++;
    cout << a1 << " " << a2 << endl;
  }
  return 0;
}
