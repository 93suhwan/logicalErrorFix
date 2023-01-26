#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  if (v.size() == 0) {
    os << "empty vector\n";
    return os;
  }
  for (auto element : v) os << element << " ";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, pair<T, second>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& v) {
  if (v.size() == 0) {
    os << "empty set\n";
    return os;
  }
  auto endit = v.end();
  endit--;
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    os << *it;
    if (it != endit) os << ", ";
  }
  os << "]";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, multiset<T>& v) {
  if (v.size() == 0) {
    os << "empty multiset\n";
    return os;
  }
  auto endit = v.end();
  endit--;
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    os << *it;
    if (it != endit) os << ", ";
  }
  os << "]";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, map<T, second>& v) {
  if (v.size() == 0) {
    os << "empty map\n";
    return os;
  }
  auto endit = v.end();
  endit--;
  os << "{";
  for (auto it = v.begin(); it != v.end(); it++) {
    os << "(" << (*it).first << " : " << (*it).second << ")";
    if (it != endit) os << ", ";
  }
  os << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<vector<T>>& v) {
  for (auto& subv : v) {
    for (auto& e : subv) os << e << " ";
    os << "\n";
  }
  return os;
}
bool do_debug = false;
long long n, k;
vector<long long> v;
vector<long long> fact(50010), ifact(50010);
long long power(long long x, long long n) {
  if (!n) return 1;
  if (n % 2)
    return (x * (power((x * x) % 998244353, n / 2) % 998244353)) % 998244353;
  return power((x * x) % 998244353, n / 2) % 998244353;
}
long long inverse(long long n) {
  return power(fact[n], 998244353 - 2) % 998244353;
}
void pre_factorials() {
  fact[0] = 1;
  for (long long i = 1; i < 50010; i++) fact[i] = (fact[i - 1] * i) % 998244353;
  for (long long i = 0; i < 50010; i++) ifact[i] = inverse(i);
}
long long ncr(long long n, long long r) {
  if (n < r)
    return 0;
  else if (n == r)
    return 1;
  else if (r == 0)
    return 0;
  long long ans = fact[n];
  ans = (ans * ifact[r]) % 998244353;
  ans = (ans * ifact[n - r]) % 998244353;
  return ans;
}
vector<vector<long long>> ps(5010, vector<long long>(2));
long long cal(long long left, long long right) {
  long long len = right - left + 1;
  long long zero = ps[right][0] - ps[left - 1][0];
  long long one = len - zero;
  long long ans = fact[len];
  ans *= (ifact[one]);
  ans %= 998244353;
  ans *= (ifact[zero]);
  ans %= 998244353;
  return ans;
}
void Runtime_Terror() {
  cin >> n >> k;
  string s;
  cin >> s;
  vector<long long> one;
  one.push_back(0);
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '1') one.push_back(i + 1);
    ps[i + 1] = ps[i];
    if (s[i] == '1')
      ps[i + 1][1]++;
    else
      ps[i + 1][0]++;
  }
  one.push_back(n + 1);
  long long sz = one.size() - 2;
  if (sz < k || k == 0) {
    cout << 1 << "\n";
    return;
  };
  ;
  long long ans = 0;
  for (long long i = 1; i < sz - k + 2; i++) {
    long long left = one[i - 1] + 1;
    long long right = one[i + k] - 1;
    ans += cal(left, right);
    ans %= 998244353;
    if (i != sz - k + 1) {
      long long tem = cal(one[i] + 1, one[i + k] - 1);
      ans = (ans + (998244353 - tem)) % 998244353;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  pre_factorials();
  for (long long i = 0; i < t; i++) Runtime_Terror();
  return 0;
}
