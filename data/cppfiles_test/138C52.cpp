#include <bits/stdc++.h>
using namespace std;
struct dsu {
  vector<int> root, size, val;
  int lsta, lstb;
  dsu(int n) {
    for (int i = 0; i < n; i++) {
      root.push_back(i);
      size.push_back(1);
      val.push_back(i);
    }
  }
  int find(int a) {
    while (a != root[a]) {
      a = root[a];
    }
    return a;
  }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return false;
    }
    if (size[a] < size[b]) {
      swap(a, b);
    }
    root[b] = a;
    size[a] += size[b];
    val[a] = max(val[a], val[b]);
    lsta = a, lstb = b;
    return true;
  }
  void revert_back() {
    size[lsta] -= size[lstb];
    root[lstb] = lstb;
  }
};
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  long long x, ans = 0;
  dsu ds(n);
  vector<pair<long long, int>> v;
  vector<long long> pref(n + m, 0);
  vector<long long> aa;
  vector<int> pos(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    aa.push_back(x);
    ans += x;
  }
  sort(aa.begin(), aa.end());
  for (int i = 0; i < n; i++) {
    v.emplace_back(make_pair(aa[i], i));
  }
  for (int j = 0; j < m; j++) {
    cin >> x;
    v.emplace_back(make_pair(x, -1));
  }
  sort(v.begin(), v.end());
  pref[0] = v[0].first;
  for (int i = 1; i < n + m; i++) {
    pref[i] = pref[i - 1] + v[i].first;
  }
  auto sum = [&](int l, int r) {
    long long ret = pref[r];
    if (l) {
      ret -= pref[l - 1];
    }
    return ret;
  };
  vector<pair<long long, int>> queries;
  vector<long long> res(q, 0);
  for (int i = 0; i < q; i++) {
    long long k;
    cin >> k;
    queries.emplace_back(make_pair(k, i));
  }
  sort(queries.begin(), queries.end());
  set<pair<long long, int>> st;
  for (int i = 0; i < n + m - 1; i++) {
    if (v[i].second != -1) {
      pos[v[i].second] = i;
      st.insert(make_pair(v[i + 1].first - v[i].first, v[i].second));
    }
  }
  if (v[n + m - 1].second != -1) {
    pos[v[n + m - 1].second] = n + m - 1;
  }
  for (auto ele : queries) {
    while (!st.empty() && st.begin()->first <= ele.first) {
      int i = st.begin()->second;
      int f = ds.find(i);
      int prev = ds.size[f];
      int j = pos[ds.val[f]];
      st.erase(st.begin());
      ans -= sum(j - prev + 1, j);
      bool flg = false;
      while (pos[i] + 1 < n + m &&
             v[pos[i] + 1].first - v[pos[i]].first <= ele.first) {
        pos[i]++;
        if (v[pos[i]].second != -1) {
          ds.unite(i, i + 1);
          flg = true;
          break;
        }
      }
      f = ds.find(i);
      int nw = ds.size[f];
      j = pos[ds.val[f]];
      ans += sum(j - nw + 1, j - nw + prev);
      if (!flg && pos[i] + 1 < n + m) {
        st.insert(make_pair(v[pos[i] + 1].first - v[pos[i]].first, i));
      }
    }
    res[ele.second] = ans;
  }
  for (int i = 0; i < q; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}
