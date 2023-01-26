#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
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
bool prime(long long n) {
  if (n < 2) return false;
  for (long long x = 2; x * x <= n; x++) {
    if (n % x == 0) return false;
  }
  return true;
}
vector<long long> sieve(long long n) {
  long long* arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
string decimalToBinary(long long n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
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
  return;
}
long long __gcd(long long a, long long b) {
  if (b > a) {
    return __gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return __gcd(b, a % b);
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
long long check(long long k, vector<long long>& a) {
  long long count = k;
  for (long long i = 0; i < ((long long)(a).size() - 1); ++i) {
    if (a[i] + k <= a[i + 1]) {
      count += k;
    } else {
      count += a[i + 1] - a[i];
    }
  }
  return count;
}
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> a(n);
  for (long long i = 0; i < (n); ++i) {
    cin >> a[i];
  }
  long long i = 0;
  long long j = INF;
  long long ans = INT_MAX;
  while (i <= j) {
    long long mid = i + (j - i) / 2;
    long long find = check(mid, a);
    if (find == h) {
      ans = mid;
      break;
    }
    if (find > h) {
      ans = mid;
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
