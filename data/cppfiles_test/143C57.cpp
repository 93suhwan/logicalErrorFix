#include <bits/stdc++.h>
const int N = 2e5 + 100;
using namespace std;
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
template <typename T>
void print(const T &t) {
  cout << t << '\n';
}
template <typename T, typename... F>
void print(const T &t, const F &...f) {
  cout << t << " ";
  print(f...);
}
template <typename T>
void input_array(vector<T> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
}
template <typename T>
void print_array(const T &arr, char c = ' ') {
  for (auto x : arr) {
    cout << x << c;
  }
  cout << '\n';
}
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  file_i_o();
  startTime = clock();
  int t;
  cin >> t;
  while (t--) {
    long long n, x = -1, cnt = 0;
    cin >> n;
    map<long long, long long> mp;
    vector<long long> ans(n + 1, -1), ze, many;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      mp[a]++;
    }
    long long res = 0, f = 0;
    for (long long i = 0; i <= n; i++) {
      if (cnt < i) {
        break;
      }
      cnt += mp[i];
      ans[i] = res + mp[i];
      if (mp[i] > 1) {
        many.push_back(i);
      }
      if (mp[i] == 0) {
        if (many.size() > 0) {
          long long h = many.back();
          res += (i - h);
          mp[h]--;
          if (mp[h] == 1) {
            many.erase(many.end() - 1);
          }
        } else {
          break;
        }
      }
    }
    print_array(ans);
  }
  return 0;
}
