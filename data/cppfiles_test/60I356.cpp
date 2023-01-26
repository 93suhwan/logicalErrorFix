#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n + 1);
    map<long long, long long> mp;
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> v[i];
      mp[v[i]]++;
      sum += v[i];
    }
    if (sum % n != 0) {
      cout << 0 << endl;
      continue;
    }
    long long k = sum / n;
    k *= 2;
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      if (v[i] > k)
        continue;
      else {
        long long req = k - v[i];
        if (req != v[i])
          ans += mp[req];
        else
          ans += mp[req] - 1;
      }
    }
    cout << ans / 2 << endl;
  }
  return 0;
}
