#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <class T>
ostream &operator<<(ostream &os, min_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << "\n";
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, max_heap<T> H) {
  while (!H.empty()) {
    os << H.top() << " ";
    H.pop();
  }
  os << "\n";
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << P.first << " " << P.second;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> arr) {
  for (long long i = 0; i < (long long)arr.size(); i++) {
    os << arr[i] << " ";
  }
  return os << "";
}
template <class T>
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
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, multiset<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, multimap<L, R> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> choices(n + 1);
  for (long long i = 1; i <= (long long)n; i++) {
    long long len;
    cin >> len;
    choices[i].resize(len + 1);
    for (long long j = 1; j <= (long long)len; j++) {
      cin >> choices[i][j];
    }
  };
  vector<long long> suf(n + 2);
  for (long long i = (long long)n; i >= 1; i--) {
    suf[i] =
        suf[i + 1] + *max_element((choices[i]).begin(), (choices[i]).end());
  }
  vector<map<long long, set<long long>>> hate(n + 1);
  long long ban;
  cin >> ban;
  if (ban == 0) {
    for (long long i = 1; i <= (long long)n; i++) {
      cout << max_element((choices[i]).begin(), (choices[i]).end()) -
                  choices[i].begin()
           << " ";
    }
    cout << "\n";
    exit(0);
  }
  vector<vector<long long>> ban_build(ban + 1, vector<long long>(n + 1));
  for (long long i = 1; i <= (long long)ban; i++) {
    vector<long long> &build = ban_build[i];
    for (long long iter = 1; iter <= (long long)n; iter++) {
      cin >> build[iter];
    };
    long long sum = 0;
    for (long long j = 1; j <= (long long)n; j++) {
      hate[j - 1][sum].insert(build[j]);
      sum += choices[j][build[j]];
    }
  };
  long long ans = 0;
  long long ans_ind = 0;
  long long pre = 0;
  for (long long i = 1; i <= (long long)n; i++) {
    multiset<long long> vals;
    for (long long j = 1; j < (long long)choices[i].size(); j++) {
      vals.insert(choices[i][j]);
    }
    for (const auto &[extra, dl] : hate[i - 1]) {
      for (const auto &d : dl) {
        vals.erase(vals.find(choices[i][d]));
      }
      if ((long long)vals.size() != 0) {
        long long profit = extra + *vals.rbegin() + suf[i + 1];
        if (profit > ans) {
          ans = profit;
          ans_ind = i;
          pre = extra;
        }
      }
      for (const auto &d : dl) {
        vals.insert(choices[i][d]);
      }
    }
  }
  vector<long long> ans_b;
  multiset<pair<long long, long long>> vals;
  for (long long j = 1; j < (long long)choices[ans_ind].size(); j++) {
    vals.insert({choices[ans_ind][j], j});
  }
  for (const auto &d : hate[ans_ind - 1][pre]) {
    vals.erase(vals.lower_bound({d, 0}));
  }
  ans_b.push_back((*vals.rbegin()).second);
  for (long long i = ans_ind + 1; i <= (long long)n; i++) {
    ans_b.push_back(max_element((choices[i]).begin(), (choices[i]).end()) -
                    choices[i].begin());
  }
  for (long long i = 1; i <= (long long)ban; i++) {
    vector<long long> &build = ban_build[i];
    long long sum = 0;
    for (long long j = 1; j < (long long)ans_ind; j++) {
      sum += choices[j][build[j]];
    }
    if (sum == pre) {
      for (long long k = 1; k < (long long)ans_ind; k++) {
        cout << build[k] << " ";
      }
      cout << ans_b << "\n";
      exit(0);
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
