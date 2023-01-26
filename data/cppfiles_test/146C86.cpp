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
  for (long long i = 0; i < (long long)arr.size(); i++) {
    os << arr[i] << " ";
  }
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> matrix) {
  os << "\n";
  for (long long i = 0; i < (long long)matrix.size(); i++) {
    for (long long j = 0; j < (long long)matrix[i].size(); j++) {
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
  long long n, q;
  cin >> n >> q;
  long long jr = (long long)floor(sqrt(n)) + 1;
  vector<long long> nxt(n + 1);
  vector<long long> prev(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> nxt[i];
    prev[nxt[i]] = i;
  }
  vector<long long> jump(n + 1);
  for (long long i = 1; i <= (long long)n; i++) {
    jump[i] = i;
    for (long long j = 1; j <= (long long)jr; j++) {
      jump[i] = nxt[jump[i]];
    }
  }
  auto query = [&](long long node, long long k) {
    long long ans = node;
    while (k > jr) {
      ans = jump[ans];
      k -= jr;
    }
    for (long long i = 0; i < (long long)k; i++) {
      ans = nxt[ans];
    }
    return ans;
  };
  auto recompute = [&](long long ind) {
    vector<long long> temp(jr + 1);
    temp[0] = ind;
    for (long long i = 1; i <= (long long)jr; i++) {
      temp[i] = nxt[temp[i - 1]];
    }
    long long cur = ind;
    for (long long i = 0; i <= (long long)jr; i++) {
      jump[cur] = temp[jr - i];
      cur = prev[cur];
    }
  };
  auto update = [&](long long u, long long v) {
    swap(nxt[u], nxt[v]);
    prev[nxt[u]] = u;
    prev[nxt[v]] = v;
    recompute(u);
    recompute(v);
  };
  for (long long i = 0; i < (long long)q; i++) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long u, v;
      cin >> u >> v;
      update(u, v);
    } else {
      long long x, k;
      cin >> x >> k;
      cout << query(x, k) << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long no_of_testcases = 1;
  for (long long i = 1; i <= no_of_testcases; i++) {
    solve();
  }
  return 0;
}
