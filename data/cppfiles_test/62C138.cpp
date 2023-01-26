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
  long long n, m, q;
  cin >> n >> m >> q;
  long long ans = 0;
  vector<vector<pair<long long, long long>>> arr(
      n + 1, vector<pair<long long, long long>>(m + 1, {-1, -1}));
  for (long long i = (long long)n - 1; i >= 0; i--) {
    for (long long j = (long long)m - 1; j >= 0; j--) {
      arr[i][j].first = (1 + arr[i][j + 1].second);
      arr[i][j].second = (1 + arr[i + 1][j].first);
      ans += (arr[i][j].first + arr[i][j].second + 1);
    }
  }
  auto check = [&](long long i, long long j) -> bool {
    return (i >= 0 && i < n && j >= 0 && j < m && arr[i][j].first != -1);
  };
  function<void(long long, long long, pair<long long, long long>)> update =
      [&](long long i, long long j, pair<long long, long long> move) -> void {
    long long nxt_i = i + move.first;
    long long nxt_j = j + move.second;
    ans -= (arr[i][j].first + arr[i][j].second + 1);
    arr[i][j].first = (1 + arr[i][j + 1].second);
    arr[i][j].second = (1 + arr[i + 1][j].first);
    ans += (arr[i][j].first + arr[i][j].second + 1);
    if (check(nxt_i, nxt_j)) {
      update(nxt_i, nxt_j, {move.second, move.first});
    }
  };
  for (long long query = 0; query < (long long)q; query++) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    if (arr[l][r].first == -1) {
      arr[l][r].first = (1 + arr[l][r + 1].second);
      arr[l][r].second = (1 + arr[l + 1][r].first);
      ans += (arr[l][r].first + arr[l][r].second + 1);
    } else {
      ans -= (arr[l][r].first + arr[l][r].second + 1);
      arr[l][r].first = -1;
      arr[l][r].second = -1;
    }
    if (check(l - 1, r)) {
      update(l - 1, r, {0, -1});
    }
    if (check(l, r - 1)) {
      update(l, r - 1, {-1, 0});
    }
    cout << ans << "\n";
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
