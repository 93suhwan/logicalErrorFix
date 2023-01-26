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
    } else
      cout << (x / 3) + 1 << " " << x / 3 << '\n';
  }
  return 0;
}
