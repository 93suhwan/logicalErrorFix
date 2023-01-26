#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long INF = 1e18;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long idx,
               __attribute__((unused)) long long LINE_NUM) {
  cout << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long idx, long long LINE_NUM, Head H,
               Tail... T) {
  if (idx > 0)
    cout << ", ";
  else
    cout << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cout << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
template <typename T>
using min_prq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[ ";
  for (long long i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[ ";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[ ";
  for (auto it : v) os << it << ", ";
  os << " ]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  os << "{ ";
  for (auto it : v) os << it.first << " : " << it.second << ", ";
  os << " }\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const multimap<T, S>& v) {
  os << "{ ";
  for (auto it : v) os << it.first << " : " << it.second << ", ";
  os << " }\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, priority_queue<T> p) {
  os << "[ ";
  while (!p.empty()) {
    os << p.top() << " ,";
    p.pop();
  }
  os << " ]\n";
  return os;
}
namespace number_theory {
long long gcd(long long a, long long b) {
  long long c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
long long modpow(long long a, long long p = M - 2, long long MOD = M) {
  long long result = 1;
  while (p > 0) {
    if (p & 1) {
      result = a * result % MOD;
    }
    a = a * a % MOD;
    p >>= 1;
  }
  return result;
}
long long ncr(long long n, long long k) {
  long long ans = 1;
  if (k > n - k) {
    k = n - k;
  }
  for (long long(i) = (1); (i) <= (k); ++(i)) {
    ans *= (n - i + 1);
    ans /= i;
  }
  return ans;
}
}  // namespace number_theory
using namespace number_theory;
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
void solve() {
  long long k;
  cin >> k;
  if (isPerfectSquare(k)) {
    cout << sqrt(k) << " " << 1;
  } else {
    long long low = sqrt(k), high = low + 1;
    low *= low;
    high *= high;
    long long x = 1;
    long long y = sqrt(low) + 1;
    for (long long i = low + 1; i <= high - 1; i++) {
      if (i == k) {
        cout << x << " " << y;
        return;
      } else {
        if (x < y) {
          x++;
        } else {
          y--;
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  for (long long(T) = (1); (T) <= (t); ++(T)) {
    solve();
    cout << "\n";
  }
  return 0;
}
