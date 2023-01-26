#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int x;
    cin >> x;
    if (x % 3 == 0) {
      cout << x / 3 << " " << x / 3 << '\n';
    } else {
      long long temp = x / 3 + 1;
      long long temp2 = x / 3;
      if (temp + 2 * temp2 == x) {
        cout << temp << " " << temp2 << '\n';
      } else
        cout << temp2 << " " << temp << '\n';
    }
  }
  return 0;
}
