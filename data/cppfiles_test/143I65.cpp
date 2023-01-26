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
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  long long ind[n + 1];
  long long freq[n + 1];
  memset(freq, 0, sizeof(freq));
  for (long long i = 0; i <= n; i++) ind[i] = -1;
  for (long long i = 0; i < n; i++) {
    if (ind[arr[i]] == -1) {
      ind[arr[i]] = i;
    }
    freq[arr[i]]++;
  }
  long long last = n + 1;
  stack<long long> st;
  long long add = 0;
  long long z = 0;
  for (long long i = 0; i <= n; i++) {
    long long index = lower_bound(arr, arr + n, i) - arr;
    if (index < i) {
      cout << "-1 ";
      last = i + 1;
      break;
    }
    cout << freq[i] + add << " ";
    if (freq[i] > 1) {
      st.push(i);
    }
    if (freq[i] == 0) {
      if (st.empty() && z != 0) {
        cout << "-1 ";
        last = i + 1;
        break;
      }
      long long x;
      if (st.empty() && z == 0) {
        continue;
      }
      x = st.top();
      st.pop();
      long long fx = freq[x];
      add += (i - x);
      fx--;
      if (fx > 1) {
        st.push(x);
      }
    }
  }
  for (long long i = last; i <= n; i++) {
    cout << "-1 ";
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
