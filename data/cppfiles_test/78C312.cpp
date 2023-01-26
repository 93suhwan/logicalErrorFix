#include <bits/stdc++.h>
using namespace std;
long long int MAX = 1e6 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    if (r / 2 + 1 >= l)
      cout << r % (r / 2 + 1) << "\n";
    else
      cout << r % l << "\n";
  }
}
