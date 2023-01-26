#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, c1, c2;
    cin >> n;
    c1 = c2 = n / 3;
    if (n % 3 == 1)
      c1++;
    else if (n % 3 == 2)
      c2++;
    cout << c1 << " " << c2 << "\n";
  }
  return 0;
}
