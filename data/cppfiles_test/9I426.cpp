#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void rotate(vector<int> arr, int n) {
  int x = arr[n - 1], i;
  for (i = n - 1; i > 0; i--) arr[i] = arr[i - 1];
  arr[0] = x;
}
void showlist(list<int> g) {
  list<int>::iterator it;
  for (it = g.begin(); it != g.end(); it++) cout << *it << " ";
  cout << "\n";
}
bool compare_function(string& s1, string& s2) {
  return (s1.length() > s2.length());
}
void showvec(vector<int> v) {
  vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
}
void showset(set<int> s) {
  set<int>::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
}
void swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}
bool isPrime(int n) {
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int findNextPrime(int n) {
  int nextPrime = n;
  bool found = false;
  while (!found) {
    nextPrime++;
    if (isPrime(nextPrime)) found = true;
  }
  return nextPrime;
}
int largest(int arr[], int n) { return *max_element(arr, arr + n); }
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
vector<long long> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
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
template <class T>
T gcd(T a, T b) {
  while (a != 0) {
    T temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}
template <class T>
T egcd(T a, T b, T& x, T& y) {
  T gcd, xt, yt;
  if (a == 0) {
    gcd = b;
    x = 0, y = 1;
  } else {
    gcd = egcd(b % a, a, xt, yt);
    x = yt - (b / a) * xt;
    y = xt;
  }
  return gcd;
}
template <class T>
T expo(T base, T exp, T mod) {
  T res = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
template <class T>
T modinv(T a, T mod) {
  T x, y;
  egcd<T>(a, mod, x, y);
  while (x < 0) x += mod;
  while (x >= mod) x -= mod;
  return x;
}
template <class T>
T modinvfermat(T a, T mod) {
  return expo<T>(a, mod - 2, mod);
}
template <class T>
bool rev(T a, T b) {
  return a > b;
}
template <class T>
long long maxpower(T a, T b) {
  long long ans = 0;
  while (a > 0 && a % b == 0) {
    ans++;
    a /= b;
  }
  return ans;
}
template <class T>
T mceil(T a, T b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
template <class T>
T lcm(T a, T b) {
  return (a * b) / gcd<T>(a, b);
}
const long long infl = 1e18;
const int inf = 1e9 + 5;
void solve() {
  string s;
  cin >> s;
  int flag = 0;
  int n = s.size();
  if (n == 1) {
    cout << 0;
  } else {
    for (long long i = (long long)(1); i < (long long)(n); i++) {
      if (s[0] != s[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << 1;
    } else
      cout << n / 2;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start = high_resolution_clock::now();
  cout << setprecision(15);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  return 0;
}
