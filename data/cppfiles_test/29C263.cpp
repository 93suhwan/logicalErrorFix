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
      long long zeros = mp[0];
      if (mp.find(0) != mp.end() && mp.find(1) != mp.end()) {
        ans += mp[1] * pow(2, zeros);
      } else if (mp.find(1) != mp.end()) {
        ans += mp[1];
      }
      cout << ans << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
  return 0;
}
