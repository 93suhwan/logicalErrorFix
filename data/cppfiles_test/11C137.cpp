#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9 + 7;
long long nxt() {
  long long x;
  cin >> x;
  return x;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long qu = nxt();
  while (qu--) {
    vector<string> v;
    long long n = nxt();
    for (long long i = 0; i < n; i++) {
      string s;
      cin >> s;
      v.push_back(s);
    }
    long long ans = 0;
    for (char c = 'a'; c <= 'e'; c++) {
      long long arr[n];
      for (long long i = 0; i < n; i++) {
        arr[i] = 0;
        for (auto c1 : v[i]) arr[i] += (c1 == c ? 1 : -1);
      }
      sort(arr, arr + n);
      reverse(arr, arr + n);
      long long cnt = 0;
      long long i = 0;
      while (i < n && cnt + arr[i] > 0) cnt += arr[i], i++;
      ans = max(ans, i);
    }
    cout << ans << "\n";
  }
  return 0;
}
