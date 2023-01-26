#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    swap(a, b);
    long long res = a % b;
    if (a / 2 + 1 >= b) res = max(res, a % (a / 2 + 1));
    cout << res << "\n";
  }
  return 0;
}
