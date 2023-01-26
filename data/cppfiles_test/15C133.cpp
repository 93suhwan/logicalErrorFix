#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
const long long mod = 1000000007;
const long long mod2 = 998244353;
const long double PI = 3.141592653589793238462;
template <typename T>
void sort(vector<T>& v) {
  std::sort(v.begin(), v.end());
}
template <typename T>
void sortbig(vector<T>& v) {
  std::sort(v.begin(), v.end(), greater<T>());
}
template <typename T, typename Y>
ostream& operator<<(ostream& x, const pair<T, Y>& v) {
  x << v.first << " " << v.second;
  return x;
}
template <typename T, typename Y>
ostream& operator<<(ostream& x, const map<T, Y>& v) {
  for (auto it : v) x << it.first << ": " << it.second << '\n';
  return x;
}
template <typename T, typename Y>
istream& operator>>(istream& x, pair<T, Y>& v) {
  x >> v.first >> v.second;
  return x;
}
template <typename T>
istream& operator>>(istream& x, vector<T>& v) {
  for (T& it : v) x >> it;
  return x;
}
template <typename T>
ostream& operator<<(ostream& x, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++) x << v[i] << " ";
  return x;
}
template <typename T>
ostream& operator<<(ostream& x, const set<T>& v) {
  for (auto it : v) x << it << " ";
  return x;
}
template <typename T>
ostream& operator<<(ostream& x, const multiset<T>& v) {
  for (auto it : v) x << it << " ";
  return x;
}
void print(int t) { cerr << t; }
void print(long long t) { cerr << t; }
void print(char t) { cerr << t; }
void print(long double t) { cerr << t; }
void print(double t) { cerr << t; }
void print(const string& t) { cerr << t; }
template <class T, class V>
void print(pair<T, V> p);
template <class T, class V>
void print(map<T, V> v);
template <class T, class V>
void print(pair<T, V> p) {
  cerr << "(";
  print(p.first);
  cerr << ",";
  print(p.second);
  cerr << ")";
}
template <class T, class V>
void print(map<T, V> v) {
  for (auto i : v) {
    print(i);
    cerr << " ";
  }
}
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T>
void print(multiset<T> v);
template <class T>
void print(vector<T> v) {
  for (T i : v) {
    print(i);
    cerr << " ";
  }
}
template <class T>
void print(set<T> v) {
  for (T i : v) {
    print(i);
    cerr << " ";
  }
}
template <class T>
void print(multiset<T> v) {
  for (T i : v) {
    print(i);
    cerr << " ";
  }
}
inline long long expo(long long a, long long b, long long mm) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mm;
    a = (a * a) % mm;
    b = b >> 1;
  }
  return res;
}
inline long long invprime(long long a, long long b) {
  return expo(a, b - 2, b);
}
inline long long mulmod(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long divmod(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mulmod(a, invprime(b, m), m) + m) % m;
}
void extendgcd(long long a, long long b, long long* v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
}
inline long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long invnonprime(long long a, long long b) {
  long long arr[3];
  if (gcd(a, b) != 1) {
    return -1;
  }
  extendgcd(a, b, arr);
  if (arr[0] < 0) {
    arr[0] += b;
  }
  return arr[0];
}
inline long long addmod(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
inline long long submod(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
inline long long sumOfDigits(long long n) {
  long long sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
long long nCr(long long n, long long r) {
  long long p = 1, k = 1;
  if (n - r > r) r = n - r;
  if (r == 0) return 1;
  while (r) {
    p *= n;
    k *= r;
    long long m = gcd(p, k);
    p /= m;
    k /= m;
    n--;
    r--;
  }
  return p;
}
long long nCrmod(long long n, long long r, vector<long long>& fact,
                 long long mm) {
  return divmod(fact[n], mulmod(fact[r], fact[n - r], mm), mm);
}
vector<long long> sieve(long long n) {
  long long* arr = new long long[n + 1]();
  vector<long long> v;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      v.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  delete[] arr;
  return v;
}
vector<long long> makesieve(vector<long long>& arr, long long n) {
  vector<long long> v;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      v.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return v;
}
void makefact(vector<long long>& arr, long long n, long long mm) {
  arr[0] = arr[1] = 1;
  for (long long i = 2; i <= n; i++) {
    arr[i] = arr[i - 1] * i;
    arr[i] %= mm;
  }
}
inline void google(long long x) { cout << "Case #" << x << ": "; }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  clock_t t1, t2;
  t1 = clock();
  int tc = 0, tt = 1;
  cin >> tt;
  while (tc++ < tt) {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<vector<bool>> done(n, vector<bool>(m, false));
    bool ok = true;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == '*') {
          long long sz = 0, jj = 0, ii = i;
          while (ii >= 0 and j - jj >= 0 and j + jj < m and
                 arr[ii][j - jj] == '*' and arr[ii][j + jj] == '*') {
            ii--, jj++, sz++;
          }
          if (sz - 1 >= k) {
            jj = 0, ii = i;
            while (ii >= 0 and j - jj >= 0 and j + jj < m and
                   arr[ii][j - jj] == '*' and arr[ii][j + jj] == '*') {
              done[ii][j + jj] = done[ii][j - jj] = true;
              ii--, jj++;
            }
          } else {
            if (done[i][j] == false) {
              ok = false;
              break;
            }
          }
        }
      }
      if (!ok) {
        break;
      }
    }
    ok ? cout << "YES" << '\n' : cout << "NO" << '\n';
  }
  return 0;
}
