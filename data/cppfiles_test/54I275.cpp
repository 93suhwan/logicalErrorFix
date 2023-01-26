#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
vector<char*> tokenizer(const char* args) {
  char* token = new char[111];
  strcpy(token, args);
  token = strtok(token, ", ");
  vector<char*> v({token});
  while (token = strtok(NULL, ", ")) v.push_back(token);
  return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*> args) { cerr << "\b "; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
  debug() << " [" << args.back() << ": " << H << "] ";
  args.pop_back();
  debugg(args, T...);
}
const double PI = acos(-1);
const long long mod = 1e9 + 7;
long long bin_pow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
vector<long long> dp;
long long sol(long long& n, long long k) {
  if (k == 1) {
    if (n % 2 == 0)
      return bin_pow(2, n - 1);
    else
      return 1 + bin_pow(2, n - 1);
  }
  if (dp[k] != -1) return dp[k];
  dp[k] = 0;
  if (n % 2 == 0) {
    dp[k] += sol(n, k - 1);
    dp[k] %= mod;
    dp[k] += (((bin_pow(2, n - 1) - 1 + mod) % mod) * sol(n, k - 1)) % mod;
    dp[k] %= mod;
  } else {
    dp[k] += bin_pow(2, k * n - n);
    dp[k] %= mod;
    dp[k] += (bin_pow(2, n - 1) * sol(n, k - 1)) % mod;
    dp[k] %= mod;
  }
  return dp[k];
}
int32_t main() {
  int test = 1;
  cin >> test;
  while (test--) {
    long long n, k;
    cin >> n >> k;
    dp = vector<long long>(k + 1, -1);
    dp[0] = 1;
    cout << sol(n, k) << "\n";
  }
  return 0;
}
