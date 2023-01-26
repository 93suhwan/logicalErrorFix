#include <bits/stdc++.h>
using namespace std;
int main() {
  auto time = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long tt = 1; tt <= t; ++tt) {
    long long n;
    cin >> n;
    std::vector<long long> arr(n);
    for (long long i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long flag = 1;
    long long prev_eq = 0;
    long long prev_val = 0;
    multiset<long long> extras;
    for (long long i = 0; i <= n; ++i) {
      long long ct = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
      if (ct < i || flag == 0) {
        cout << "-1 ";
        flag = 0;
        continue;
      }
      auto tot_eq = equal_range(arr.begin(), arr.end(), i);
      long long eq_ele = tot_eq.second - tot_eq.first;
      if (i == 0) {
        cout << eq_ele << " ";
        prev_eq = eq_ele;
        prev_val = eq_ele;
        for (long long j = 1; j < eq_ele; ++j) {
          extras.insert(0);
        }
        continue;
      }
      long long checker =
          lower_bound(arr.begin(), arr.end(), i - 1) - arr.begin();
      if (checker >= arr.size()) {
        checker = i + 1;
      } else {
        checker = arr[checker];
      }
      if (checker == i - 1) {
        long long val = prev_val - prev_eq + eq_ele;
        prev_eq = eq_ele;
        prev_val = val;
        cout << val << " ";
      } else {
        auto it = extras.end();
        it--;
        long long temp = *(it);
        long long val = prev_val - prev_eq + eq_ele + (i - 1 - temp);
        prev_eq = eq_ele;
        prev_val = val;
        cout << val << " ";
        extras.erase(it);
      }
      for (long long j = 1; j < eq_ele; ++j) {
        extras.insert(i);
      }
    }
    cout << endl;
  }
  return 0;
}
