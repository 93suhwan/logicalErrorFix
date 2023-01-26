#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 3 == 0)
      cout << n / 3 << " " << n / 3 << endl;
    else {
      int t1 = n / 3;
      int t2 = n / 3 + 1;
      if (t1 + t2 * 2 == n)
        cout << t1 << " " << t2 << endl;
      else if (t2 + t1 * 2 == n)
        cout << t2 << " " << t1 << endl;
    }
  }
  return 0;
}
