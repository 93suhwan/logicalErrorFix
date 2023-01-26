#include <bits/stdc++.h>
using namespace std;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
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
vector<long long> BIT;
void updateBIT(long long index, long long val) {
  index++;
  while (index < BIT.size()) {
    BIT[index] += val;
    index += (index & (-index));
  }
}
long long get_sum(long long index) {
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
  unordered_map<long long, long long, custom_hash> mp;
  for (long long i = 0; i < n; i++) {
    if (!mp.count(b[i])) mp[b[i]] = k++;
  }
  for (long long i = 0; i < n; i++) a[i] = mp[a[i]];
  long long r = *max_element(a.begin(), a.end());
  for (long long i = 0; i <= r; i++) BIT[i] = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long x = get_sum(a[i] - 2);
    long long y = get_sum(r - 1) - get_sum(a[i] - 1);
    ans += max(0ll, min(x, y));
    updateBIT(a[i] - 1, 1);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long ok = 1;
  BIT.resize(2e5 + 1, 0);
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
