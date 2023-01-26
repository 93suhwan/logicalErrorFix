#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> sorted_arr(arr.begin(), arr.end());
    sort(begin(sorted_arr), end(sorted_arr));
    unordered_map<int, int> next_adjacent_value;
    for (int i = 0; i < n; i++)
      next_adjacent_value[sorted_arr[i]] = sorted_arr[i + 1];
    next_adjacent_value[sorted_arr.back()] = 1e6;
    long long break_cnt = 1;
    int index = 0;
    while (index < n - 1) {
      while (index < n - 1 and arr[index] < arr[index + 1] and
             arr[index + 1] == next_adjacent_value[arr[index]])
        ++index;
      if (index == n - 1) break;
      ++break_cnt;
      ++index;
    }
    if (break_cnt <= k)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
