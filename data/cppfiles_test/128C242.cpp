#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
struct custom_hash {
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return x + FIXED_RANDOM;
  }
};
long long binaryExponential(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans % 1000000007 * a % 1000000007) % 1000000007;
    }
    a = (a % 1000000007 * a % 1000000007) % 1000000007;
    b >>= 1;
  }
  return ans;
}
void seive() {
  vector<long long> prime(10000007, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i <= 10000007; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= 10000007; j += i) prime[j] = 0;
    }
  }
}
bool isprime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long g, x, y;
void extendedEuclid(long long a, long long b) {
  if (b == 0) {
    g = a;
    x = 1;
    y = 0;
  } else {
    extendedEuclid(b, a % b);
    long long temp = x;
    x = y;
    y = temp - (a / b) * y;
  }
}
long long ETF(long long n) {
  long long ans = n;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      ans = (ans / i) * (i - 1);
    }
    while (n % i == 0) n /= i;
  }
  if (n > 1) {
    ans = (ans / n) * (n - 1);
  }
  return ans;
}
long long factors(long long n) {
  long long count = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      count++;
      if (n / i != i) {
        count++;
      }
    }
  }
  return count;
}
double myPow(double x, int n) {
  if (n == 0) return 1.00000;
  if (n < 0) {
    return (n % 2 == 0) ? 1.00000 / myPow(x * x, abs(n / 2))
                        : 1.000 / (x * myPow(x * x, abs(n / 2)));
  } else {
    return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
  }
}
bool isUnique(vector<long long> &v) {
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); i++) {
    if (v[i] == v[i + 1]) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void solution() {
  long long n;
  cin >> n;
  vector<int> ans{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  for (auto &x : ans) {
    if ((n - x - 1) % x != 0) {
      cout << n - x - 1 << ' ' << x << ' ' << 1 << "\n";
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  cout << fixed << setprecision(12);
  while (t--) {
    solution();
  }
  return 0;
}
