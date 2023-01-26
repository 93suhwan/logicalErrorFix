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
struct sparse_table_min {
  long long N;
  long long max_power;
  long long def_val;
  vector<long long> log_value;
  vector<vector<long long>> table;
  long long merge_nodes(long long left, long long right) {
    return min(left, right);
  }
  sparse_table_min() {}
  void precompute_logs() {
    log_value[0] = -1e9;
    log_value[1] = 0;
    for (long long i = 2; i <= N; i++) {
      log_value[i] = log_value[i / 2] + 1;
    }
  }
  sparse_table_min(vector<long long> &elements, long long val) {
    N = elements.size();
    max_power = (long long)floor(log2((long long)elements.size()));
    def_val = val;
    log_value.resize(N + 1, 0);
    table.resize(N, vector<long long>(max_power + 1, val));
    precompute_logs();
    build(elements);
  }
  void build(vector<long long> &elements) {
    for (long long i = 0; i < N; i++) {
      table[i][0] = elements[i];
    }
    for (long long j = 1; j <= max_power; j++) {
      for (long long i = 0; i < N; i++) {
        if (i + (1 << j) - 1 >= N) {
          break;
        }
        table[i][j] =
            merge_nodes(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  long long query(long long l, long long r) {
    long long len = r - l + 1;
    long long bit = log_value[len];
    return merge_nodes(table[l][bit], table[r - (1 << bit) + 1][bit]);
  }
};
struct sparse_table_max {
  long long N;
  long long max_power;
  long long def_val;
  vector<long long> log_value;
  vector<vector<long long>> table;
  long long merge_nodes(long long left, long long right) {
    return max(left, right);
  }
  sparse_table_max() {}
  void precompute_logs() {
    log_value[0] = -1e9;
    log_value[1] = 0;
    for (long long i = 2; i <= N; i++) {
      log_value[i] = log_value[i / 2] + 1;
    }
  }
  sparse_table_max(vector<long long> &elements, long long val) {
    N = elements.size();
    max_power = (long long)floor(log2((long long)elements.size()));
    def_val = val;
    log_value.resize(N + 1, 0);
    table.resize(N, vector<long long>(max_power + 1, val));
    precompute_logs();
    build(elements);
  }
  void build(vector<long long> &elements) {
    for (long long i = 0; i < N; i++) {
      table[i][0] = elements[i];
    }
    for (long long j = 1; j <= max_power; j++) {
      for (long long i = 0; i < N; i++) {
        if (i + (1 << j) - 1 >= N) {
          break;
        }
        table[i][j] =
            merge_nodes(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  long long query(long long l, long long r) {
    long long len = r - l + 1;
    long long bit = log_value[len];
    return merge_nodes(table[l][bit], table[r - (1 << bit) + 1][bit]);
  }
};
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> vals(n);
  vector<vector<long long>> arr(n, vector<long long>(m));
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)m; j++) {
      cin >> arr[i][j];
    }
    vals[i] = {arr[i][0], i};
  }
  sort((vals).begin(), (vals).end());
  vector<vector<long long>> matrix(n, vector<long long>(m));
  for (long long i = 0; i < (long long)n; i++) {
    matrix[i] = arr[vals[i].second];
  }
  vector<vector<long long>> min_pre(n, vector<long long>(m, 1e9));
  vector<vector<long long>> max_pre(n, vector<long long>(m, 0));
  vector<vector<long long>> min_suf(n, vector<long long>(m, 1e9));
  vector<vector<long long>> max_suf(n, vector<long long>(m, 0));
  for (long long i = 0; i < (long long)n; i++) {
    min_pre[i][0] = matrix[i][0];
    max_pre[i][0] = matrix[i][0];
    for (long long j = 1; j < (long long)m; j++) {
      min_pre[i][j] = min(matrix[i][j], min_pre[i][j - 1]);
      max_pre[i][j] = max(matrix[i][j], max_pre[i][j - 1]);
    }
  }
  for (long long i = (long long)n - 1; i >= 0; i--) {
    min_suf[i][m - 1] = matrix[i][m - 1];
    max_suf[i][m - 1] = matrix[i][m - 1];
    for (long long j = (long long)m - 2; j >= 0; j--) {
      min_suf[i][j] = min(min_suf[i][j + 1], matrix[i][j]);
      max_suf[i][j] = max(max_suf[i][j + 1], matrix[i][j]);
    }
  }
  auto sub = [&](long long cut) -> long long {
    vector<long long> min_left(n);
    vector<long long> max_left(n);
    for (long long i = 0; i < (long long)n; i++) {
      min_left[i] = min_pre[i][cut];
      max_left[i] = max_pre[i][cut];
    }
    vector<long long> min_right(n);
    vector<long long> max_right(n);
    for (long long i = 0; i < (long long)n; i++) {
      min_right[i] = min_suf[i][cut + 1];
      max_right[i] = max_suf[i][cut + 1];
    }
    sparse_table_max mxlt(max_left, 0);
    sparse_table_max mnlt(min_left, 1e9);
    sparse_table_max mxrt(max_right, 0);
    sparse_table_max mnrt(min_right, 1e9);
    for (long long i = 0; i < (long long)n - 1; i++) {
      long long a = mxlt.query(0, i);
      long long b = mnrt.query(0, i);
      long long c = mnlt.query(i + 1, n - 1);
      long long d = mxrt.query(i + 1, n - 1);
      if (c > a && b > d) {
        return i;
      }
    }
    return -1;
  };
  for (long long i = 0; i < (long long)m - 1; i++) {
    long long ans = sub(i);
    if (ans != -1) {
      cout << "YES"
           << "\n";
      vector<char> color(n, 'R');
      for (long long j = 0; j <= (long long)ans; j++) {
        color[vals[j].second] = 'B';
      }
      for (long long j = 0; j < (long long)n; j++) {
        cout << color[j];
      }
      cout << " ";
      cout << i + 1 << "\n";
      return;
    }
  }
  cout << "NO"
       << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long no_of_testcases = 1;
  cin >> no_of_testcases;
  for (long long i = 1; i <= no_of_testcases; i++) {
    solve();
  }
  return 0;
}
