#include <bits/stdc++.h>
using namespace std;
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
  _print(p.first);
  cerr << ",";
  _print(p.second);
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
long long binpo(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpomo(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
void precision(int a) { cout << setprecision(a) << fixed; }
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
long long mminvprime(long long a, long long b) { return binpomo(a, b - 2, b); }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long modu(long long a, long long b) {
  if (b - a > 0) {
    return b - a;
  } else {
    return a - b;
  }
}
long long mod(long long a) {
  if (a > 0) {
    return a;
  } else {
    return -a;
  }
}
long long C(long long N, long long R) {
  if (R == 0) return 1;
  long long res = 1;
  for (int i = 1; i <= R; i++) {
    res = (res * (N - i + 1));
    res = (res / i);
  }
  return res;
}
const int MAX_SIZE = 2800001;
vector<int> isprime(MAX_SIZE, true);
vector<int> idx(MAX_SIZE);
vector<int> prime;
vector<int> SPF(MAX_SIZE);
void manipulated_seive(int N) {
  isprime[0] = isprime[1] = false;
  for (int i = 2; i < N; i++) {
    if (isprime[i]) {
      prime.push_back(i);
      SPF[i] = i;
    }
    for (int j = 0;
         j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
      isprime[i * prime[j]] = false;
      SPF[i * prime[j]] = prime[j];
    }
  }
  for (int i = 0; i < (int)prime.size(); i++) {
    idx[prime[i]] = i + 1;
  }
}
void solve() {
  long long n;
  cin >> n;
  long long a, b;
  cin >> a >> b;
  if ((a + b) > n - 2) {
    cout << -1 << "\n";
    return;
  }
  if (a > ((n - 1) / 2)) {
    cout << -1 << "\n";
    return;
  }
  if (b > ((n - 1) / 2)) {
    cout << -1 << "\n";
    return;
  }
  if (abs(a - b) > 1) {
    cout << -1 << "\n";
    return;
  }
  if (a == b) {
    vector<long long> ans(n + 1);
    for (long long i = 1; i < n + 1; i++) {
      ans[i] = i;
    }
    int i = 1;
    int j = n;
    for (long long k = 0; k < a; k++) {
      swap(ans[i], ans[j]);
      i += 2;
      j -= 2;
    }
    for (long long i = 1; i < n + 1; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }
  if (a > b) {
    long long t = a;
    vector<long long> ans(n + 1);
    for (long long i = 1; i < n + 1; i++) {
      ans[i] = i;
    }
    long long k = n;
    for (long long i = 0; i < t; i++) {
      swap(ans[k], ans[k - 1]);
      k = k - 2;
    }
    for (long long i = 1; i < n + 1; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }
  if (b > a) {
    long long t = b;
    vector<long long> ans(n + 1);
    for (long long i = 1; i < n + 1; i++) {
      ans[i] = i;
    }
    long long k = n;
    for (long long i = 0; i < t; i++) {
      swap(ans[k], ans[k - 1]);
      k = k - 2;
    }
    for (long long i = 1; i < n + 1; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
