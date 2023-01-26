#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int power(int a, int b, int m) {
  if (a == 0 and b == 0) return 1;
  if (a == 0) return 0;
  if (b == 0) return 1;
  if (b == 1) return a;
  int x = power(a, b / 2, m);
  x = (1ll * x * x) % m;
  if (b % 2 == 1) {
    x = (1ll * x * a) % m;
  }
  return x;
}
int k, a, h;
void print(vector<int> &_1, vector<int> &_2) {
  vector<int> ans((1 << k) + 1);
  for (int j = 0, l = k - 2; j < (1 << k) / 2; l--) {
    if (l == -1) {
      ans[_1[j++]] = 1;
      break;
    }
    int r = (1 << l);
    int v = r * 2 + 1;
    while (r--) {
      ans[_1[j++]] = v;
    }
  }
  for (int j = 0, l = k - 2; j < (1 << k) / 2; l--) {
    if (l == -1) {
      ans[_2[j++]] = 2;
      break;
    }
    int r = (1 << l);
    int v = r * 2 + 1;
    while (r--) {
      ans[_2[j++]] = v;
    }
  }
  for (int i = 1; i < int(ans.size()); i++) cout << ans[i] << " ";
  cout << '\n';
}
int calc_hash(vector<int> &_1) {
  long long ans = 0;
  for (int j = 0, l = k - 2; j < (1 << k) / 2; l--) {
    if (l == -1) {
      ans += (1ll * _1[j++] * power(a, 2, mod)) % mod;
      ans %= mod;
      break;
    }
    int r = (1 << l);
    int v = r * 2 + 1;
    while (r--) {
      ans += (1ll * _1[j++] * power(a, v, mod)) % mod;
      ans %= mod;
    }
  }
  return ans;
}
set<int> x;
void calc(vector<vector<int>> &res, vector<int> arr, vector<int> b, int ans,
          int _t) {
  int _n = int(arr.size());
  if (_n == 1) {
    b.push_back(arr[0]);
    b.push_back(ans);
    res.push_back(b);
    return;
  }
  int v = (1 << _t) + 1;
  int s = int(b.size());
  for (int i = 0; i < (1 << (_n / 2)); i++) {
    vector<int> _arr;
    int _ans = ans;
    for (int j = 0; j < _n / 2; j++) {
      int _cand;
      int __cand;
      if ((1 << j) & i)
        _cand = arr[2 * j + 1], __cand = arr[2 * j];
      else
        _cand = arr[2 * j], __cand = arr[2 * j + 1];
      _arr.push_back(_cand);
      _ans = (1ll * _ans + (1ll * __cand * power(a, v, mod)) % mod) % mod;
      b.push_back(__cand);
    }
    calc(res, _arr, b, _ans, _t - 1);
    while (int(b.size()) > s) b.pop_back();
  }
}
void solve() {
  cin >> k >> a >> h;
  int ans = 0;
  if (k <= 4) {
    vector<vector<int>> _1;
    vector<int> arr1((1 << k));
    for (int i = 0; i < (1 << k); i++) arr1[i] = i + 1;
    calc(_1, arr1, vector<int>{}, ans, k - 1);
    for (int i = 0; i < int(_1.size()); i++) {
      int _h = (1ll * _1[i].back() +
                (1ll * _1[i][int(_1[i].size()) - 2] * power(a, 1, mod)) % mod) %
               mod;
      if (_h == h) {
        vector<int> ans((1 << k) + 1);
        for (int j = 0, l = k - 1; j < (1 << k); l--) {
          if (l == -1) {
            ans[_1[i][j++]] = 1;
            break;
          }
          int r = (1 << l);
          int v = r + 1;
          while (r--) {
            ans[_1[i][j++]] = v;
          }
        }
        for (int j = 1; j < int(ans.size()); j++) cout << ans[j] << " ";
        cout << '\n';
        return;
      }
    }
  } else {
    vector<vector<int>> _1, _2;
    vector<int> arr1(16), arr2(16);
    for (int i = 0; i < 16; i++) arr1[i] = i + 1, arr2[i] = i + 17;
    calc(_1, arr1, vector<int>{}, ans, 4);
    calc(_2, arr2, vector<int>{}, ans, 4);
    map<int, int> _m;
    for (int i = 0; i < int(_2.size()); i++) {
      _m[(1ll * _2[i].back() +
          (1ll * _2[i][int(_2[i].size()) - 2] * power(a, 2, mod)) % mod) %
         mod] = i;
    }
    for (int i = 0; i < int(_1.size()); i++) {
      int _h = (1ll * _1[i].back() +
                (1ll * _1[i][int(_1[i].size()) - 2] * power(a, 1, mod)) % mod) %
               mod;
      int _h2 = _h;
      _h = (h - _h + mod) % mod;
      if (_m.find(_h) != _m.end()) {
        print(_1[i], _2[_m[_h]]);
        return;
      }
    }
    _m.clear();
    for (int i = 0; i < int(_2.size()); i++) {
      _m[(1ll * _2[i].back() +
          (1ll * _2[i][int(_2[i].size()) - 2] * power(a, 1, mod)) % mod) %
         mod] = i;
    }
    for (int i = 0; i < int(_1.size()); i++) {
      int _h = (1ll * _1[i].back() +
                (1ll * _1[i][int(_1[i].size()) - 2] * power(a, 2, mod)) % mod) %
               mod;
      _h = (h - _h + mod) % mod;
      if (_m.find(_h) != _m.end()) {
        print(_2[_m[_h]], _1[i]);
        return;
      }
    }
  }
  cout << -1 << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
