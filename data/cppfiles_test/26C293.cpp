#include <bits/stdc++.h>
const int N = 100001, M = 998244353, mod = 1000000007;
const long long MX = INT64_MAX, MN = INT64_MIN, oo = 1e18;
using namespace std;
vector<string> tokenizer(string str, char ch) {
  std::istringstream var((str));
  vector<string> v;
  string t;
  while (getline((var), t, (ch))) {
    v.emplace_back(t);
  }
  return v;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void put(T&&... args) {
  ((cout << args << " "), ...);
}
void file_i_o() {
  freopen("./tests/test01.txt", "r", stdin);
  freopen("./tests/output01.txt", "w", stdout);
}
long long expm(long long a, long long b, long long m = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = ((res % m) * (a % m)) % m;
    }
    b /= 2;
    a = ((a % m) * (a % m)) % m;
  }
  return res;
}
void solve(int T) {
  long long n;
  read(n);
  long long ans = 1;
  for (int i = 2; i < 2 * n + 1; i++) ans = (ans * i) % mod;
  {
    put((ans * expm(2, mod - 2)) % mod);
    cout << "\n";
  }
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i < t + 1; i++) {
    solve(t);
  }
  return 0;
}
