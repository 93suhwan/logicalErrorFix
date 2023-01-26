#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long sum = 0;
    map<long long, long long> mp;
    set<long long> s;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
      mp[arr[i]]++;
    }
    long long count = 0;
    for (long long i = 0; i < n; i++) {
      long long temp = sum - arr[i];
      if (temp == sum - 1) {
        count = 1;
        break;
      }
    }
    if (count == 1) {
      long long ans = 0;
      for (auto it = mp.begin(); it != mp.end(); it++) {
        long long first = (*it).first;
        if (first != 0) {
          v.push_back((*it).second);
        }
      }
      long long maxi = *max_element(v.begin(), v.end());
      long long zeros = mp[0];
      if (mp.find(0) != mp.end()) {
        ans += maxi * pow(2, zeros);
      } else {
        ans += 1;
      }
      cout << ans << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
  return 0;
}
