#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  if (v.size() == 0) {
    os << "empty vector\n";
    return os;
  }
  for (auto element : v) os << element << " ";
  return os;
}
template <typename T, typename second>
ostream &operator<<(ostream &os, pair<T, second> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &v) {
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
ostream &operator<<(ostream &os, multiset<T> &v) {
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
ostream &operator<<(ostream &os, map<T, second> &v) {
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
ostream &operator<<(ostream &os, vector<vector<T>> &v) {
  for (auto &subv : v) {
    for (auto &e : subv) os << e << " ";
    os << "\n";
  }
  return os;
}
bool do_debug = false;
long long n, k;
vector<long long> v;
pair<long long, long long> solve(long long index, long long removed) {
  if (index == n + 1) return {0, -1};
  pair<long long, long long> ans;
  long long tem1 = solve(index + 1, removed + 1).first;
  long long tem2;
  if (v[index] == index - removed) {
    tem2 = solve(index + 1, removed).first + 1;
  } else
    tem2 = solve(index + 1, removed).first;
  ans.first = max(tem1, tem2);
  if (ans.first == tem2) {
    if (v[index] == index - removed)
      ans.second = max(solve(index + 1, removed).second, index);
    else
      ans.second = solve(index + 1, removed).second;
  } else
    ans.second = solve(index + 1, removed + 1).second;
  return ans;
}
void Runtime_Terror() {
  cin >> n >> k;
  v.resize(n + 1);
  for (long long i = 1; i < n + 1; i++) cin >> v[i];
  long long mini = 1e8;
  bool ans = false;
  for (long long i = 1; i < n + 1; i++) {
    if (solve(i, i - 1).first >= k) {
      long long temans = i - 1;
      long long len = solve(i, i - 1).second - i + 1;
      long long val = v[solve(i, i - 1).second];
      temans += len - val;
      mini = min(mini, temans);
    }
  }
  if (mini < 1e8)
    cout << mini << "\n";
  else
    cout << -1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) Runtime_Terror();
  return 0;
}
