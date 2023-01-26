#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 30;
const long long MOD = 1e9 + 7;
const long long MAX = 1e6 + 5;
long long powerm(long long a, long long b, long long m) {
  if (b == 0) {
    return 1;
  }
  long long res = powerm(a, b / 2, m);
  if (b % 2) {
    return ((res * res) % m * (a % m)) % m;
  }
  return (res * res) % m;
}
long long power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long res = power(a, b / 2);
  if (b % 2 == 0) {
    return res * res;
  }
  return res * res * a;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    pair<long long, long long> arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i].first;
      arr[i].second = i;
    }
    sort(arr, arr + n);
    long long ans[n];
    vector<long long> f(k + 1, 0);
    long long currnum = -1, currcol = k + 1;
    for (long long i = 0; i < n; i++) {
      if (currcol > k && currnum != arr[i].first) {
        currcol = 1;
        currnum = arr[i].first;
      }
      if (currcol <= k) {
        ans[arr[i].second] = currcol;
        f[currcol]++;
        currcol++;
      } else {
        ans[arr[i].second] = 0;
      }
    }
    long long color = 1e6;
    for (long long i = 1; i <= k; i++) {
      color = min(color, f[i]);
    }
    for (long long i = 1; i <= k; i++) {
      f[i] = color;
    }
    for (long long i = 0; i < n; i++) {
      if (ans[i] != 0 && f[ans[i]] == 0) {
        ans[i] = 0;
      } else {
        f[ans[i]]--;
      }
    }
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
