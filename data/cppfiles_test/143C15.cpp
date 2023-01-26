#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long idx,
               __attribute__((unused)) long long LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long idx, long long LINE_NUM, Head H,
               Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
long long dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
long long dx4[] = {0, 0, 1, -1};
long long dy4[] = {1, -1, 0, 0};
const long long MOD = 1000000007;
double sq(double x) { return x * x; }
template <typename T>
inline T Bigmod(T base, T power, T MOD) {
  T ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
inline void normal(long long &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long modMul(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long modAdd(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long modSub(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, MOD - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
bool sortinrev(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.first > b.first);
}
void solution() {
  long long n;
  cin >> n;
  vector<long long> arr(n), cnt(n + 1);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }
  sort(arr.begin(), arr.end());
  stack<long long> st;
  vector<long long> ans(n + 1, -1);
  long long sum = 0;
  for (long long i = 0; i <= n; i++) {
    if (i > 0 && cnt[i - 1] == 0) {
      if (st.empty()) {
        break;
      }
      long long x = st.top();
      st.pop();
      sum += i - x - 1;
    }
    ans[i] = sum + cnt[i];
    while (i > 0 && cnt[i - 1] > 1) {
      cnt[i - 1]--;
      st.push(i - 1);
    }
  }
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
