#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, char>> arr(n);
    for (long long i = 0; i != n; i++) {
      cin >> arr[i].first;
    }
    for (long long i = 0; i != n; i++) {
      cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    vector<long long> low(n + 1, 0);
    vector<long long> high(n + 1, 0);
    for (long long j = 0; j != n; j++) {
      if (arr[j].second == 'B') {
        if (arr[j].first >= n) {
          low[n]++;
        } else if (arr[j].first >= 0) {
          low[arr[j].first]++;
        }
      } else {
        if (arr[j].first <= 0) {
          high[1]++;
        } else if (arr[j].first <= n) {
          high[arr[j].first]++;
        }
      }
    }
    long long cur = 0;
    for (long long i = 1; i <= n; i++) {
      cur += high[i];
      if (cur > 0) {
        high[i] = 1;
        cur--;
      }
    }
    cur = 0;
    for (long long i = n; i >= 1; i--) {
      cur += low[i];
      if (cur > 0) {
        low[i] = 1;
        cur--;
      }
    }
    long long malo = 0;
    long long lish = 0;
    for (long long i = 1; i <= n; i++) {
      if (low[i] == 0 && high[i] == 0) {
        malo++;
      }
      if (low[i] == 1 && high[i] == 1) {
        lish++;
      }
    }
    cout << (lish - malo >= 0 ? "YES" : "NO") << '\n';
  }
  return 0;
}
