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
  long long n, d;
  cin >> n >> d;
  vector<long long> v(n + 1);
  for (long long i = 1; i < n + 1; i++) cin >> v[i];
  map<long long, long long> m;
  map<long long, long long> rev;
  for (long long i = 1; i < n + 1; i++) {
    m[i] = (i + n - d) % n;
    if (m[i] == 0) m[i] = n;
    long long tem = (i + n - d) % n;
    if (tem == 0) tem = n;
    rev[tem] = i;
  }
  vector<pair<long long, long long>> calc(n + 1);
  set<long long> s;
  for (long long i = 1; i < n + 1; i++) {
    calc[i].first = v[i];
    calc[i].second = v[m[i]];
    pair<long long, long long> p;
    p.first = 1;
    p.second = 0;
    if (calc[i] == p) s.insert(i);
  }
  long long ans = 0;
  set<long long> next;
  ;
  ;
  ;
  long long cnt = 0;
  while (1) {
    cnt++;
    if (cnt > 5) break;
    ;
    if (s.size() == 0) break;
    for (auto x : s) {
      long long index = x;
      calc[index].first = 0;
      long long nindex = rev[index];
      calc[nindex].second = 0;
      pair<long long, long long> p;
      p.first = 1;
      p.second = 0;
      if (calc[nindex] == p) next.insert(nindex);
    }
    ans++;
    s.clear();
    s = next;
    next.clear();
  }
  for (long long i = 1; i < n + 1; i++) {
    if (calc[i].first == 1) {
      cout << -1 << "\n";
      return;
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
