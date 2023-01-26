#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v1[300010];
vector<int> v[300010];
int c[300010];
int ff;
int a[300010], b[300010];
map<pair<int, int>, int> mp;
vector<int> bb;
int need;
vector<pair<int, int> > ne;
vector<int> ans;
int du[300010];
void init(int x) {
  c[x] = 1;
  for (auto k : v1[x]) {
    if (c[k]) continue;
    v[x].push_back(k);
    v[k].push_back(x);
    c[k] = 1;
    init(k);
  }
}
void dfs(int a, int b) {
  c[a] = 1;
  if (a == b) {
    bb.push_back(b);
    ff = 1;
    return;
  }
  if (ff) return;
  for (auto k : v[a]) {
    if (c[k]) continue;
    dfs(k, b);
    if (ff) {
      mp[make_pair(min(k, a), max(k, a))]++;
      bb.push_back(a);
      return;
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    v1[l].push_back(r);
    v1[r].push_back(l);
  }
  init(1);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    for (int j = 1; j <= n; j++) c[j] = 0;
    bb.clear();
    ff = 0;
    cin >> a[i] >> b[i];
    dfs(a[i], b[i]);
    for (int j = bb.size() - 1; j >= 0; j--) ans.push_back(bb[j]);
  }
  for (auto it : mp) {
    if (it.second & 1) {
      ne.push_back(make_pair(it.first.first, it.first.second));
      du[it.first.first]++;
      du[it.first.second]++;
    }
  }
  if (ne.empty()) {
    cout << "YES" << endl;
    int pos = 0;
    for (int i = 1; i <= q; i++) {
      bb.clear();
      for (int j = pos; j < ans.size(); j++) {
        if (ans[j] == b[i]) {
          bb.push_back(ans[j]);
          pos = j + 1;
          break;
        }
        bb.push_back(ans[j]);
      }
      cout << bb.size() << endl;
      for (auto k : bb) cout << k << " ";
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
    need = ne.size();
    for (auto it : ne) {
      int x = it.first, y = it.second;
      if (du[x] > 1) {
        du[x]--;
        need--;
      } else if (du[y] > 1) {
        du[y]--;
        need--;
      }
    }
    cout << need << endl;
  }
  return 0;
}
