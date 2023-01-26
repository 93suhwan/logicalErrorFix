#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) { return l + rng() % (r - l + 1); }
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const long long N = 110;
long long a[N], b[3][N], cnt[3];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long st_pos = 0;
    for (long long i = 1, _c = n; i <= _c; ++i) {
      char inp;
      cin >> inp;
      if (inp == 'B')
        a[i] = 1;
      else if (inp == 'R')
        a[i] = 2;
      else
        a[i] = 3;
      if (a[i] < 3 && !st_pos) st_pos = i;
    }
    for (long long st = 1, _c = 2; st <= _c; ++st) {
      for (long long i = 1, _c = n; i <= _c; ++i) b[st][i] = a[i];
      long long curr = st;
      for (long long i = 1, _c = n; i <= _c; ++i) {
        if (a[i] == 3)
          b[st][i] = curr, curr = 3 - curr;
        else
          curr = 3 - a[i];
      }
    }
    for (long long col = 1, _c = 2; col <= _c; ++col)
      for (long long i = 1, _c = n - 1; i <= _c; ++i)
        if (b[col][i] == b[col][i + 1]) cnt[col]++;
    long long res = (cnt[1] < cnt[2]) ? 1 : 2;
    for (long long i = 1, _c = n; i <= _c; ++i)
      cout << ((b[res][i] == 1) ? 'B' : 'R');
    cout << "\n";
  }
}
