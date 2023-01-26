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
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
void FASTIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
template <typename P>
P pow(P x, P n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    P y = pow(x, n / 2);
    return y * y;
  } else
    return x * pow(x, n - 1);
}
long long modpow(long long x, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    long long y = modpow(x, n / 2);
    return (y * y) % 1000000007;
  } else
    return ((x % 1000000007) * modpow(x, n - 1) % 1000000007);
}
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int countBits(int number) { return (int)log2(number) + 1; }
int numlen(int a) {
  int res = 0;
  while (a > 0) {
    res++;
    a /= 10;
  }
  return res;
}
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  double ans;
  long long mx = LLONG_MIN;
  long long indx = -1;
  for (int i = 0; i < n; i++) {
    if (mx < arr[i]) {
      mx = arr[i];
      indx = i;
    }
  }
  long long other = 0;
  for (int i = 0; i < n; i++) {
    if (i != indx) other += arr[i];
  }
  ans = ((double)other / (n - 1));
  ans += mx;
  cout << fixed << setprecision(10) << ans;
  cout << endl;
}
int main() {
  FASTIO();
  int t;
  t = 1;
  cin >> t;
  for (int test = 1; test <= t; test++) {
    solve();
  }
  return 0;
}
