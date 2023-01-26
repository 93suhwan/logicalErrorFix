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
    int n, x = -1, cnt = 0;
    cin >> n;
    map<int, int> mp;
    vector<int> ans(n + 1, -1), ze, many;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mp[a]++;
    }
    int res = 0, f = 0;
    for (int i = 0; i <= n; i++) {
      if (cnt < i) {
        break;
      }
      cnt += mp[i];
      if (ze.size() > 0) {
        for (int a : ze) {
          auto k = lower_bound(many.begin(), many.end(), a);
          int y = k - many.begin() - 1;
          int h = many[y];
          res += (a - h);
          ze.erase(find(ze.begin(), ze.end(), a));
          mp[h]--;
          if (mp[h] == 1) {
            many.erase(find(many.begin(), many.end(), h));
          }
        }
      }
      if (mp[i] == 0) {
        ze.push_back(i);
      } else if (mp[i] > 1) {
        many.push_back(i);
      }
      ans[i] = res + mp[i];
      if (f == 0 && ans[i] == 0) {
        f = 1;
        res = 0;
      }
      if (f == 0) {
        res = 0;
      }
    }
    print_array(ans);
  }
  return 0;
}
