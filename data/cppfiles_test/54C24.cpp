#include <bits/stdc++.h>
using namespace std;
bool cust(pair<long long, long long>& x, pair<long long, long long>& y) {
  if (x.first != y.first)
    return x.first < y.first;
  else
    return x.second > y.second;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void dfs(int x, vector<set<int>>& adj, vector<pair<int, int>>& c, int par) {
  for (auto j : adj[x]) {
    if (j != par) {
      c[j].first = x;
      dfs(j, adj, c, x);
    }
  }
}
long long find(vector<pair<long long, long long>>& par, long long i) {
  if (par[i].first != i) return par[i].first = find(par, par[i].first);
  return par[i].first;
}
void merge(vector<pair<long long, long long>>& par, long long x, long long y) {
  long long i = find(par, x);
  long long j = find(par, y);
  if (par[i].second > par[j].second) {
    par[j].first = i;
  } else if (par[i].second < par[j].second) {
    par[i].first = j;
  } else {
    par[j].first = i;
    par[i].second++;
  }
}
long long modInverse(long long x, long long m) { return power(x, m - 2, m); }
int b = 0;
int l = 0;
int leaf = 0;
int bfs(int x, vector<vector<long long>>& adj, int par) {
  int z = 1;
  int le = 0;
  for (auto j : adj[x]) {
    if (j != par) {
      le++;
      int y = bfs(j, adj, x);
      if (y == 2) {
        leaf--;
        le--;
      } else if (y == 0)
        z = 0;
    }
  }
  if (le == 0 && par == 1) {
    l = 1;
    leaf++;
  } else if (le == 0)
    leaf++;
  if (z == 1 && le > 0) {
    b++;
    z = 2;
  }
  return z;
}
long long n;
void cal(map<long long, long long>& mp, long long curr, long long l) {
  cout << curr << endl;
  if (curr <= n) mp[curr] += l;
  for (long long i = 0; i <= 9; i++) {
    long long z = curr * 10 + 1;
    string y = "";
    while (z > 0) {
      y += z % 10 + '0';
      z /= 10;
    }
    long long l2 = 0;
    for (int j = y.size() - 1; j >= 0; j--) {
      if (y[j] != '1') break;
      l2++;
    }
    cal(mp, curr * 10 + i, l2);
  }
}
vector<vector<int>> ghn(vector<vector<long long>>& adj, int i, int par) {
  vector<vector<int>> ans(2);
  if (par == -1) {
    int x = (adj[i].size() + 1) / 2;
    ans[0].push_back(i);
    ans[1].push_back(i);
    for (auto j : adj[i]) {
      if (j != par) {
        if (x > 0) {
          ans[0].push_back(j);
          x--;
        } else {
          ans[1].push_back(j);
        }
      }
    }
  } else {
    int x = (adj[i].size()) / 2;
    ans[0].push_back(i);
    ans[1].push_back(i);
    for (auto j : adj[i]) {
      if (j != par) {
        if (x > 0) {
          ans[0].push_back(j);
          x--;
        } else {
          ans[1].push_back(j);
        }
      }
    }
  }
  return ans;
}
long long findpar(vector<pair<long long, long long>>& par, long long i) {
  if (par[i].first != i) return par[i].first = find(par, par[i].first);
  return par[i].first;
}
void mergepar(vector<pair<long long, long long>>& par, long long x,
              long long y) {
  long long i = findpar(par, x);
  long long j = findpar(par, y);
  if (i != j) {
    par[i].second += par[j].second;
    par[j].second = 0;
    par[j].first = i;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> par(2 * n + 1, {0, 0});
    for (int i = 0; i <= 2 * n; i++) {
      par[i].first = i;
      par[i].second = (i <= n ? 1 : 0);
    }
    for (int i = 0; i < m; i++) {
      long long a, b;
      cin >> a >> b;
      string z;
      cin >> z;
      if (a)
        if (z[0] == 'c') {
          mergepar(par, a, b);
          mergepar(par, a + n, b + n);
        } else {
          mergepar(par, a, b + n);
          mergepar(par, a + n, b);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (findpar(par, i) == findpar(par, i + n)) {
        ans = -1;
        break;
      }
      ans += max(par[i].second, par[i + n].second);
    }
    cout << ans << endl;
  }
  return 0;
}
