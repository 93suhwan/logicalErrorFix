#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n, k;
    cin >> n >> k;
    long long a[n];
    int ans = 0;
    map<long long, long long> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]] = i;
    }
    for (int i = 0; i < n - 1; i++) {
      if (mp[a[i + 1]] - mp[a[i]] == 1) continue;
      ans++;
    }
    if (ans > k)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
