#include <bits/stdc++.h>
using namespace std;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
template <typename T, typename U>
T max(T a, U b) {
  if (a > b) return a;
  return b;
}
template <typename T, typename U>
T min(T a, U b) {
  if (a < b) return a;
  return b;
}
void assign_mx(long long &a, long long &b) {
  long long x = max(a, b);
  long long y = min(a, b);
  a = x;
  b = y;
}
template <typename T, typename U>
void oned(vector<T> &A, U n) {
  for (long long i = 0; i < n; ++i) {
    long long val;
    cin >> val;
    A.push_back(val);
  }
  return;
}
template <typename T, typename U, typename F>
void twod(vector<vector<T>> &A, U n, F m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long val;
      cin >> val;
      A[i].push_back(val);
    }
  }
  return;
}
void istr(string &str) {
  getline(cin, str);
  return;
}
void estr() {
  string temp;
  getline(cin, temp);
  return;
}
template <typename T>
void print1d(vector<T> v) {
  long long n = v.size();
  for (long long i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
  return;
}
template <typename T>
void print2d(vector<vector<T>> v) {
  long long n = v.size();
  for (long long i = 0; i < n; i++) {
    print1d(v[i]);
  }
  return;
}
long long power(long long base, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2) res = (res * base) % mod1;
    base = base * base % mod1;
    p /= 2;
  }
  return res % mod1;
}
vector<long long> fact;
void facorials() {
  fact.resize((1e5) + 1, 1);
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i <= (1e5); i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
}
void updateBIT(long long index, long long val, vector<long long> &BIT) {
  index++;
  while (index < BIT.size()) {
    BIT[index] += val;
    index += (index & (-index));
  }
}
long long get_sum(long long index, vector<long long> &BIT) {
  index++;
  long long sum = 0;
  while (index > 0) {
    sum += BIT[index];
    index -= (index & (-index));
  }
  return sum;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a;
  oned(a, n);
  vector<long long> b = a;
  sort((b).begin(), (b).end());
  long long k = 1;
  unordered_map<long long, long long> mp;
  b.erase(unique((b).begin(), (b).end()), b.end());
  long long r = b.size();
  long long ans = 0;
  vector<long long> bit;
  bit.resize(r + 1, 0);
  for (long long i = 0; i < n; i++) {
    a[i] = lower_bound((b).begin(), (b).end(), a[i]) - b.begin() + 1;
    long long x = get_sum(a[i] - 2, bit);
    long long y = get_sum(r - 1, bit) - get_sum(a[i] - 1, bit);
    ans += max(0ll, min(x, y));
    updateBIT(a[i] - 1, 1, bit);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long ok = 1;
  ok = 0;
  if (ok)
    solve();
  else {
    long long t;
    cin >> t;
    while (t--) {
      solve();
      cout << '\n';
    }
  }
}
