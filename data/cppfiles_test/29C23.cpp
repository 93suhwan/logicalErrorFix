#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  cin >> x;
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(A* x, int size) {
  for (int i = (0); (1) > 0 ? i < (size) : i > (size); i += (1)) read(x[i]);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class T>
void print(T& x) {
  cout << x << ' ';
}
template <class H, class... T>
void print(H h, T... t) {
  print(h);
  print(t...);
}
template <class A>
void print(A* x, int size) {
  for (int i = (0); (1) > 0 ? i < (size) : i > (size); i += (1)) print(x[i]);
  cout << '\n';
}
template <class A>
void print(vector<A>& x) {
  for (auto& a : x) print(a);
}
template <class H, class... T>
void debug(H h, T... t) {
  print(h, t...);
  cout << endl;
}
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int N = 200010, mod = 1e9 + 7;
void solve() {
  long long sum = 0, one = 0, zero = 0;
  int n, val;
  read(n);
  for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1)) {
    read(val);
    sum += val;
    one += (val == 1);
    zero += (val == 0);
  }
  if (sum == 0)
    cout << 0 << '\n';
  else if (sum == 1)
    cout << (1LL << zero) << '\n';
  else
    cout << (1LL << zero) * one << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _t;
  cin >> _t;
  while (_t--) solve();
}
