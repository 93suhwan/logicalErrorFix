#include <bits/stdc++.h>
using namespace std;
inline void smax(int& a, int b) {
  if (b > a) a = b;
}
inline void smin(int& a, int b) {
  if (b < a) a = b;
}
inline void smax(long long& a, long long b) {
  if (b > a) a = b;
}
inline void smin(long long& a, long long b) {
  if (b < a) a = b;
}
const long long LLINF = 2e18 + 13;
const int INF = 1e9 + 7;
mt19937 rng(time(nullptr) + 'm' + 'a' + 'n' + 'u' + 'l');
uniform_int_distribution<int> uid(0, INF);
int32_t main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i], b[i] = a[i];
    sort(b.begin(), b.end());
    int cnt = lower_bound(b.begin(), b.end(), 1) - b.begin();
    cout << cnt;
    int extra = 0;
    vector<pair<int, int> > ex;
    if (cnt > 1) ex.push_back({0, cnt - 1});
    for (int i = 1; i <= n; ++i) {
      if (cnt < i) {
        for (; i <= n; ++i) {
          cout << ' ' << -1;
        }
        cout << endl;
        goto NEXT;
      }
      int nums = upper_bound(b.begin(), b.end(), i) -
                 lower_bound(b.begin(), b.end(), i);
      cnt += nums;
      cout << ' ' << nums + extra;
      if (!nums) {
        if (ex.empty()) {
          for (i++; i <= n; ++i) {
            cout << ' ' << -1;
          }
          cout << endl;
          goto NEXT;
        }
        extra += i - ex.back().first;
        if (ex.back().second == 1)
          ex.pop_back();
        else
          ex.back().second--;
      } else if (nums > 1)
        ex.push_back({i, nums - 1});
    }
    cout << endl;
  NEXT:;
  }
  return 0;
}
