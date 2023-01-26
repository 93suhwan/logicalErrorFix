#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int T = 1;
const int MOD = 1000000007;
const int N = 1007;
const ll oo = 1e18 + 7;
const double eps = 1e-8;
int n;
pii r[N];
int test_case(int test_ID) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r[i].first >> r[i].second;
  }
  for (int i = 0; i < n; i++) {
    if (r[i].first == r[i].second) {
      cout << r[i].first << " " << r[i].second << " " << r[i].first << endl;
      continue;
    }
    int d = -1;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (r[i].first > r[j].first || r[i].second < r[j].second) continue;
      if (r[j].first == r[i].first) {
        d = max(d, r[j].second + 1);
      }
      if (r[j].second == r[i].second) {
        if (~d)
          d = min(d, r[j].first - 1);
        else
          d = r[j].first - 1;
      }
    }
    cout << r[i].first << " " << r[i].second << " " << d << endl;
  }
  cout << endl;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++) test_case(i);
  return 0;
}
