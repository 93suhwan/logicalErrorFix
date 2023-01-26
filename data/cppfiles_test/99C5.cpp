#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void printvi(vector<long long> v) {
  for (auto x : v) cout << x << " ";
  cout << endl;
}
long long solve() {
  long long x, y, r;
  cin >> x >> y;
  r = y % 4;
  long long val = y - r;
  while (r--) {
    if (abs(x) % 2 == 0) {
      x -= (++val);
    } else {
      x += (++val);
    }
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    cout << solve() << endl;
  }
  return 0;
}
