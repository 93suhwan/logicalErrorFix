#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(bool t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
bool revsort(long long a, long long b) { return a > b; }
void precision(long long a) { cout << setprecision(a) << fixed; }
long long fact(long long i) {
  if (i <= 1)
    return 1;
  else
    return i * fact(i - 1);
}
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = i * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
string decToBin(long long n) {
  string s = "";
  long long i = 0;
  while (n > 0) {
    s = to_string(n % 2) + s;
    n = n / 2;
    i++;
  }
  return s;
}
long long binToDec(string n) {
  string num = n;
  long long dec_value = 0;
  long long base = 1;
  long long len = num.length();
  for (long long i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
long long mpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = 1;
  a %= 1000000007;
  while (b) {
    if (b & 1) {
      res = (res * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long madd(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a + b) % 1000000007) + 1000000007) % 1000000007;
}
long long msub(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a - b) % 1000000007) + 1000000007) % 1000000007;
}
long long mmul(long long a, long long b) {
  a = a % 1000000007;
  b = b % 1000000007;
  return (((a * b) % 1000000007) + 1000000007) % 1000000007;
}
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (auto &val : v) {
    cin >> val;
  }
  if (v[0] % 2 == 0) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
