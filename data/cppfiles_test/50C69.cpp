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
int top;
long long mul, add;
long long num[maxn];
long long stk[maxn];
long long sum;
long long power(long long a, long long b, long long c = P) {
  long long r = 1;
  for (r %= c, a %= c; b; b >>= 1, a = a * a % c)
    if (b & 1) r = r * a % c;
  return r;
}
int main() {
  prepare();
  int n;
  long long y;
  cin >> n;
  cin >> y;
  top = 1;
  mul = 1;
  add = 0;
  sum = y;
  stk[1] = y;
  num[1] = 1;
  for (int i = 2; i <= n; i++) {
    long long x;
    cin >> x;
    if (x <= y) {
      long long sum0 = sum;
      while (x < stk[top]) {
        long long l = max(x, stk[top - 1]);
        sum = (sum - (num[top] * mul + add) % P * (stk[top] - l) % P + P) % P;
        --top;
      }
      if (x > stk[top]) {
        ++top;
        stk[top] = x;
      }
      add *= -1;
      mul *= -1;
      sum *= -1;
      add = (add + sum0) % P;
      sum = (sum + sum0 * x) % P;
    } else {
      long long sum0 = sum;
      add *= -1;
      mul *= -1;
      sum *= -1;
      add = (add + sum0) % P;
      sum = (sum + sum0 * x) % P;
      stk[++top] = x;
      num[top] = (sum0 - add) * power(mul, P - 2) % P;
    }
    y = x;
  }
  cout << ((sum + P) % P + P) % P << endl;
  return 0;
}
