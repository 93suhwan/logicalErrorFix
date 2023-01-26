#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> fre;
bool comp(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.second < p2.second;
}
string rev(string s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    int temp = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = temp;
  }
  return s;
}
class gr {
 public:
  int parent;
  int rank;
  gr() { rank = 0; }
};
int Parent(int u, vector<gr> &par) {
  if (u == par[u].parent) return u;
  par[u].parent = Parent(par[u].parent, par);
  return par[u].parent;
}
void Union(int p1, int p2, vector<gr> &parent) {
  if (parent[p1].rank > parent[p2].rank) {
    parent[p2].parent = p1;
  } else if (parent[p1].rank < parent[p2].rank) {
    parent[p1].parent = p2;
  } else {
    parent[p2].parent = p1;
    parent[p1].rank++;
  }
}
void rotate(vector<long long> &arr, int n, int l, int r, int d) {
  if (d == 0) return;
  int temp[d];
  int q = 0;
  for (int i = l; i < d + l; i++) {
    temp[q] = arr[i];
    q++;
  }
  int x = l;
  for (int j = l + d; j <= r; j++) {
    arr[x] = arr[j];
    x++;
  }
  x = 0;
  for (int k = r + 1 - d; k <= r; k++) {
    arr[k] = temp[x];
    x++;
  }
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> arr(n, vector<char>(m));
  int cnt = 0;
  vector<vector<bool>> vis(n, vector<bool>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == '*') cnt++;
    }
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < m; t++) {
      if (arr[i][t] == '*') {
        bool root = vis[i][t];
        if (!vis[i][t]) {
          vis[i][t] = true;
          cnt--;
        }
        int tick = 0;
        int a = i - 1;
        int b = t - 1;
        int c = i - 1;
        int d = t + 1;
        stack<bool> left;
        stack<bool> right;
        while (a >= 0 && b >= 0 && c >= 0 && d < m && arr[a][b] == '*' &&
               arr[c][d] == '*') {
          left.push(vis[a][b]);
          right.push(vis[c][d]);
          if (!vis[a][b]) {
            cnt--;
            vis[a][b] = true;
          }
          if (!vis[c][d]) {
            cnt--;
            vis[c][d] = true;
          }
          a--;
          b--;
          c--;
          d++;
          tick++;
        }
        a++;
        b++;
        c++;
        d--;
        if (tick < k) {
          while (a != i && b != t && c != i && d != t) {
            vis[a][b] = false;
            vis[c][d] = false;
            if (left.top() == false) cnt++;
            if (right.top() == false) cnt++;
            left.pop();
            right.pop();
            a++;
            b++;
            c++;
            d--;
          }
          vis[i][t] = false;
          if (root == false) cnt++;
        }
      }
    }
  }
  bool flag = true;
  for (int i = 0; flag && i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '*' && vis[i][j] == false) {
        flag = false;
        break;
      }
    }
  }
  if (flag)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
