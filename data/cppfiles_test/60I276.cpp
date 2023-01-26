#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int mod1 = 998244353;
const long long int inf = 9e18 + 5;
const double pi = acosl(-1.0l);
const long double eps = 1e-9;
void _print(long long int t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(long double t) { cout << t; }
void _print(double t) { cout << t; }
void _print(unsigned long long t) { cout << t; }
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
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
void swap(long long int &a, long long int &b) {
  long long int t = a;
  a = b;
  b = t;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int add(long long int a, long long int b) {
  long long int t = a + b;
  if (t >= mod) {
    return t -= mod;
  }
  return t;
}
long long int sub(long long int a, long long int b) {
  return (a - b + mod) % mod;
}
long long int mul(long long int a, long long int b) { return (a * b) % mod; }
long long int power(long long int a, long long int b) {
  a %= mod;
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
long long int modInverse(long long int a) { return power(a, mod - 2); }
const int mx = 4e5 + 4;
vector<long long int> edges[mx];
int indegree[mx];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int sum = 0;
    map<long long int, long long int> mp;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      mp[a[i]]++;
    }
    if (sum % n != 0) {
      cout << "0\n";
      continue;
    }
    sum /= n;
    sum *= 2;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      long long int left = sum - a[i];
      if ((sum - a[i]) == a[i]) {
        ans += mp[a[i]] - 1;
      } else {
        ans += mp[left];
      }
    }
    cout << ans / 2 << "\n";
  }
}
