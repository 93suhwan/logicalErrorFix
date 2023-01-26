#include <bits/stdc++.h>
using namespace std;
unsigned power(unsigned long long x, unsigned long long y,
               unsigned long long p) {
  unsigned res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
std::vector<pair<int, int>> arr(100000, {1e9 + 3, 1e9 + 3});
std::vector<pair<int, int>> brr(100000, {1e9 + 3, 1e9 + 3});
int b_search(int prev, int val, int n) {
  int mid = (n - 1) / 2;
  int left = 0;
  int right = n - 1;
  if (prev == 0) {
    while (left <= right) {
      mid = (left + right) / 2;
      if (arr[mid].first == val)
        return mid;
      else if (arr[mid].first > val)
        left = mid + 1;
      else
        right = mid - 1;
    }
  } else {
    while (left <= right) {
      mid = (left + right) / 2;
      if (brr[mid].first == val)
        return mid;
      else if (brr[mid].first > val)
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  return mid;
}
bool comp(pair<int, int> &a, pair<int, int> &b) { return (a.first > b.first); }
int main() {
  auto time = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int flag = 1;
    int prev_eq = 0;
    int prev_val = 0;
    multiset<int> extras;
    for (int i = 0; i <= n; ++i) {
      int ct = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
      if (ct < i || flag == 0) {
        cout << "-1 ";
        flag = 0;
        continue;
      }
      auto tot_eq = equal_range(arr.begin(), arr.end(), i);
      int eq_ele = tot_eq.second - tot_eq.first;
      if (i == 0) {
        cout << eq_ele << " ";
        prev_eq = eq_ele;
        prev_val = eq_ele;
        for (int j = 1; j < eq_ele; ++j) {
          extras.insert(0);
        }
        continue;
      }
      int checker = lower_bound(arr.begin(), arr.end(), i - 1) - arr.begin();
      if (checker >= arr.size()) {
        checker = i + 1;
      } else {
        checker = arr[checker];
      }
      if (checker == i - 1) {
        int val = prev_val - prev_eq + eq_ele;
        prev_eq = eq_ele;
        prev_val = val;
        cout << val << " ";
      } else {
        auto it = extras.end();
        it--;
        int temp = *(it);
        int val = prev_val - prev_eq + eq_ele + (i - 1 - temp);
        prev_eq = eq_ele;
        prev_val = val;
        cout << val << " ";
        extras.erase(it);
      }
      for (int j = 1; j < eq_ele; ++j) {
        extras.insert(i);
      }
    }
    cout << endl;
  }
  return 0;
}
