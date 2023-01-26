#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4.1")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j;
  int tct;
  cin >> tct;
  while (tct--) {
    int n;
    cin >> n;
    vector<long long> arr(n);
    vector<long long> diff(n);
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (i = 0; i < n; i++) {
      if (!i) {
        diff[i] = arr[i] - arr[n - 1];
      } else {
        diff[i] = arr[i] - arr[i - 1];
      }
    }
    long long all = (n * (n + 1)) / 2;
    long long sum = 0;
    for (i = 0; i < n; i++) {
      sum += arr[i];
    }
    long long k = sum / all;
    vector<long long> ans(n);
    int f = 1;
    for (i = 0; i < n; i++) {
      ans[i] = (k - diff[i]) / n;
      if (ans[i] < 1 or ans[i] > 1e9) f = 0;
    }
    long long c1 = 0;
    long long c2 = 0;
    for (i = 0; i < n; i++) {
      c1 += ans[i];
      c2 += all * ans[i];
    }
    if (c1 != k or c2 != sum) f = 0;
    for (i = 0; i < n; i++) {
      if (diff[i] != k - (n)*ans[i]) f = 0;
    }
    if (!f) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (auto it : ans) {
      cout << it << " ";
    }
    cout << endl;
  }
  return 0;
}
