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
long long dp[2010][2010];
long long solve(long long index, long long done, long long maxi) {
  if (index == n) {
    if (v[index] == index - done)
      return 1;
    else
      return 0;
  }
  if (dp[index][done] != -1) return dp[index][done];
  if (done == maxi) {
    if (v[index] == index - done)
      return dp[index][done] = solve(index + 1, done, maxi) + 1;
    else
      return dp[index][done] = solve(index + 1, done, maxi);
  }
  long long tem1 = solve(index + 1, done + 1, maxi);
  long long tem2;
  if (v[index] == index - done) {
    tem2 = solve(index + 1, done, maxi) + 1;
  } else
    tem2 = solve(index + 1, done, maxi);
  return dp[index][done] = max(tem1, tem2);
}
long long max_val = 0;
bool f(long long mid) {
  for (long long i = 0; i < n + 2; i++)
    for (long long j = 0; j < mid + 2; j++) dp[i][j] = -1;
  long long tem = solve(1, 0, mid);
  if (tem < k)
    return false;
  else
    return true;
}
void Runtime_Terror() {
  cin >> n >> k;
  v.resize(n + 1);
  for (long long i = 1; i < n + 1; i++) cin >> v[i];
  long long l = 0, r = n;
  if (f(0)) {
    cout << 0 << "\n";
    return;
  }
  if (f(n) == 0) {
    cout << -1 << "\n";
    return;
  }
  while (l <= r) {
    long long mid = (l + r) / 2;
    bool b1 = f(mid), b2 = f(mid + 1);
    if (!b1 && b2) {
      cout << mid + 1 << "\n";
      return;
    }
    if (b1)
      r = mid;
    else
      l = mid + 1;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) Runtime_Terror();
  return 0;
}
