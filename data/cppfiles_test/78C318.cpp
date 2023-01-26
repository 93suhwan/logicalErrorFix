#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int l, a;
    cin >> l >> a;
    if (l > (a / 2))
      cout << a % l << endl;
    else
      cout << (a) % ((a / 2) + 1) << endl;
  }
  return 0;
}
