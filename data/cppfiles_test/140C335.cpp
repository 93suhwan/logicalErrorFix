#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<long long int> v;
  map<long long int, long long int> mp;
  for (long long int i = 1; i <= 100000; i++) {
    if (mp[i * i] == 0) {
      v.push_back((i * i));
      mp[i * i] = 1;
    }
    if (mp[i * i * i] == 0) {
      v.push_back((i * i * i));
      mp[i * i * i] = 1;
    }
  }
  sort(v.begin(), v.end());
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int u = upper_bound(v.begin(), v.end(), n) - v.begin();
    cout << u << "\n";
  }
}
