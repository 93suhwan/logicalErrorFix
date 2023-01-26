#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    ll i, n, k, count1 = 0;
    map<ll, ll> mp;
    cin >> n >> k;
    vector<long long int> ara(n), sorted(n);
    for (int i = 0; i < n; i++) {
      cin >> ara[i];
      sorted[i] = ara[i];
    }
    sorted.push_back(INT_MAX);
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++) {
      mp[sorted[i]] = sorted[i + 1];
    }
    for (int i = 0; i < n; i++) {
      if (mp[ara[i]] != ara[i + 1]) count1++;
    }
    if (count1 <= k)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
