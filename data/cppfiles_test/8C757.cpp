#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int oneB = n / 3, twoB = oneB;
    int rem = n % 3;
    if (rem == 0)
      cout << oneB << " " << twoB << endl;
    else if (rem == 1)
      cout << oneB + 1 << " " << twoB << endl;
    else
      cout << oneB << " " << twoB + 1 << endl;
  }
  return 0;
}
