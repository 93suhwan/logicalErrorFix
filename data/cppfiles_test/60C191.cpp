#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int j = (int32_t)0; j < (int32_t)t; j++) {
    long long int n;
    cin >> n;
    long long int arr[n];
    map<long long int, long long int> mp;
    long double sm = 0.0;
    long long int sm_tw = 0;
    for (long long int i = (int32_t)0; i < (int32_t)n; i++) {
      cin >> arr[i];
      sm += arr[i];
      sm_tw += arr[i];
      mp[arr[i]]++;
    }
    sm /= ((long double)n);
    sm *= 2;
    sort(arr, arr + n);
    if ((ceil(sm) == ((long long int)(sm)))) {
      long long int cnt = 0;
      for (long long int i = (int32_t)0; i < (int32_t)n; i++) {
        long long int nm = arr[i];
        if (mp.find(sm - nm) != mp.end()) {
          if (mp[sm - nm] == 0) continue;
          mp[nm] -= 1;
          cnt += mp[sm - nm];
        }
      }
      cout << cnt << '\n';
    } else {
      cout << "0\n";
    }
  }
  return 0;
}
