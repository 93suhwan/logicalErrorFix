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
void Runtime_Terror() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v;
  long long cur = 1;
  for (long long i = 0; i < 35; i++) {
    v.push_back(cur);
    cur *= n;
    cur %= 1000000007;
  }
  vector<long long> bits;
  for (long long i = 0; i < 35; i++) {
    if (k & (1ll << i))
      bits.push_back(1);
    else
      bits.push_back(0);
  };
  ;
  long long ans = 0;
  for (long long i = 0; i < 35; i++) {
    if (bits[i]) {
      ans += v[i];
      ans %= 1000000007;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) Runtime_Terror();
  return 0;
}
