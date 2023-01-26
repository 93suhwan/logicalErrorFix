#include <bits/stdc++.h>
const bool debugging = 1;
const long long mod = 1e9 + 7;
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  for (auto v : V) {
    os << v << " ";
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, vector<vector<T>> V) {
  for (long long i = 0; i < V.size(); i++) {
    for (long long j = 0; j < V[i].size(); j++) {
      os << V[i][j] << " ";
    }
    os << "\n";
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << P.first << " " << P.second;
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
class disjoint_sets {
 private:
  long long N;
  vector<long long> ancestor;
  vector<long long> children;

 public:
  disjoint_sets(long long size) {
    N = size;
    ancestor.resize(N + 1);
    children.resize(N + 1, 1);
    for (long long i = 1; i <= N; i++) {
      ancestor[i] = i;
    }
  }
  long long find_root(long long X) {
    if (ancestor[X] == X) {
      return X;
    }
    ancestor[X] = find_root(ancestor[X]);
    return ancestor[X];
  }
  void merge_sets(long long X, long long Y) {
    long long root_X = find_root(X);
    long long root_Y = find_root(Y);
    if (root_X == root_Y) {
      return;
    }
    if (children[root_X] > children[root_Y]) {
      swap(root_X, root_Y);
    }
    ancestor[root_X] = root_Y;
    children[root_Y] += children[root_X];
    children[root_X] = 0;
  }
};
void solve() {
  long long N, M;
  cin >> N >> M;
  map<long long, long long> pos;
  vector<long long> arr(N);
  for (long long i = 0; i < N; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  vector<long long> shift(N);
  for (long long i = 0; i < N; i++) {
    long long index = ((i + 1) - arr[i] + N) % N;
    shift[index]++;
  }
  auto func = [&](long long shift_len) -> long long {
    disjoint_sets ds(N + 1);
    for (long long i = 0; i < N; i++) {
      long long current = (i - shift_len + N) % N + 1;
      if (current != arr[i]) {
        ds.merge_sets(pos[current], i);
      }
    }
    set<long long> unique;
    for (long long i = 0; i < N; i++) {
      unique.insert(ds.find_root(i));
    }
    if (N - (long long)unique.size() <= M) {
      return 1;
    }
    return 0;
  };
  vector<long long> vals;
  long long ans = 0;
  for (long long i = 0; i < N; i++) {
    if (N - 2 * M <= shift[i]) {
      if (func(i)) {
        ans++;
        vals.push_back(i);
      }
    }
  }
  cout << ans << " ";
  cout << vals << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long no_of_testcases;
  cin >> no_of_testcases;
  while (no_of_testcases-- > 0) {
    solve();
  }
  return 0;
}
