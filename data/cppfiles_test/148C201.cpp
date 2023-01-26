#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << "[" << *it << ": " << a << "]\t";
  err(++it, args...);
}
void solver() {
  long long n, m;
  cin >> n >> m;
  long long k, p;
  cin >> k;
  long long ans = -1;
  long long mini = INT_MAX, maxx = -1;
  for (long long i = 0; i < k; i++) {
    cin >> p;
    mini = min(mini, p);
    maxx = max(maxx, p);
  }
  ans = max(ans, (maxx - mini) * m);
  cin >> k;
  mini = INT_MAX, maxx = -1;
  for (long long i = 0; i < k; i++) {
    cin >> p;
    mini = min(mini, p);
    maxx = max(maxx, p);
  }
  ans = max(ans, (maxx - mini) * m);
  cin >> k;
  mini = INT_MAX, maxx = -1;
  for (long long i = 0; i < k; i++) {
    cin >> p;
    mini = min(mini, p);
    maxx = max(maxx, p);
  }
  ans = max(ans, (maxx - mini) * n);
  cin >> k;
  mini = INT_MAX, maxx = -1;
  for (long long i = 0; i < k; i++) {
    cin >> p;
    mini = min(mini, p);
    maxx = max(maxx, p);
  }
  ans = max(ans, (maxx - mini) * n);
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solver();
  }
  return 0;
}
