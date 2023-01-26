#include <bits/stdc++.h>
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
void _print(long long int x) { cerr << x; }
void _print(long x) { cerr << x; }
void _print(unsigned x) { cerr << x; }
void _print(unsigned long x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(const char *x) { cerr << '\"' << x << '\"'; }
void _print(const string &x) { cerr << '\"' << x << '\"'; }
void _print(bool x) { cerr << (x ? "true" : "false"); }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(unordered_set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
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
void _print(unordered_set<T> v) {
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) cin >> it;
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) cout << it << " ";
  return ostream;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int expo(long long int a, long long int n) {
  long long int ans = 1;
  while (n) {
    if (n & 1) {
      ans *= a;
    }
    a *= a;
    n >>= 1;
  }
  return ans;
}
long long int expo(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
bool tc = 1;
const long long int MOD = 1000000007;
const long long int N = 2e5 + 1;
const long double eps = 1e-9;
void preSolve() {}
void solve() {
  string a, b;
  cin >> a >> b;
  long long int n1 = (long long int)a.size(), n2 = (long long int)b.size();
  long long int i = n1 - 1, j = n2 - 1;
  string ans;
  if (stoll(a) > stoll(b)) {
    cout << -1 << "\n";
    return;
  }
  while (i >= 0 and j >= 0) {
    if (b[j] >= a[i]) {
      long long int x = b[j] - a[i];
      char ch = (char)((long long int)'0' + x);
      ans = ch + ans;
      j--;
      i--;
    } else {
      if (j == 0) {
        cout << -1 << "\n";
        return;
      }
      long long int num = (b[j - 1] - '0') * 10 + (b[j] - '0');
      long long int x = a[i] - '0';
      long long int y = num - x;
      if (y > 9) {
        cout << -1 << "\n";
        return;
      }
      ans = to_string(y) + ans;
      j -= 2;
      i--;
    }
    if (j <= -1 and i >= 0) {
      cout << -1 << "\n";
      return;
    }
    if (j >= 0 and i <= -1) {
      ans = b.substr(0, j + 1) + ans;
    }
  }
  long long int x = stoll(ans);
  string tmp;
  long long int A = stoll(a);
  while (A > 0 or x > 0) {
    tmp = to_string(A % 10 + x % 10) + tmp;
    A /= 10;
    x /= 10;
  }
  if (tmp != b) {
    cout << -1 << "\n";
    return;
  }
  cout << stoll(ans) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  preSolve();
  long long int t = 1;
  if (tc) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
