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
  os << endl;
  return os << "";
}
template <typename T>
ostream &operator<<(ostream &os, max_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << endl;
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
  os << endl;
  for (long long i = 0; i < (long long)matrix.size(); i++) {
    for (long long j = 0; j < (long long)matrix[i].size(); j++) {
      os << matrix[i][j] << " ";
    }
    os << endl;
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
  os << endl;
  for (auto m : M) {
    os << m << endl;
  }
  return os << "";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, multimap<F, S> M) {
  os << endl;
  for (auto m : M) {
    os << m << endl;
  }
  return os << "";
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> ans(n);
  ans[n - 1] = n;
  vector<long long> q(n, 1);
  for (long long i = 1; i < (long long)n; i++) {
    q[n - 1]++;
    cout << "? " << q << endl;
    long long qa;
    cin >> qa;
    if (qa == 0) {
      ans[n - 1] = n + 1 - i;
      break;
    }
  }
  q = vector<long long>(n, ans[n - 1]);
  q[n - 1] = 0;
  for (long long i = 1; i <= (long long)n; i++) {
    if (i == ans[n - 1]) {
      continue;
    }
    q[n - 1] = i;
    cout << "? " << q << endl;
    long long loc;
    cin >> loc;
    loc--;
    ans[loc] = i;
  }
  cout << "! " << ans << endl;
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
