#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
int mx = 1e9;
const long long inf = 1e18;
int get_mod(int a, int m) { return (a % m + m) % m; }
long long int add(long long int x, long long int y) {
  long long int res = x + y;
  return (res >= mod) ? res % mod : res;
}
long long int mul(long long int x, long long int y) {
  long long int res = x * y;
  return (res >= mod) ? res % mod : res;
}
long long int subs(long long int x, long long int y) {
  long long int res = x - y;
  return (res >= mod) ? res % mod : res;
}
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if ((b & 1) == 0) {
      a = mul(a, a);
      b = b >> 1;
    } else {
      res = mul(res, a);
      b = b - 1;
    }
  }
  return res;
}
void solve() {
  int n, k;
  cin >> n >> k;
  list<int> arr, temp;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    arr.push_back(t);
  }
  int t = k;
  arr.sort();
  temp = arr;
  int ans = 0;
  while (arr.size() > 0 && k > 0) {
    int d = arr.front();
    arr.pop_front();
    auto it = upper_bound(arr.begin(), arr.end(), d);
    int f = 0;
    if (it != arr.end()) {
      f = *it;
      arr.erase(it);
    } else {
      f = arr.back();
      arr.pop_back();
    }
    ans += (d / f);
    k--;
  }
  while (arr.size() > 0) {
    ans += arr.back();
    arr.pop_back();
  }
  int count = 0;
  while (temp.size() > 0 && t > 0) {
    int d = temp.back();
    temp.pop_back();
    int f = temp.back();
    temp.pop_back();
    count += d / f;
    t--;
  }
  while (temp.size() > 0) {
    count += temp.back();
    temp.pop_back();
  }
  cout << min(count, ans) << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
