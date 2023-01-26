#include <bits/stdc++.h>
const int P = 998244353;
using namespace std;
template <class T>
using vector2D = vector<vector<T>>;
template <class T>
using vector3D = vector<vector2D<T>>;
template <class T>
using pque = priority_queue<T>;
template <class T>
using heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
bool umax(T &x, T y) {
  return (x < y) ? x = y, true : false;
}
template <class T>
bool umin(T &x, T y) {
  return (x > y) ? x = y, true : false;
}
void prepare() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int maxn = 200005;
int n;
long long a[maxn];
long long flag = 1;
long long pre[maxn];
long long suf[maxn];
int main() {
  prepare();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  pre[0] = suf[n + 1] = 1;
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] * a[i] % P;
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] * a[i] % P;
  long long ans = pre[n];
  for (int len = 2; len <= n; len++) {
    long long cur = 0;
    for (int i = 1; i + len - 1 <= n; i++) {
      long long mn = a[i];
      for (int j = i; j < i + len; j++) mn = min(mn, a[j]);
      cur = (cur + mn * pre[i - 1] % P * suf[i + len]) % P;
    };
    flag = P - flag;
    ans = (ans + cur * flag) % P;
  }
  cout << ans << endl;
  return 0;
}
