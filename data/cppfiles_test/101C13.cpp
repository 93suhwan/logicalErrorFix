#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> X(N), Y(M);
    for (int i = 0; i < N; i++) {
      cin >> X[i];
    }
    for (int i = 0; i < M; i++) {
      cin >> Y[i];
    }
    vector<pair<int, int>> P(K);
    for (int i = 0; i < K; i++) {
      cin >> P[i].first >> P[i].second;
    }
    long long ans = 0;
    for (int rep = 0; rep < 2; rep++) {
      sort(P.begin(), P.end());
      map<int, int> m;
      int cnt = 0, id = 0;
      for (int i = 0; i < K; i++) {
        int tmp = id;
        while (X[id] < P[i].first) {
          id++;
        }
        if (X[id] == P[i].first) {
          m.clear();
          cnt = 0;
        } else if (id != tmp) {
          m.clear();
          cnt = 1;
          m[P[i].second] = 1;
        } else {
          ans += cnt++;
          ans -= m[P[i].second]++;
        }
      }
      if (rep == 0) {
        for (auto& [x, y] : P) {
          swap(x, y);
        }
        swap(N, M);
        X.swap(Y);
      }
    }
    cout << ans << '\n';
  }
}
