#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "[";
  os << p.first;
  os << ", ";
  os << p.second;
  os << "]";
  return os;
}
int solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << n - 1 << " " << n << "\n";
  } else
    cout << "-" << n - 1 << " " << n << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest;
  cin >> ntest;
  for (int test = 0; test < ntest; ++test) {
    solve();
  }
  return 0;
}
