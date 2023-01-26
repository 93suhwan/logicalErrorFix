#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) {
    return a.first > b.first;
  }
};
bool comp(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
bool compp(const pair<long long, long long> &a,
           const pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long mod_power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long temp = mod_power(a, b / 2);
  temp %= 1000000007;
  temp *= temp;
  temp %= 1000000007;
  if (b % 2 == 1) {
    temp *= a;
    temp %= 1000000007;
  }
  return temp;
}
void createTree(long long node, vector<long long> &vis,
                vector<vector<long long> > &graph,
                vector<vector<long long> > &tree) {
  for (auto itr : graph[node]) {
    if (vis[itr] == 0) {
      vis[itr] = 1;
      createTree(itr, vis, graph, tree);
      tree[node].push_back(itr);
      tree[itr].push_back(node);
    }
  }
}
void printPath(long long st, long long par, long long des,
               vector<long long> &path, vector<vector<long long> > &tree) {
  path.push_back(st);
  if (st == des) {
    cout << path.size() << "\n";
    for (auto itr : path) {
      cout << itr << " ";
    }
    cout << "\n";
    return;
  }
  for (auto itr : tree[st]) {
    if (itr != par) {
      printPath(itr, st, des, path, tree);
    }
  }
  path.pop_back();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long> > graph(n + 1);
    for (long long i = 0; i < m; i++) {
      long long x, y;
      cin >> x >> y;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    vector<vector<long long> > tree(n + 1);
    vector<long long> vis(n + 1, 0);
    vis[1] = 1;
    createTree(1, vis, graph, tree);
    long long q;
    cin >> q;
    vector<pair<long long, long long> > vp;
    fill(vis.begin(), vis.end(), 0);
    long long odd = 0;
    while (q--) {
      long long x, y;
      cin >> x >> y;
      vis[x]++;
      vis[y]++;
      if (vis[x] % 2) {
        odd++;
      } else {
        odd--;
      }
      if (vis[y] % 2) {
        odd++;
      } else {
        odd--;
      }
      vp.push_back(make_pair(x, y));
    }
    if (odd) {
      cout << "NO\n";
      cout << odd / 2 << '\n';
    } else {
      cout << "YES\n";
      for (auto itr : vp) {
        vector<long long> path;
        printPath(itr.first, -1, itr.second, path, tree);
      }
    }
  }
  return 0;
}
