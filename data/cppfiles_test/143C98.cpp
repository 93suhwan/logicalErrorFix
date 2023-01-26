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
  long long n;
  cin >> n;
  vector<long long> arr(n);
  vector<long long> cnt(n + 1);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }
  if (cnt[0] == 0) {
    cout << 0 << " ";
    for (long long i = 1; i <= (long long)n; i++) {
      cout << -1 << " ";
    }
    cout << "\n";
    return;
  }
  vector<long long> us;
  vector<long long> cost(n + 1);
  us.reserve(n);
  for (long long i = 0; i < (long long)cnt[0] - 1; i++) {
    us.push_back(0);
  }
  cout << cnt[0] << " ";
  for (long long i = 1; i <= (long long)n; i++) {
    cost[i] = cost[i - 1];
    if (cnt[i - 1] == 0) {
      if (us.empty()) {
        for (long long j = i; j <= (long long)n; j++) {
          cout << -1 << " ";
        }
        cout << "\n";
        return;
      }
      cost[i] += (i - 1 - us.back());
      us.pop_back();
    }
    cout << cost[i] + cnt[i] << " ";
    for (long long k = 0; k < (long long)cnt[i] - 1; k++) {
      us.push_back(i);
    }
  }
  cout << "\n";
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
