#include <bits/stdc++.h>
using namespace std;
template <typename T>
T max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T max4(T a, T b, T c, T d) {
  return max(max(a, d), max(b, c));
}
template <typename T>
T min3(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T min4(T a, T b, T c, T d) {
  return min(min(a, d), min(b, c));
}
template <typename T>
T binex(T a, T b, T mod) {
  T ans = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, set<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T, class Q>
ostream& operator<<(ostream& os, pair<T, Q> a) {
  os << "| ";
  os << a.first << ", " << a.second << " ";
  return os << "|";
}
template <class P, class Q, class T>
ostream& operator<<(ostream& os, tuple<P, Q, T> a) {
  os << "| " << (get<0>(a)) << ", " << (get<1>(a)) << ", " << (get<2>(a))
     << "|";
  return os;
}
void precomp() {}
void solve() {
  int64_t n, m;
  cin >> n >> m;
  vector<pair<vector<int64_t>, int64_t>> a(n);
  for (int64_t i = 0; i < n; i++) {
    a[i].first = vector<int64_t>(m);
    for (int64_t j = 0; j < m; j++) {
      cin >> a[i].first[j];
    }
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  vector<vector<int64_t>> dp1(n, vector<int64_t>(m));
  vector<vector<int64_t>> dp2(n, vector<int64_t>(m));
  vector<vector<int64_t>> dp3(n, vector<int64_t>(m));
  vector<vector<int64_t>> dp4(n, vector<int64_t>(m));
  for (int64_t i = 0; i < n; i++) {
    for (int64_t j = 0; j < m; j++) {
      dp1[i][j] = a[i].first[j];
      if (i - 1 >= 0) {
        dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
      }
      if (j - 1 >= 0) {
        dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
      }
    }
  }
  for (int64_t i = n - 1; i >= 0; i--) {
    for (int64_t j = 0; j < m; j++) {
      dp2[i][j] = a[i].first[j];
      if (i + 1 < n) {
        dp2[i][j] = min(dp2[i][j], dp2[i + 1][j]);
      }
      if (j - 1 >= 0) {
        dp2[i][j] = min(dp2[i][j], dp2[i][j - 1]);
      }
    }
  }
  for (int64_t i = 0; i < n; i++) {
    for (int64_t j = m - 1; j >= 0; j--) {
      dp3[i][j] = a[i].first[j];
      if (i - 1 >= 0) {
        dp3[i][j] = min(dp3[i][j], dp3[i - 1][j]);
      }
      if (j + 1 < m) {
        dp3[i][j] = min(dp3[i][j], dp3[i][j + 1]);
      }
    }
  }
  for (int64_t i = n - 1; i >= 0; i--) {
    for (int64_t j = m - 1; j >= 0; j--) {
      dp4[i][j] = a[i].first[j];
      if (i + 1 < n) {
        dp4[i][j] = max(dp4[i][j], dp4[i + 1][j]);
      }
      if (j + 1 < m) {
        dp4[i][j] = max(dp4[i][j], dp4[i][j + 1]);
      }
    }
  }
  vector<char> ans(n);
  int64_t ind = -1;
  for (int64_t i = 0; i < n - 1; i++) {
    for (int64_t j = 0; j < m - 1; j++) {
      if (dp1[i][j] < dp2[i + 1][j] && dp3[i][j + 1] > dp4[i + 1][j + 1]) {
        for (int64_t k = 0; k < n; k++) {
          if (k <= i) {
            ans[a[k].second] = 'B';
          } else {
            ans[a[k].second] = 'R';
          }
        }
        ind = j + 1;
        break;
      }
    }
  }
  if (ind == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto x : ans) {
    cout << x;
  }
  cout << " " << ind << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t T;
  cin >> T;
  precomp();
  for (int64_t I = 1; I <= T; I++) {
    solve();
  }
}
