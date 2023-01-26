#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
template <class T>
T sqr(T x) {
  return x * x;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T> v_) {
  os << "{";
  for (long long i = 0; i < v_.size(); i++) {
    os << v_[i];
    if (i != v_.size() - 1) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}
class DSU {
 private:
  const long long reserve = 5;

 public:
  vector<long long> parent;
  vector<long long> sets_size;
  explicit DSU(long long size) {
    parent = vector<long long>(size);
    sets_size = vector<long long>(size, 1);
    iota(parent.begin(), parent.end(), 0);
  }
  void make_set(long long v) {
    if (v >= parent.size()) {
      parent.resize(v + reserve);
      sets_size.resize(v + reserve);
    }
    parent[v] = v;
    sets_size[v] = 1;
  }
  long long find_set(long long v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find_set(parent[v]);
  }
  void union_sets(long long a, long long b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      parent[b] = a;
      sets_size[b] += sets_size[a];
    }
  }
  long long operator[](const long long& v) { return find_set(v); }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long>> a(n, vector<long long>(m, 0));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  DSU dsu(int32_t(n * m));
  for (long long q = 0; q < k; q++) {
    long long pos;
    cin >> pos;
    pos--;
    for (long long i = 0; i < n;) {
      while (a[i][pos] != 2) {
        long long to = a[i][pos] == 1 ? pos + 1 : pos - 1;
        a[i][pos] = 2;
        pos = to;
      }
      if (a[i][pos] == 2) {
        if (i + 1 == n) {
          break;
        }
        if (a[i + 1][pos] == 2) {
          dsu.union_sets(m * (i + 1) + pos, m * i + pos);
          i = dsu.find_set(m * i + pos) / m;
        } else {
          i++;
        }
      }
    }
    cout << pos + 1 << " ";
  }
  return 0;
}
