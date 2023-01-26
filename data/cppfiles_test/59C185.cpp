#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int mxn = (int)1e5 + 3;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    cout << ([]() -> bool {
      int n;
      cin >> n;
      vector<vector<int>> a(n, vector<int>(5));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
          cin >> a[i][j];
        }
      }
      for (int day_1 = 0; day_1 < 5; day_1++) {
        for (int day_2 = day_1 + 1; day_2 < 5; day_2++) {
          set<int> p, q;
          for (int i = 0; i < n; i++) {
            if (a[i][day_1]) p.insert(i);
            if (a[i][day_2]) q.insert(i);
          }
          if (p.size() >= n / 2 and q.size() >= n / 2) {
            int common = 0;
            for (auto &x : q) {
              if (p.find(x) != p.end()) common++;
            }
            if (n - (p.size() - common) - (q.size() - common) <= common)
              return 1;
          }
        }
      }
      return 0;
    }()
                         ? "YES\n"
                         : "NO\n");
  }
  return 0;
}
