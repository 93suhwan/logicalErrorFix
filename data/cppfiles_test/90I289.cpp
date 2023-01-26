#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long mod2 = 998244353;
const long double pi = acos(-1);
template <typename... T>
void take_input(T &&...args) {
  ((cin >> args), ...);
}
long long input() {
  long long n;
  take_input(n);
  return n;
}
vector<long long> inputvec(long long n, long long start = 0) {
  vector<long long> vec(n);
  for (long long i = start; i < n; i++) {
    vec[i] = input();
  }
  return vec;
}
template <typename T>
bool btn(T a, T b, T c) {
  if ((a <= b && b <= c) || (a >= b && b >= c)) return true;
  return false;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << " ";
  }
  return os;
}
template <typename... T>
void print(T &&...args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
template <typename... T>
void printl(T &&...args) {
  ((cout << args << " "), ...);
}
template <typename... T, typename Q>
Q max(Q arg1, T &&...args) {
  Q ans = arg1;
  ((ans = (args > ans ? args : ans)), ...);
  return ans;
}
template <typename... T, typename Q>
Q min(Q arg1, T &&...args) {
  Q ans = arg1;
  ((ans = (args < ans ? args : ans)), ...);
  return ans;
}
long double TLD(long long n) { return TLD(n); }
long long func() {
  long long x, y;
  take_input(x, y);
  long long ans;
  if (x == y) {
    return x;
  }
  if (x > y) {
    ans = x * y + y;
  }
  if (y > x) {
    ans = (x + y) / 2;
  }
  if (ans % x == y % ans) {
    return ans;
  } else {
    cout << "x"
         << " = " << x << "\n";
    cout << "y"
         << " = " << y << "\n";
  }
  return 0;
}
int main() {
  long long t;
  take_input(t);
  for (long long start_from_0 = 0; start_from_0 != t; start_from_0++) {
    print(func());
  }
}
