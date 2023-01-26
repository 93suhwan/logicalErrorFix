#include <bits/stdc++.h>
using namespace std;
const int Alp = 26;
const int __PRECISION = 9;
const int inf = 1e9 + 8;
const long double PI = acos(-1);
const long double EPS = 1e-7;
const long long MOD = 1e9 + 7;
const long long MAXN = 2e5 + 5;
const long long ROOTN = 320;
const long long LOGN = 18;
const long long INF = 1e18 + 1022;
inline bool intersect(pair<int, int> A, pair<int, int> B) {
  vector<pair<int, int> > t;
  t.push_back(make_pair(A.first, 0));
  t.push_back(make_pair(A.second, 0));
  t.push_back(make_pair(B.first, 1));
  t.push_back(make_pair(B.second, 1));
  sort((t).begin(), (t).end());
  int a = t[0].second + 2 * t[1].second + 4 * t[2].second + 8 * t[3].second;
  return (a == 10 || a == 5);
}
inline void test_case() {
  int N, K;
  cin >> N >> K;
  vector<int> vis(2 * N + 1);
  pair<int, int> line[K];
  long long ans = (N - K) * (N - K - 1) / 2;
  for (int i = 0; i < (K); ++i) {
    int x, y;
    cin >> x >> y;
    line[i] = make_pair(x - 1, y - 1);
    vis[x - 1] = vis[y - 1] = 1;
    for (int j = 0; j < (i); ++j) {
      if (intersect(line[i], line[j])) {
        ++ans;
      }
    }
  }
  for (int i = 0; i < (K); ++i) {
    int a = 0, tmp = 0;
    for (int j = line[i].second; j != line[i].first; j = (j + 1) % (2 * N)) {
      a += 1 - vis[j];
    }
    for (int j = line[i].first; j != line[i].second; j = (j + 1) % (2 * N)) {
      tmp += 1 - vis[j];
    }
    ans += min(a, tmp);
  }
  cout << ans << '\n';
}
signed main() {
  int test_case_number;
  cin >> test_case_number;
  while (test_case_number--) test_case();
  return 0;
}
