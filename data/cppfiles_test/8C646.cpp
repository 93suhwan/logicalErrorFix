#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c2 = n / 3;
    if (n % 3 == 0)
      cout << n / 3 << " " << n / 3 << endl;
    else if (n % 3 == 1)
      cout << (n - 2 * c2) << " " << c2 << endl;
    else {
      cout << (n - 2 * (c2 + 1)) << " " << c2 + 1 << endl;
    }
  }
  return 0;
}
