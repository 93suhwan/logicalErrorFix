#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long int const lac = 100000;
long long int modmul(long long int a, long long int b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long int modadd(long long int a, long long int b) {
  return (((a % 1000000007) + (b % 1000000007))) % 1000000007;
}
long long modExpo(long long a, long long b, long long m) {
  long long result = 1;
  a = a % m;
  while (b > 0) {
    if (b % 2) {
      result = modmul(result, a);
      b--;
    } else {
      a = modmul(a, a);
      b /= 2;
    }
  }
  return result % m;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
class comp {
 public:
  bool operator()(int a, int b) const { return a > b; }
};
bool compa(pair<long long int, long long int> a,
           pair<long long int, long long int> b) {
  return a.first > b.first;
}
void dfs(long long int par, long long int node,
         vector<pair<long long int, string>> adj[],
         vector<long long int> &nodes, vector<bool> &visited) {
  visited[node] = true;
  nodes.push_back(node);
  for (auto child : adj[node]) {
    if (!visited[abs(child.first)]) {
      dfs(node, abs(child.first), adj, nodes, visited);
    }
  }
}
void dfs2(long long int par, long long int node, string role,
          vector<pair<long long int, string>> adj[], bool &ok,
          vector<bool> &visited2, long long int &cnt, vector<string> &cr) {
  for (auto child : adj[node]) {
    if (child.first > 0) {
      if (visited2[node] && (!visited2[child.first])) {
        visited2[child.first] = true;
        if (role == "imposter") {
          string childRole =
              child.second == "imposter" ? "crewmate" : "imposter";
          cr[child.first] = childRole;
          dfs2(node, child.first, childRole, adj, ok, visited2, cnt, cr);
        } else {
          string childRole =
              child.second == "imposter" ? "imposter" : "crewmate";
          cr[child.first] = childRole;
          dfs2(node, child.first, childRole, adj, ok, visited2, cnt, cr);
        }
      } else if ((!visited2[node]) && visited2[child.first]) {
        visited2[node] = true;
        if (cr[child.first] == "imposter") {
          string childRole =
              child.second == "imposter" ? "crewmate" : "imposter";
          cr[node] = childRole;
        } else {
          string childRole =
              child.second == "imposter" ? "imposter" : "crewmate";
          cr[node] = childRole;
        }
      } else if (visited2[child.first] && visited2[node]) {
        if (cr[child.first] == "imposter") {
          if (cr[node] == "imposter" && child.second == "imposter") {
            ok = false;
            return;
          } else if (cr[node] == "crewmate" && child.second == "crewmate") {
            ok = false;
            return;
          }
        } else {
          if (cr[node] == "imposter" && child.second == "crewmate") {
            ok = false;
            return;
          } else if (cr[node] == "crewmate" && child.second == "imposter") {
            ok = false;
            return;
          }
        }
      }
      if (!ok) {
        return;
      }
    }
  }
  for (auto child : adj[node]) {
    if (child.first < 0) {
      if ((!visited2[abs(child.first)]) && visited2[node] == true) {
        dfs2(node, abs(child.first), "imposter", adj, ok, visited2, cnt, cr);
      }
    }
  }
}
void answerNikalBc(long long int t1) {
  long long int n, m;
  cin >> n >> m;
  map<pair<long long int, long long int>, string> mp;
  vector<pair<long long int, string>> adj[n + 1];
  bool ok = true;
  for (long long int i = 1; i <= m; i++) {
    long long int u, v;
    string s;
    cin >> u >> v >> s;
    if (mp.find({u, v}) == mp.end()) {
      adj[u].push_back({v, s});
      adj[v].push_back({-1 * u, s});
      mp[{u, v}] = s;
    } else {
      if (mp[{u, v}] == s) {
        continue;
      } else {
        ok = false;
      }
    }
  }
  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  long long int ans = 0;
  vector<bool> visited(n + 1, false);
  vector<bool> visited2(n + 1, false);
  vector<string> childRole(n + 1, "imposter");
  for (long long int i = 1; i <= n; i++) {
    if (!visited[i]) {
      vector<long long int> nodes;
      dfs(-1, i, adj, nodes, visited);
      bool init = false;
      long long int cnt1 = 0, cnt2 = 0;
      for (long long int j = 0; j < nodes.size(); j++) {
        if (!visited2[nodes[j]]) {
          if (!init) {
            visited2[nodes[j]] = true;
            childRole[nodes[j]] = "imposter";
            dfs2(-1, nodes[j], "imposter", adj, ok, visited2, cnt1, childRole);
            init = true;
          } else {
            dfs2(-1, nodes[j], "imposter", adj, ok, visited2, cnt1, childRole);
          }
        }
      }
      for (auto a : nodes) {
        visited2[a] = false;
      }
      for (auto a : nodes) {
        if (childRole[a] == "imposter") {
          cnt1++;
        }
      }
      init = false;
      for (long long int j = 0; j < nodes.size(); j++) {
        if (!visited2[nodes[j]]) {
          if (!init) {
            visited2[nodes[j]] = true;
            childRole[nodes[j]] = "crewmate";
            dfs2(-1, nodes[j], "crewmate", adj, ok, visited2, cnt2, childRole);
            init = true;
          } else {
            dfs2(-1, nodes[j], "crewmate", adj, ok, visited2, cnt2, childRole);
          }
        }
      }
      for (auto a : nodes) {
        if (childRole[a] == "imposter") {
          cnt2++;
        }
      }
      if (!ok) {
        cout << -1 << "\n";
        return;
      }
      ans += (max(cnt1, cnt2));
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    answerNikalBc(t);
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
