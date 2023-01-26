#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
ostream &operator<<(ostream &os, min_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << "\n";
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, max_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << "\n";
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, pair<F, S> P) {
  return os << P.first << " " << P.second;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> arr) {
  for (int i = 0; i < (int)arr.size(); i++) {
    os << arr[i] << " ";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> matrix) {
  os << "\n";
  for (int i = 0; i < (int)matrix.size(); i++) {
    for (int j = 0; j < (int)matrix[i].size(); j++) {
      os << matrix[i][j] << " ";
    }
    os << "\n";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, set<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, multiset<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, map<F, S> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, multimap<F, S> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
void solve() {
  int n, q;
  cin >> n >> q;
  int jr = (int)floor(sqrt(n)) + 1;
  vector<int> nxt(n + 1);
  vector<int> prev(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
    prev[nxt[i]] = i;
  }
  vector<int> jump(n + 1);
  for (int i = 1; i <= (int)n; i++) {
    jump[i] = i;
    for (int j = 1; j <= (int)jr; j++) {
      jump[i] = nxt[jump[i]];
    }
  }
  auto query = [&](int node, int k) {
    int ans = node;
    while (k > jr) {
      ans = jump[ans];
      k -= jr;
    }
    for (int i = 0; i < (int)k; i++) {
      ans = nxt[ans];
    }
    return ans;
  };
  auto recompute = [&](int ind) {
    vector<int> temp(jr + 1);
    temp[0] = ind;
    for (int i = 1; i <= (int)jr; i++) {
      temp[i] = nxt[temp[i - 1]];
    }
    int cur = ind;
    for (int i = 0; i <= (int)jr; i++) {
      jump[cur] = temp[jr - i];
      cur = prev[cur];
    }
  };
  auto update = [&](int u, int v) {
    swap(nxt[u], nxt[v]);
    prev[nxt[u]] = u;
    prev[nxt[v]] = v;
    recompute(u);
    recompute(v);
  };
  for (int i = 0; i < (int)q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v;
      cin >> u >> v;
      update(u, v);
    } else {
      int x, k;
      cin >> x >> k;
      cout << query(x, k) << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int no_of_testcases = 1;
  for (int i = 1; i <= no_of_testcases; i++) {
    solve();
  }
  return 0;
}
