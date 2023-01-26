#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(vector<T> &arr) {
  for (auto &x : arr) cin >> x;
}
template <class T>
void read2d(vector<vector<T>> &arr) {
  for (auto &x : arr)
    for (auto &y : x) cin >> y;
}
template <class T>
void write(const T &t) {
  cout << t << "\n";
}
template <class T>
void printArray(const vector<T> &arr) {
  for (auto x : arr) cout << x << ' ';
  cout << "\n";
}
void test_case() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  read(arr);
  vector<long long> ans(n, 0);
  unordered_map<long long, long long> m;
  for (long long i = 0; i < n; ++i) {
    if (m.find(arr[i]) == m.end()) {
      m[arr[i]]++;
      ans[i] = 1;
    } else {
      if (m[arr[i]] >= k) {
        continue;
      } else {
        m[arr[i]]++;
        ans[i] = m[arr[i]];
      }
    }
  }
  printArray(ans);
}
int32_t main(int32_t args, char **argc) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    test_case();
  }
  return 0;
}
