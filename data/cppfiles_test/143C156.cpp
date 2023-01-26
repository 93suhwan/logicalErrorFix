#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    multiset<long long> extras;
    for (long long i = 0; i < n;) {
      long long var = arr[i];
      i++;
      while (i < n && arr[i] == var) {
        extras.insert(var);
        i++;
      }
    }
    long long pre[n + 1];
    memset(pre, 0, sizeof(pre));
    bool first = 1;
    for (long long i = 0; i <= n; i++) {
      if (binary_search(arr, arr + n, i)) {
        if (i == 0)
          pre[i] = 0;
        else
          pre[i] = pre[i - 1];
      } else {
        auto indi = extras.lower_bound(i);
        if (extras.empty() || indi == extras.begin()) {
          for (long long j = i; j <= n; j++) {
            pre[j] = -1;
          }
          i = n;
        } else {
          advance(indi, -1);
          pre[i] = pre[i - 1] + i - *indi;
          extras.erase(indi);
        }
      }
    }
    long long freqs[n + 1];
    memset(freqs, 0, sizeof(freqs));
    for (long long i = 0; i < n; i++) freqs[arr[i]]++;
    bool flag = 1;
    for (long long i = 0; i <= n; i++) {
      long long ans = freqs[i];
      if (i > 0 && pre[i - 1] == -1) {
        cout << -1 << " ";
      } else {
        if (i > 0)
          cout << ans + pre[i - 1] << " ";
        else
          cout << ans << " ";
      }
    }
    cout << '\n';
  }
}
