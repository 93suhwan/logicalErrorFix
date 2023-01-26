#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[400005];
vector<int> adj2[400005];
int color[400005];
bool seen[400005];
void clear(int n) {
  for (int i = 0; i < 2 * n + 5; i++) {
    adj[i].clear();
    adj2[i].clear();
    color[i] = -1;
    seen[i] = false;
  }
}
bool cdfs(int x, int c) {
  if (c == -1) {
    if (color[x] == -1) {
      return cdfs(x, 0);
    }
    return true;
  }
  if (color[x] != -1) {
    return color[x] == c;
  } else {
    color[x] = c;
    bool works = true;
    for (auto it : adj2[x]) {
      works &= cdfs(it, 1 - c);
    }
    return works;
  }
}
bool pdfs(int x) {
  seen[x] = true;
  assert(color[x] != -1);
  for (auto it : adj[x]) {
    if (seen[it.first]) continue;
    if (it.second != -1) {
      cout << x + 1 << " " << it.first + 1 << " " << it.second << "\n";
      if (__builtin_popcount(it.second) % 2 == 0) {
        if (color[it.first] != -1) {
          assert(color[it.first] == color[x]);
        }
        color[it.first] = color[x];
      } else {
        if (color[it.first] != -1) {
          assert(color[it.first] == 1 - color[x]);
        }
        color[it.first] = 1 - color[x];
      }
    } else {
      if (color[it.first] == -1 || color[it.first] == color[x]) {
        cout << x + 1 << " " << it.first + 1 << " " << 0 << "\n";
        color[it.first] = color[x];
      } else {
        cout << x + 1 << " " << it.first + 1 << " " << 1 << "\n";
        color[it.first] = 1 - color[x];
      }
    }
    pdfs(it.first);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    clear(n);
    int z = n;
    for (int i = 0; i < n - 1; i++) {
      int x, y, v;
      int bc;
      cin >> x >> y >> v;
      x--;
      y--;
      adj[x].push_back({y, v});
      adj[y].push_back({x, v});
      if (v != -1) {
        bc = __builtin_popcount(v);
        if (bc & 1) {
          adj2[x].push_back(y);
          adj2[y].push_back(x);
        } else {
          adj2[x].push_back(z);
          adj2[z].push_back(x);
          adj2[y].push_back(z);
          adj2[z].push_back(y);
          z++;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, p;
      cin >> a >> b >> p;
      a--;
      b--;
      if (p) {
        adj2[a].push_back(b);
        adj2[b].push_back(a);
      } else {
        adj2[a].push_back(z);
        adj2[z].push_back(a);
        adj2[b].push_back(z);
        adj2[z].push_back(b);
        z++;
      }
    }
    bool works = true;
    for (int i = 0; i < n; i++) {
      if (!cdfs(i, -1)) {
        works = false;
        break;
      }
    }
    if (!works) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
      int starter = 0;
      for (int i = 0; i < n; i++) {
        if (color[i] != -1) {
          starter = i;
          break;
        }
      }
      if (color[starter] == -1) color[starter] = 0;
      pdfs(starter);
    }
  }
}
