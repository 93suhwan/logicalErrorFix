#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(6);
  long long int test;
  cin >> test;
  while (test--) {
    long long int l;
    cin >> l;
    long long int r;
    cin >> r;
    if (l > r / 2)
      cout << r % l << '\n';
    else {
      if (r % 2 == 0)
        cout << (r / 2) - 1 << '\n';
      else
        cout << (r / 2) << '\n';
    }
  }
  return 0;
}
