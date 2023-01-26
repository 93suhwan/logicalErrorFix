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
vector<long long> adj[110], par(101);
vector<vector<long long>> level(101, vector<long long>(101)),
    parent(101, vector<long long>(101));
void DFS(long long node, long long par, vector<long long>& levels,
         vector<long long>& parents) {
  for (auto x : adj[node]) {
    if (x != par) {
      parents[x] = node;
      levels[x] = levels[node] + 1;
      DFS(x, node, levels, parents);
    }
  }
}
long long dp[110][110];
long long solve(long long i, long long j, vector<long long>& num) {
  if (j <= 0) return 1;
  if (i < 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  long long ans = 0;
  long long tem = num[i] * solve(i - 1, j - 1, num);
  tem %= 1000000007;
  ans = solve(i - 1, j, num) % 1000000007;
  return dp[i][j] = (ans + tem) % 1000000007;
}
long long ways(vector<long long>& num) {
  long long siz = num.size();
  for (long long i = 0; i < siz + 1; i++)
    for (long long j = 0; j < k + 1; j++) dp[i][j] = -1;
  return solve(siz - 1, k, num);
}
void Runtime_Terror() {
  cin >> n >> k;
  for (long long i = 1; i < n + 1; i++) adj[i].clear();
  for (long long i = 0; i < n + 1; i++)
    for (long long j = 0; j < n + 1; j++) level[i][j] = 0;
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << endl;
    return;
  }
  for (long long i = 1; i < n + 1; i++) {
    parent[i][i] = -1;
    DFS(i, -1, level[i], parent[i]);
  }
  long long ans = 0;
  for (long long i = 1; i < n + 1; i++) {
    vector<vector<long long>> dis(n + 1);
    for (long long j = 1; j < n + 1; j++) {
      dis[level[i][j]].push_back(j);
    }
    if (dis[1].size() >= k) {
      vector<long long> num;
      for (long long j = 0; j < dis[1].size(); j++) num.push_back(1);
      ans += ways(num);
      ans %= 1000000007;
      set<long long> one;
      for (auto& x : dis[1]) one.insert(x);
      ;
      for (long long j = 2; j < n + 1; j++) {
        ;
        map<long long, long long> onecnt;
        onecnt.clear();
        for (long long z = 0; z < dis[j].size(); z++) {
          long long cur = dis[j][z];
          ;
          while (one.find(cur) == one.end()) {
            ;
            cur = parent[i][cur];
          }
          onecnt[cur]++;
        };
        num.clear();
        for (auto& x : onecnt) num.push_back(x.second);
        ans += ways(num);
        ;
        ;
        ;
        ans %= 1000000007;
      }
    };
    ;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) Runtime_Terror();
  return 0;
}
