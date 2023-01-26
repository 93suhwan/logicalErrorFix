#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long m;
  cin >> m;
  vector<pair<long long, long long>> vec(m);
  for (long long i = 0; i < m; i++) {
    cin >> vec[i].first;
    cin >> vec[i].second;
  }
  sort(arr.begin(), arr.end());
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum += arr[i];
  for (long long i = 0; i < m; i++) {
    long long coins = 0;
    long long index =
        lower_bound(arr.begin(), arr.end(), vec[i].first) - arr.begin();
    if (index == 0)
      coins = max((long long)0, vec[i].second - sum + arr[0]);
    else if (index > n - 1)
      coins = max((long long)0, vec[i].first - arr[n - 1]) +
              max((long long)0, vec[i].second - sum + arr[n - 1]);
    else {
      long long index1 = index - 1;
      long long coins1 = max((long long)0, vec[i].first - arr[index1]) +
                         max((long long)0, vec[i].second - sum + arr[index1]);
      coins = max((long long)0, vec[i].second - sum + arr[index]);
      coins = min(coins, coins1);
    }
    cout << coins << '\n';
  }
}
