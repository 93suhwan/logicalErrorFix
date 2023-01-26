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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> vals(n);
  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)m; j++) {
      cin >> arr[i][j];
    }
    vals[i] = {arr[i][0], i};
  }
  sort((vals).begin(), (vals).end());
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < (int)n; i++) {
    matrix[i] = arr[vals[i].second];
  }
  vector<vector<int>> min_pre(n, vector<int>(m, 1e9));
  vector<vector<int>> max_pre(n, vector<int>(m, 0));
  vector<vector<int>> min_suf(n, vector<int>(m, 1e9));
  vector<vector<int>> max_suf(n, vector<int>(m, 0));
  for (int i = 0; i < (int)n; i++) {
    min_pre[i][0] = matrix[i][0];
    max_pre[i][0] = matrix[i][0];
    for (int j = 1; j < (int)m; j++) {
      min_pre[i][j] = min(matrix[i][j], min_pre[i][j - 1]);
      max_pre[i][j] = max(matrix[i][j], max_pre[i][j - 1]);
    }
  }
  for (int i = (int)n - 1; i >= 0; i--) {
    min_suf[i][m - 1] = matrix[i][m - 1];
    max_suf[i][m - 1] = matrix[i][m - 1];
    for (int j = (int)m - 2; j >= 0; j--) {
      min_suf[i][j] = min(min_suf[i][j + 1], matrix[i][j]);
      max_suf[i][j] = max(max_suf[i][j + 1], matrix[i][j]);
    }
  }
  auto sub = [&](int cut) -> int {
    vector<int> min_left(n);
    vector<int> max_left(n);
    for (int i = 0; i < (int)n; i++) {
      min_left[i] = min_pre[i][cut];
      max_left[i] = max_pre[i][cut];
    }
    vector<int> min_right(n);
    vector<int> max_right(n);
    for (int i = 0; i < (int)n; i++) {
      min_right[i] = min_suf[i][cut + 1];
      max_right[i] = max_suf[i][cut + 1];
    }
    vector<int> mxlt(n);
    mxlt[0] = max_left[0];
    for (int i = 1; i < (int)n; i++) {
      mxlt[i] = max(mxlt[i - 1], max_left[i]);
    }
    vector<int> mnrt(n);
    mnrt[0] = min_right[0];
    for (int i = 1; i < (int)n; i++) {
      mnrt[i] = min(mnrt[i - 1], min_right[i]);
    }
    vector<int> mxrt(n);
    mxrt[n - 1] = max_right[n - 1];
    for (int i = (int)n - 2; i >= 0; i--) {
      mxrt[i] = max(mxrt[i + 1], max_right[i]);
    }
    vector<int> mnlt(n);
    mnlt[n - 1] = min_left[n - 1];
    for (int i = (int)n - 2; i >= 0; i--) {
      mnlt[i] = min(mnlt[i + 1], min_left[i]);
    }
    for (int i = 0; i < (int)n - 1; i++) {
      int a = mxlt[i];
      int b = mnrt[i];
      int c = mnlt[i + 1];
      int d = mxrt[i + 1];
      if (c > a && b > d) {
        return i;
      }
    }
    return -1;
  };
  for (int i = 0; i < (int)m - 1; i++) {
    int ans = sub(i);
    if (ans != -1) {
      cout << "YES"
           << "\n";
      vector<char> color(n, 'R');
      for (int j = 0; j <= (int)ans; j++) {
        color[vals[j].second] = 'B';
      }
      for (int j = 0; j < (int)n; j++) {
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
  int no_of_testcases = 1;
  cin >> no_of_testcases;
  for (int i = 1; i <= no_of_testcases; i++) {
    solve();
  }
  return 0;
}
