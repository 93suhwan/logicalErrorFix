#include <bits/stdc++.h>
using namespace std;
using tup = tuple<int, int, int>;
vector<vector<pair<int, int>>> v;
long long t, l, r;
int main() {
  cin >> t;
  while (t--) {
    cin >> l >> r;
    long long MAX = r % l;
    for (int i = 2; i <= r / l; i++) {
      if (l <= r / i) {
        if (r % i == 0) {
          MAX = max(r / i - 1, MAX);
        } else
          MAX = max(r / i, MAX);
        break;
      }
    }
    cout << MAX << '\n';
  }
  return 0;
}
