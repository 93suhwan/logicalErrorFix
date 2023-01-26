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
  long long n;
  cin >> n;
  vector<string> s(n);
  read(s);
  vector<vector<long long>> freq(n, vector<long long>(6, 0));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < s[i].size(); ++j) {
      freq[i][s[i][j] - 'a']++;
    }
    for (long long j = 0; j < 5; ++j) {
      freq[i][5] += freq[i][j];
    }
  }
  long long ans = 0;
  for (long long a = 0; a < 5; ++a) {
    vector<long long> arr;
    for (long long i = 0; i < n; ++i) {
      arr.push_back(freq[i][a] - (freq[i][5] - freq[i][a]));
    }
    sort(arr.begin(), arr.end(), greater<long long>());
    long long d = 0;
    long long cnt = 0;
    for (auto x : arr) {
      d += x;
      if (d > 0) {
        cnt++;
      } else {
        break;
      }
    }
    ans = max(ans, cnt);
  }
  write(ans);
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
