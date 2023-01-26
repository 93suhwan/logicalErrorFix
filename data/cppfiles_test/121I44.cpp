#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void _deb(long long int t) { cerr << t; }
void _deb(int t) { cerr << t; }
void _deb(string t) { cerr << t; }
void _deb(char t) { cerr << t; }
void _deb(double t) { cerr << t; }
template <class T, class V>
void _deb(pair<T, V> p);
template <class T>
void _deb(vector<T> v);
template <class T>
void _deb(set<T> v);
template <class T, class V>
void _deb(map<T, V> v);
template <class T>
void _deb(multiset<T> v);
template <class T, class V>
void _deb(pair<T, V> p) {
  cerr << "{";
  _deb(p.first);
  cerr << ",";
  _deb(p.second);
  cerr << "}";
}
template <class T>
void _deb(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _deb(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _deb(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _deb(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _deb(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _deb(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _deb(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _deb(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long int mod = 1e9 + 7;
const long long int maxN = 2e5 + 1;
const long long int inf = 1e9;
const long long int INF = 1e16;
long long int gcd(long long int a, long long int b);
long long int lcm(long long int a, long long int b);
bool isPrime(long long int n);
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b);
void sieve();
long long int modExp(long long int b, long long int n);
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int good_ones = 0, good_zeroes = 0, bad_ones = 0, bad_zeroes = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] == '1')
      a[i] == b[i] ? good_ones++ : bad_ones++;
    else
      a[i] == b[i] ? good_zeroes++ : bad_zeroes++;
  }
  bool ok = (good_zeroes == 0 || good_ones == 0) &&
            (bad_zeroes == 0 || bad_ones == 0);
  int ans = 0;
  map<pair<pair<int, int>, pair<int, int> >, bool> mp;
  while (1) {
    int x = good_ones + good_zeroes;
    int y = bad_ones + bad_zeroes;
    pair<pair<int, int>, pair<int, int> > q;
    q.first.first = good_ones;
    q.first.second = bad_ones;
    q.second.first = good_zeroes;
    q.second.second = bad_zeroes;
    if (x == n) {
      cout << ans << endl;
      return;
    }
    if (mp[q]) break;
    mp[q] = true;
    ok = (good_zeroes == 0 || good_ones == 0) &&
         (bad_zeroes == 0 || bad_ones == 0);
    if (x <= y && good_ones) {
      swap(good_ones, bad_zeroes);
      swap(good_zeroes, bad_ones);
      good_ones++;
      bad_zeroes--;
    } else if (bad_ones) {
      swap(bad_ones, good_zeroes);
      swap(bad_zeroes, good_ones);
      bad_ones++;
      good_zeroes--;
    } else
      break;
    ans++;
  }
  cout << -1 << endl;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  }
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool isPrime(long long int n) {
  if (!(n & 1) && n > 2) return false;
  for (long long int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
void sieve() {}
long long int modExp(long long int b, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = (res * b) % mod;
    n >>= 1;
    b = (b * b) % mod;
  }
  return res;
}
