#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long int mod = 1e9 + 7;
const long long int inf = 1e18;
const long long int MX = 1e6 + 1;
const double PI = 3.141592653589793238;
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << '[';
  for (auto i = v.begin(); i != v.end(); i++)
    out << (i != v.begin() ? "," : "") << (*i);
  return (out << ']');
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& s) {
  out << '[';
  for (auto i = s.begin(); i != s.end(); i++)
    out << (i != s.begin() ? "," : "") << (*i);
  return (out << ']');
}
template <typename T>
ostream& operator<<(ostream& out, const unordered_set<T>& s) {
  out << "\n" << '[';
  for (auto i = s.begin(); i != s.end(); i++)
    out << (i != s.begin() ? "," : "") << (*i);
  return (out << ']');
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  return (out << '(' << p.first << "," << p.second << ')');
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const map<T1, T2>& m) {
  out << '{' << "\n";
  for (auto x : m) out << "  " << x.first << " -> " << x.second << "\n";
  return (out << '}');
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, const unordered_map<T1, T2>& m) {
  out << '{' << "\n";
  for (auto x : m) out << "  " << x.first << " -> " << x.second << "\n";
  return (out << '}');
}
long long int mpow(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
vector<long long int> sieve(long long int n = MX) {
  vector<long long int> P;
  vector<bool> N(n, 1);
  P.emplace_back(2);
  for (long long int i = 4; i < n; i += 2) N[i] = 0;
  for (long long int i = 3; i < n; i += 2) {
    if (N[i]) {
      P.emplace_back(i);
      for (long long int j = i * i; j < n; j += i) N[j] = 0;
    }
  }
  return P;
}
vector<long long int> primes;
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a = (a * a);
    b >>= 1;
  }
  return ans;
}
bool solution() {
  long long int n;
  cin >> n;
  cin.ignore();
  ;
  for (long long int i = 1; i < n + 1; i++) {
    for (long long int j = 0; j < i; j++) cout << '(';
    for (long long int j = 0; j < i; j++) cout << ')';
    for (long long int j = 1; j < n - i + 1; j++) cout << "()";
    cout << "\n";
  }
  return 0;
}
signed main() {
  fastio();
  long long int t = 1;
  cin >> t;
  cin.ignore();
  for (long long int caseno = 1; caseno <= t; caseno++) {
    bool ans = solution();
  }
}
