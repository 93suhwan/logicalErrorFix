#include <bits/stdc++.h>
using namespace std;
const auto LAMBDA_TRUE = [](long long int) { return true; };
const auto LAMBDA_FALSE = [](long long int) { return false; };
long long int _fastXOR(const long long int &_n) {
  if (_n % 4 == 0) return _n;
  if (_n % 4 == 1) return 1;
  if (_n % 4 == 2) return _n + 1;
  return 0;
}
long long int _fastSUM(const long long int &_n) { return ((1 + _n) * _n) / 2; }
long long int _ceil(const long long int &_v1, const long long int &_v2) {
  return (_v1 + _v2 - 1) / _v2;
}
template <class T>
pair<T, T> _min_v(
    const vector<T> &_v,
    const std::function<bool(const T &)> &_cmpv = LAMBDA_TRUE,
    const std::function<bool(const T &)> &_cmpi = LAMBDA_TRUE) noexcept {
  pair<T, T> r;
  r.first = numeric_limits<long long int>::max();
  for (size_t i = 0; i < _v.size(); i++)
    if (_v[i] < r.first && _cmpv(_v[i]) && _cmpi(i)) {
      r.first = _v[i];
      r.second = i;
    }
  return r;
}
template <class T>
pair<T, T> _max_v(
    const vector<T> &_v,
    const std::function<bool(const T &)> &_cmpv = LAMBDA_TRUE,
    const std::function<bool(const T &)> &_cmpi = LAMBDA_TRUE) noexcept {
  pair<T, T> r;
  r.first = numeric_limits<long long int>::min();
  for (size_t i = 0; i < _v.size(); i++)
    if (_v[i] > r.first && _cmpv(_v[i]) && _cmpi(i)) {
      r.first = _v[i];
      r.second = i;
    }
  return r;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long int d = a[0];
  long long int ma = a[0];
  for (long long int i = 1; i < n; i++) {
    a[i] -= d;
    d += a[i];
    ma = max(a[i], ma);
  }
  cout << ma << endl;
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
