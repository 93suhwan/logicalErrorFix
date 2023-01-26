#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main() {
  int t;
  cin >> t;
  long long sum[65] = {0};
  sum[0] = 1;
  for (int i = 1; i <= 60; i++) {
    sum[i] = sum[i - 1] * 2;
  }
  while (t--) {
    map<long long, long long> mp;
    long long x[65];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      mp[x[i]]++;
    }
    if (!mp[1]) {
      cout << 0 << "\n";
      continue;
    } else {
      cout << mp[1] * sum[mp[0]] << "\n";
    }
  }
}
