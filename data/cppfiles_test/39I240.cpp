#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << "{ ";
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << " }";
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << " ";
  for (auto &i : x) cerr << (f++ ? " , " : ""), __print(i);
  cerr << " ";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
clock_t time_p = clock();
void timer() {
  time_p = clock() - time_p;
  cerr << "\nTime Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "sec\n";
}
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
void google(long long t) { cout << "Case #" << t << ": "; }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
vector<long long> factorial(2e5 + 1);
void f_factorial() {
  factorial[0] = 1, factorial[1] = 1;
  for (long long i = 2; i <= 2e5; i++) {
    factorial[i] = factorial[i - 1] * i;
    factorial[i] %= 1000000000 + 7;
  }
}
long long bimult(long long a, long long b, long long m) {
  long long res = 0;
  while (b) {
    if (b & 1) {
      res = (res + a) % m;
    }
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}
long long biexp(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a;
      res %= m;
    }
    a = a * a;
    a %= m;
    b >>= 1;
  }
  return res;
}
long long ncr(long long a, long long b, long long m) {
  long long res = bimult(factorial[a], biexp(factorial[b], m - 2, m), m);
  res = bimult(res, biexp(factorial[a - b], m - 2, m), m);
  return res;
}
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
inline long long ceil(long long a, long long b) {
  return (a % b == 0) ? a / b : a / b + 1;
}
long long set_bits(long long n) {
  long long cnt = 0;
  while (n) {
    n -= n & -n;
    cnt++;
  }
  return cnt;
}
void pr_vi(vector<long long> &arr, long long i, long long n) {
  cout << "[ ";
  for (; i <= n; i++) cout << arr[i] << " ";
  cout << "]\n";
}
vector<long long> pri(2000000 + 10);
void prime_factorization() {
  for (long long i = 2; i <= 2000000 + 5; i++) pri[i] = -1;
  pri[1] = 1;
  for (long long i = 2; i <= 2000000 + 5; i++) {
    if (pri[i] == -1) {
      for (long long j = i; j <= 2000000 + 5; j += i) {
        if (pri[j] == -1) {
          pri[j] = i;
        }
      }
    }
  }
}
vector<long long> pfactors(long long n) {
  vector<long long> res;
  while (pri[n] != 1) {
    res.push_back(pri[n]);
    n = n / pri[n];
  }
  return res;
}
vector<long long> factor_Count(2000000 + 10, 0);
void pf_count() {
  for (long long i = 2; i <= 2000000 + 2; i++) {
    if (factor_Count[i] == 0) {
      for (long long j = i; j <= 2000000 + 2; j += i) {
        factor_Count[j]++;
      }
    }
  }
}
bool isprime(long long n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
priority_queue<long long, vector<long long>, greater<long long>> pq;
string S1 = "abcdefghijklmnopqrstuvwxyz";
string S2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
long long interact(long long i, long long n) {
  cout << "? ";
  for (long long j = 1; j <= n - 1; j++) cout << i << " ";
  cout << n << "\n";
  long long te;
  cin >> te;
  cout.flush();
  return te;
}
void spidy() {
  long long n;
  cin >> n;
  long long a = -1;
  for (long long i = 1; i <= n; i++) {
    long long te = interact(i, n);
    if (te != 0) {
      a = i;
      break;
    }
  };
  if (a == -1) a = n;
  vector<long long> ans(n + 1);
  ans[n] = a;
  for (long long i = 1; i <= n; i++) {
    if (i != a) {
      long long x = interact(i, n);
      ans[x] = i;
    }
  }
  cout << "! ";
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
}
int main() {
  long long t = 1;
  while (t--) {
    spidy();
  }
  timer();
  return 0;
}
