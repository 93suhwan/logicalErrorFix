#include <bits/stdc++.h>
using namespace std;
constexpr long long int mod = 1e9 + 7;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
int myrand(int mod) { return (int)((((double)rand() / RAND_MAX) * (mod))); }
template <typename T, typename U>
void operator%=(T &a, const U &m) {
  if (abs(a) >= m) a %= m;
  if (a < 0) a += m;
}
template <typename T, typename U>
T operator%(T &a, const U &m) {
  T b = a;
  b %= m;
  return b;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a) {
  for (int i = int(0); i < int((int)a.size()); i++) out << a[i] << " ";
  out << "\n";
  return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &a) {
  for (int i = int(0); i < int((int)a.size()); i++) in >> a[i];
  return in;
}
template <typename T, typename U>
T pow2(const T &x, const U &y) {
  T res = 1, X = x;
  U Y = y;
  while (Y > 0) {
    if (Y & 1) res *= X;
    Y >>= 1;
    X *= X;
    X %= mod;
    res %= mod;
  }
  return res;
}
pair<long long int, long long int> operator-(
    pair<long long int, long long int> &a,
    pair<long long int, long long int> &b) {
  return {a.first - b.first, a.second - b.second};
}
pair<long long int, long long int> operator+(
    pair<long long int, long long int> &a,
    pair<long long int, long long int> &b) {
  return {a.first + b.first, a.second + b.second};
}
void solve() {
  int n;
  cin >> n;
  vector<long long int> a(n);
  cin >> a;
  long long int N = n * (n + 1) / 2;
  long long int sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum % N != 0) {
    cout << "NO\n";
    return;
  }
  sum /= N;
  vector<long long int> res(n);
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    long long int c = a[j] - a[i];
    res[j] = sum - c;
    if (res[j] <= 0 || res[j] % n != 0) {
      cout << "NO\n";
      return;
    } else {
      res[j] /= n;
    }
  }
  cout << "YES\n";
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
