#include <bits/stdc++.h>
using namespace std;
long long mi(long long n, long long m) {
  long long pw = n % m;
  long long ex = m - 2;
  long long ans = 1;
  while (ex) {
    if (ex & 1) ans = ans * pw % m;
    pw = pw * pw % m;
    ex >>= 1;
  }
  return ans % 1000000007;
}
long long pw(long long a, long long n) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  long long pw = a;
  long long ex = n;
  long long ans = 1;
  while (ex) {
    if (ex & 1) ans = ans * pw;
    pw = pw * pw;
    ex >>= 1;
  }
  return ans;
}
long long pwm(long long a, long long n) {
  long long pw = a % 1000000007;
  long long ex = n;
  long long ans = 1;
  while (ex) {
    if (ex & 1) ans = (ans % 1000000007 * pw % 1000000007) % 1000000007;
    pw = (pw % 1000000007 * pw % 1000000007) % 1000000007;
    ex >>= 1;
  }
  return ans % 1000000007;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long max2(long long a, long long b) { return a > b ? a : b; }
long long min2(long long a, long long b) { return a < b ? a : b; }
long long max3(long long a, long long b, long long c) {
  return max2(a, max2(b, c));
}
long long min3(long long a, long long b, long long c) {
  return min2(a, min2(b, c));
}
long long ceil(long long a, long long b) { return a / b + (a % b != 0); }
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
long long X[] = {2, 1, -1, -2, -2, -1, 1, 2};
long long Y[] = {1, 2, 2, 1, -1, -2, -2, -1};
struct comp {
  bool operator()(const pair<long long, long long>& a,
                  const pair<long long, long long>& b) const {
    if (a.second > b.second) return true;
    return false;
  }
};
static bool comp(string a, string b) {
  string aa = a + b;
  string bb = b + a;
  return aa.compare(bb) < 0;
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long x = (r + 1) / 2;
  if (r % 2 == 0) x++;
  if (x >= l) {
    cout << r % x;
  } else {
    cout << r % l;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
