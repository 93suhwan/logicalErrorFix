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
template <typename T>
istream &operator>>(istream &is, vector<T> &arr) {
  typename vector<T>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    is >> *a;
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &arr) {
  typename vector<T>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    os << *a << " ";
  }
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
  os << p.first << " " << p.second << '\n';
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, vector<pair<T1, T2>> &arr) {
  typename vector<pair<T1, T2>>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    os << *a;
  }
  return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, vector<pair<T1, T2>> &arr) {
  typename vector<pair<T1, T2>>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    is >> *a;
  }
  return is;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<bool> isprime(2e5 + 10, true);
vector<long long int> lp(2e5 + 10), hp(2e5 + 10);
void sieve() {
  isprime[0] = isprime[1] = false;
  for (long long int i = 2; i < 2e5 + 10; i++) {
    if (isprime[i] == true) {
      for (long long int j = 2 * i; j < 2e5 + 10; j += i) {
        isprime[j] = false;
        hp[j] = i;
        if (lp[j] == 0) lp[j] = i;
      }
    }
  }
}
long long int add(long long int a, long long int b) {
  return ((a % 1000000007) + (b % 1000000007)) % 1000000007;
}
long long int sub(long long int a, long long int b) {
  return ((a % 1000000007) - (b % 1000000007) + 1000000007) % 1000000007;
}
long long int mul(long long int a, long long int b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long int mpow(long long int x, long long int y) {
  long long int res = 1;
  x = x % 1000000007;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
void solve() {
  long long int n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  vector<long long int> v;
  long long int cnt = 0, acnt = 0;
  for (long long int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      v.push_back(-1);
      acnt++;
    } else {
      while (s[i] == '*' && i < n) {
        cnt++;
        i++;
      }
      v.push_back(cnt * k);
      cnt = 0;
      if (i != n) i--;
    }
  }
  n = v.size();
  string ans = "";
  if (x == 1) {
    for (long long int i = 0; i < acnt; ++i) ans += "a";
    cout << ans << "\n";
    return;
  }
  x--;
  for (long long int i = n - 1; i >= 0; i--) {
    if (v[i] == -1) {
      ans = "a" + ans;
    } else {
      string temp = "";
      long long int rem = x % (v[i] + 1);
      x = x / (v[i] + 1);
      for (long long int j = 0; j < rem; ++j) temp += "b";
      ans = temp + ans;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
