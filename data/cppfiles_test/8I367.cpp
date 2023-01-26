#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double n;
    cin >> n;
    cout << abs(n - (2 * round(n / 3))) << " " << round(n / 3) << endl;
  }
}
