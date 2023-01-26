#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265359;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(rng);
}
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
void print(vector<long long> v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i + 1 != v.size()) cout << ", ";
  }
  cout << "]" << endl;
}
void print(pair<long long, long long> p) {
  cout << "{" << p.first << ", " << p.second << "}" << endl;
}
const long long MOD = 998244353;
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long ultdp = v[0];
  long long soma = v[0];
  for (long long i = 1; i < n; i++) {
    ultdp = (v[i] * ultdp - soma) % MOD;
    soma = ultdp;
  }
  cout << (ultdp + MOD) % MOD << '\n';
}
