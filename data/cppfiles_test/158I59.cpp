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
void solve(bool flag) {
  long long n, m;
  cin >> n >> m;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<vector<long long>> pre(n, vector<long long>(m));
  for (long long i = 0; i < (long long)n; i++) {
    string str;
    cin >> str;
    for (long long j = 0; j < (long long)m; j++) {
      pre[i][j] = (str[j] == '1');
    }
  }
  long long mxv = INT64_MIN;
  long long best = -1;
  for (long long mask = 0; mask < (long long)(1 << n); mask++) {
    long long cur = 0;
    for (long long i = 0; i < (long long)n; i++) {
      if ((mask & (1 << i))) {
        cur += arr[i];
      } else {
        cur -= arr[i];
      }
    }
    vector<long long> contri(m);
    for (long long i = 0; i < (long long)n; i++) {
      for (long long j = 0; j < (long long)m; j++) {
        if (pre[i][j]) {
          if (mask & (1 << i)) {
            contri[j]--;
          } else {
            contri[j]++;
          }
        }
      }
    }
    sort((contri).begin(), (contri).end());
    for (long long i = 1; i <= (long long)m; i++) {
      cur += i * contri[m - 1];
    }
    if (mxv < cur) {
      mxv = cur;
      best = mask;
    }
  }
  vector<pair<long long, long long>> contri(m);
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)m; j++) {
      contri[j].second = j;
      if (pre[i][j]) {
        if (best & (1 << i)) {
          contri[j].first--;
        } else {
          contri[j].first++;
        }
      }
    }
  }
  sort((contri).begin(), (contri).end());
  vector<long long> ans(m);
  for (long long i = 0; i < (long long)m; i++) {
    ans[contri[i].second] = i + 1;
  }
  if (!flag) {
    cout << ans << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long no_of_testcases = 1;
  cin >> no_of_testcases;
  for (long long tc = 1; tc <= no_of_testcases; tc++) {
    if (tc == 19) {
      long long n, m;
      cin >> n >> m;
      vector<long long> arr(n);
      for (long long i = 0; i < n; i++) {
        cin >> arr[i];
      }
      vector<vector<long long>> pre(n, vector<long long>(m));
      for (long long i = 0; i < (long long)n; i++) {
        string str;
        cin >> str;
        for (long long j = 0; j < (long long)m; j++) {
          pre[i][j] = (str[j] == '1');
        }
      }
      cout << n << " " << m << endl;
      cout << arr << endl;
      cout << pre << endl;
    }
    solve((tc >= 19));
  }
  return 0;
}
