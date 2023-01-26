#include <bits/stdc++.h>
using namespace std;
int parent[200001];
int urank[200001];
int mini[200001];
void create(int x, int z) {
  parent[x] = x;
  urank[x] = 0;
  mini[x] = z;
}
int find(int x) {
  if (parent[x] != x) {
    parent[x] = find(parent[x]);
  }
  return parent[x];
}
void merge(int x, int y) {
  int xroot = find(x);
  int yroot = find(y);
  if (xroot == yroot) return;
  if (urank[xroot] <= urank[yroot]) {
    parent[xroot] = yroot;
    urank[yroot] = urank[yroot] + urank[xroot];
    mini[yroot] = min(mini[yroot], mini[xroot]);
  } else {
    parent[yroot] = xroot;
    urank[xroot] = urank[xroot] + urank[yroot];
    mini[xroot] = min(mini[xroot], mini[yroot]);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k, i, j, a, b;
    cin >> n >> k;
    map<int, vector<pair<int, int>>> mp, mp2;
    for (i = 1; i <= n; ++i) {
      cin >> a >> b >> j;
      create(i, j);
      mp[a].push_back({b, i});
      mp2[b].push_back({a, i});
    }
    vector<pair<int, int>> v;
    for (auto it : mp) {
      v = it.second;
      sort(v.begin(), v.end());
      for (i = 1; i < v.size(); ++i) {
        if (v[i].first - v[i - 1].first <= k) {
          merge(v[i].second, v[i - 1].second);
        }
      }
    }
    for (auto it : mp2) {
      v = it.second;
      sort(v.begin(), v.end());
      for (i = 1; i < v.size(); ++i) {
        if (v[i].first - v[i - 1].first <= k) {
          merge(v[i].second, v[i - 1].second);
        }
      }
    }
    set<int> st;
    for (i = 1; i <= n; ++i) {
      st.insert(find(i));
    }
    int l = 0, r = n + 10, mid, ans = n, ct;
    while (l <= r) {
      mid = (l + r) / 2;
      ct = 0;
      for (auto it : st) {
        if (mini[it] <= mid) continue;
        ++ct;
      }
      if (ct <= mid + 1) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
