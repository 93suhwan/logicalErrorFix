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
vector<long long> par(300100), siz(300100);
long long find_root(long long node) {
  if (par[node] == node)
    return node;
  else
    return par[node] = find_root(par[node]);
}
void merge_sets(long long a, long long b) {
  long long x = find_root(a);
  long long y = find_root(b);
  if (x == y) return;
  if (siz[x] < siz[y]) swap(x, y);
  par[y] = x;
  siz[x] += siz[y];
}
long long calc(vector<long long>& before, vector<long long>& after) {
  long long n = before.size();
  for (long long i = 0; i < 300100; i++) {
    par[i] = i;
    siz[i] = 1;
  }
  for (long long i = 0; i < before.size(); i++) {
    merge_sets(before[i], after[i]);
  }
  set<long long> s;
  for (long long i = 0; i < n; i++) s.insert(par[i]);
  return (n - s.size());
}
void Runtime_Terror() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    cin >> v[i];
  };
  vector<long long> cnt(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    if (i >= v[i]) {
      cnt[i - v[i] + 1]++;
    } else {
      long long tem = v[i] - i;
      cnt[n - tem + 1]++;
    }
  }
  long long mini = n - 2 * m;
  vector<long long> ans;
  for (long long i = 1; i < n + 1; i++) {
    if (cnt[i] >= mini) {
      vector<long long> before(n), after(n);
      for (long long j = 1; j < n + 1; j++) before[j - 1] = v[j];
      long long start = i;
      start--;
      long long cur = 1;
      for (long long j = 0; j < n; j++) {
        after[start] = cur;
        start++;
        cur++;
        if (start == n) start = 0;
      }
      if (calc(before, after) <= m) ans.push_back(i - 1);
    }
  }
  cout << ans.size() << " ";
  if (ans.size()) cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) Runtime_Terror();
  return 0;
}
