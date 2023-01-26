#include <bits/stdc++.h>
using namespace std;
int findset(int v, vector<int>& parent) {
  if (parent[v] == v) return v;
  return findset(parent[v], parent);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long long sz = n * m;
    vector<int> parent(sz);
    vector<int> sz1(sz);
    auto makeset = [&](int v) {
      parent[v] = v;
      sz1[v] = 1;
    };
    auto unionset = [&](int a, int b) {
      a = findset(a, parent);
      b = findset(b, parent);
      if (a != b) {
        if (sz1[a] < sz1[b]) {
          swap(a, b);
        }
        parent[b] = a;
        sz1[a] += sz1[b];
      }
    };
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> nodes(n, vector<int>(m));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        nodes[i][j] = cnt;
        cin >> arr[i][j];
        makeset(cnt);
        cnt++;
      }
    }
    auto checkleft = [](int a) {
      if (a & 1 << 0) return 1;
      return 0;
    };
    auto checkright = [](int a) {
      if (a & 1 << 2) return 1;
      return 0;
    };
    auto checkup = [](int a) {
      if (a & 1 << 3) return 1;
      return 0;
    };
    auto checkdown = [](int a) {
      if (a & 1 << 1) return 1;
      return 0;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == n - 1 && j == m - 1) {
          continue;
        } else if (i == n - 1) {
          if (!(checkright(arr[i][j]) || checkleft(arr[i][j + 1]))) {
            unionset(nodes[i][j], nodes[i][j + 1]);
          }
        } else if (j == m - 1) {
          if (!(checkdown(arr[i][j]) || checkup(arr[i + 1][j]))) {
            unionset(nodes[i][j], nodes[i + 1][j]);
          }
        } else {
          if (!(checkright(arr[i][j]) || checkleft(arr[i][j + 1]))) {
            unionset(nodes[i][j], nodes[i][j + 1]);
          }
          if (!(checkdown(arr[i][j]) || checkup(arr[i + 1][j]))) {
            unionset(nodes[i][j], nodes[i + 1][j]);
          }
        }
      }
    }
    map<int, int> ans;
    vector<int> ans1;
    for (int i = 0; i < sz; i++) {
      ans[findset(i, parent)]++;
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
      ans1.push_back(i.second);
    }
    sort(ans1.begin(), ans1.end(), greater<int>());
    for (auto i : ans1) {
      cout << i << " ";
    }
  }
  return 0;
}
