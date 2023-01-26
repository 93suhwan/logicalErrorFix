#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c1, c2;
    int rem = n % 3;
    int diff = min(rem, 3 - rem);
    c2 = (n - diff) / 3;
    c1 = c2 + diff;
    if (rem > 3 - rem) {
      cout << c2 << " " << c1 << endl;
    } else {
      cout << c1 << " " << c2 << endl;
    }
  }
}
