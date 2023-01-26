#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, b, x;
    cin >> n;
    if ((n - 1) % 3 == 0) {
      x = (int)((n - 1) / 3);
      x++;
      b = (n - x) / 2;
    } else if ((n - 2) % 3 == 0) {
      x = (int)((n - 1) / 3);
      b = (n - x) / 2;
    } else {
      x = (int)(n / 3);
      b = x;
    }
    cout << x << " " << b << endl;
  }
  return 0;
}
