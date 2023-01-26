#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    map<long long, long long> mp;
    long long x[65];
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      mp[x[i]]++;
      sum += x[i];
    }
    if (!mp[1]) {
      cout << 0 << "\n";
      continue;
    } else {
      cout << mp[1] * pow(2, mp[0]) << "\n";
    }
  }
}
