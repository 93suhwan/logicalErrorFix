#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '[';
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <class T>
T ABS(const T &x) {
  return x > 0 ? x : -x;
}
long long int gcd(long long int n1, long long int n2) {
  return n2 == 0 ? ABS(n1) : gcd(n2, n1 % n2);
}
long long int lcm(long long int n1, long long int n2) {
  return n1 == 0 && n2 == 0 ? 0 : ABS(n1 * n2) / gcd(n1, n2);
}
long long int ceil2(long long int a, long long int b) {
  return (a + b - 1) / b;
}
template <typename T>
bool chmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool chmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
vector<T> sorttrunq(vector<T> vec) {
  sort(vec.begin(), vec.end()),
      vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
void solve() {
  long long int h, w;
  cin >> h >> w;
  long long int area = 0;
  for (int i = 0; i < 4; ++i) {
    int sz;
    cin >> sz;
    vector<long long int> p(sz);
    cin >> p;
    area = max(area, (p[sz - 1] - p[0]) * ((i < 2) ? w : h));
  }
  cout << area << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
