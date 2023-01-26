#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long remi = 1000000007;
const long long remi2 = 998244353;
const long long inf = 1e18 + 1e17 + 1e16 + 1e15 + 1e14;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j;
  long long t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    map<char, long long> mp;
    long long time = 0;
    for (i = 0; i < x.size(); i++) {
      mp[x[i]] = i + 1;
    }
    for (i = 1; i < min(x.size(), y.size()); i++) {
      time += abs(mp[y[i]] - mp[y[i - 1]]);
    }
    cout << time << "\n";
  }
  return 0;
}
