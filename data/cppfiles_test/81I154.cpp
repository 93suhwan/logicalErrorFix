#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b);
template <typename T>
T manhatten(T x, T y, T ox = 0, T oy = 0);
template <typename T, typename N>
T power(T x, N y, int m = (long long)(1e9 + 7));
template <typename T>
T getClosest(T val, multiset<T>& s);
template <typename T>
void read(vector<vector<T>>& arr);
template <typename T>
void read(vector<T>& arr);
template <typename T>
void print(vector<vector<T>>& arr, string e = "\n", string s = "");
template <typename T>
void print(vector<T>& arr, string e = " ", string s = "");
template <typename T>
T gcd(T a, T b) {
  if (b == T(0)) return a;
  return gcd<T>(b, a % b);
}
template <typename T>
T manhatten(T x, T y, T ox, T oy) {
  return abs(x - ox) + abs(y - oy);
}
template <typename T, typename N>
T power(T x, N y, int m) {
  T res = 1;
  x %= m;
  while (y > 0) {
    if (y & 1) res = (res * x) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return res;
}
template <typename T>
T getClosest(T val, multiset<T>& s) {
  auto resItr = s.lower_bound(val);
  if (resItr == s.end()) return *s.rbegin();
  if (*resItr == val || s.size() == 1) return val;
  auto prevItr = prev(resItr, 1);
  return (abs(val - *prevItr) > abs(val - *resItr)) ? *resItr : *prevItr;
}
template <typename T>
void read(vector<vector<T>>& arr) {
  int n = (int)arr.size();
  for (int i = 0; i < n; i++) {
    read(arr[i]);
  }
}
template <typename T>
void read(vector<T>& arr) {
  int n = (int)arr.size();
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
template <typename T>
void print(vector<T>& arr, string e, string s) {
  for (int i = 0; i < arr.size(); i++) {
    cout << s << arr[i] << e;
  }
}
template <typename T>
void print(vector<vector<T>>& arr, string e, string s) {
  for (int i = 0; i < arr.size(); i++) {
    print(arr[i], e, s);
    cout << endl;
  }
}
struct comb {
  int n;
  vector<long long> fac, invfac;
  comb(int n) : n(n) { init(); }
  void init() {
    fac.assign(n + 1, 0);
    invfac.assign(n + 1, 0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
      fac[i] = (fac[i - 1] * i) % (long long)(1e9 + 7);
    invfac[n] = power(fac[n], (long long)(1e9 + 7) - 2);
    for (int i = n - 1; i >= 0; i--)
      invfac[i] = (invfac[i + 1] * (i + 1)) % (long long)(1e9 + 7);
  }
  long long choose(int n, int x) {
    if (x < 0 || n < 0 || n < x) return 0LL;
    long long tmp = (invfac[x] * invfac[n - x]) % (long long)(1e9 + 7);
    return (fac[n] * tmp) % (long long)(1e9 + 7);
  }
};
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
void flip(char& c) { c = (c - '0') ^ 1 + '0'; }
void probA() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<vector<int>> qs(q, vector<int>(2, 0));
  read(qs);
  vector<int> pre(n + 1);
  for (int i = 0; i < n; i++) {
    int val = s[i] == '+' ? 1 : (-1);
    pre[i + 1] = pre[i] + ((i % 2) ? (-1) : 1) * val;
  }
  for (int i = 0; i < q; i++) {
    int l = qs[i][0] - 1, r = qs[i][1] - 1;
    int val = pre[r + 1] - pre[l];
    if (val == 0)
      cout << 0;
    else if ((r - l + 1) % 2)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
void probB() {}
void probC() {}
void probD() {}
void probE() {}
void probF() {}
int main() {
  int T = 1;
  cin >> T;
  for (int t = 0; t < T; t++) {
    probA();
  }
  return 0;
}
