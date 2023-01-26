#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T> gpf(T n) {
  vector<T> v;
  while (n % 2 == 0) {
    v.push_back(2ll);
    n = n / 2;
  }
  for (T i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) v.push_back(n);
  return v;
}
long long rmsb(long long n) { return n & (-n); }
long long countsetbits(long long n) {
  long long cnt = 0;
  while (n) {
    int rmb = rmsb(n);
    n -= rmb;
    cnt++;
  }
  return cnt;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool prime(long long n) {
  if (n == 1)
    return 0;
  else if (n == 2)
    return 1;
  else {
    for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return 0;
      }
    }
    return 1;
  }
}
string bin(long long n) {
  if (n == 0) return "0";
  string s = "";
  while (n > 0) {
    s += to_string(n % 2);
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long round(long long a, long long b) {
  if (a % b == 0) return a / b;
  return (a / b) + 1;
}
bool isp(long long x) { return x && (!(x & (x - 1))); }
long long roundn(long long x, long long n) {
  long long next = pow(n, ceil(log(x) / log(n)));
  if (next == x) return next;
  return next;
}
long long pw(long long x, long long n) { return ceil(log(x) / log(n)); }
bool issubstring(string s, string sb) {
  if (sb == "") return 1;
  string ss = s.substr(0, sb.length());
  if (ss == sb) return true;
  for (int i = sb.length(); i < s.length(); i++) {
    ss.erase(ss.begin());
    ss.push_back(s[i]);
    if (ss == sb) {
      return true;
    }
  }
  return false;
}
struct seg {
  int l, r, id;
  bool operator<(seg b) const {
    if (l != b.l) {
      return l < b.l;
    }
    return r > b.r;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  map<int, vector<string>> mp;
  string s = "()()";
  mp[2].push_back(s);
  mp[2].push_back("(())");
  for (int i = 3; i <= 50; i++) {
    for (auto x : mp[i - 1]) {
      mp[i].push_back(x + "()");
    }
    mp[i].push_back("(" + mp[i - 1][0] + ")");
  }
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "()\n";
      continue;
    }
    for (auto x : mp[n]) cout << x << "\n";
  }
}
