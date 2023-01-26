#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool umax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
const int mxN = 1e7 + 5;
int d[mxN], s[mxN], ret[mxN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int l = 0, r = n - 1;
  vector<int> v(n);
  for (auto& x : v) cin >> x;
  while (l + 1 < n && v[l] < v[l + 1]) {
    ++l;
  }
  while (r - 1 >= 0 && v[r] < v[r - 1]) {
    --r;
  }
  if ((l + 1) & 1 || (n - r) & 1) {
    cout << "Alice"
         << "\n";
  } else {
    cout << "Bob"
         << "\n";
  }
  return 0;
}
