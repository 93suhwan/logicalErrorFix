#include <bits/stdc++.h>
using namespace std;
const int N = (int)(1e6) + 322;
const long long INF = 2e18 + 17;
const int inf = 2e9;
const int mod = 1000000007;
const double eps = 1e-9;
template <typename T>
void pop_front(vector<T>& vec) {
  assert(!vec.empty());
  vec.erase(vec.begin());
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int nbr_bits(int a) { return log2(a) + 1; }
int fastpow(int a, int n, int mod) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    int res = fastpow(a, n / 2, mod);
    res *= res;
    res %= mod;
    return res;
  }
  int res = (fastpow(a, n - 1, mod) * a) % mod;
  return res;
}
int p[N];
stack<string> answers;
int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}
bool bubleSort(vector<int> v, int n) {
  int ans = 0;
  int m = (n * (n - 1)) / 2;
  for (int i = 0; i <= n - 1; ++i) {
    for (int j = 0; j <= n - 2; ++j) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
        ans++;
      }
    }
  }
  if (ans < m)
    return true;
  else
    return false;
}
vector<pair<long long, long long> > stock;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2 == 1) {
      cout << "No" << endl;
      continue;
    }
    if (s.size() == 2 && s[0] == s[1]) {
      cout << "Yes" << endl;
      continue;
    } else {
      string s1 = s.substr(0, s.size() / 2);
      string s2 = s.substr(s.size() / 2, s.size() / 2);
      if (s1 == s2)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
