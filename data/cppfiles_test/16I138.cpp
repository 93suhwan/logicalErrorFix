#include <bits/stdc++.h>
using namespace std;
int GCD(int A, int B) { return (B == 0) ? A : GCD(B, A % B); }
int LCM(int A, int B) { return A * B / GCD(A, B); }
const int mod = 1e9 + 7;
int power(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = (res * 1ll * a) % mod;
    n = n >> 1;
    a = (a * 1ll * a) % mod;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<pair<int, int>> arr;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] > 0) {
      arr.push_back({v[i], i + 1});
      sum += v[i];
    }
  }
  sort(arr.begin(), arr.end());
  if (arr.size() <= 1) {
    cout << 0 << "\n";
    return;
  }
  int size = arr.size();
  long long extra = arr[size - 1].first;
  sum -= extra;
  int j = 0;
  while (extra < sum) {
    sum -= arr[j].first;
    extra += arr[j].first;
    j++;
  }
  multiset<pair<int, int>> a, b;
  for (int i = 0; i < j; i++) b.insert(arr[i]);
  b.insert(arr[size - 1]);
  for (int i = j; i < size - 1; i++) a.insert(arr[i]);
  vector<pair<int, int>> res;
  while (a.size() && b.size()) {
    auto x = *a.begin();
    auto y = *b.begin();
    a.erase(a.begin());
    b.erase(b.begin());
    if (x.first < y.first) {
      int t = x.first;
      while (t--) {
        res.push_back({x.second, y.second});
      }
      b.insert({y.first - x.first, y.second});
    } else if (x.first > y.first) {
      int t = y.first;
      while (t--) {
        res.push_back({y.second, x.second});
      }
      a.insert({x.first - y.first, x.second});
    } else {
      int t = x.first;
      while (t--) {
        res.push_back({y.second, x.second});
      }
    }
  }
  cout << res.size() << "\n";
  for (auto e : res) cout << e.first << " " << e.second << "\n";
}
int main() {
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
