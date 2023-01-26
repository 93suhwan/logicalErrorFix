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
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<long long>> cnt(n + 1, vector<long long>(5));
    vector<long long> len(n + 1);
    for (long long i = 1, _c = n; i <= _c; ++i) {
      string s;
      cin >> s;
      len[i] = s.size();
      for (long long j = 0, _c = s.size() - 1; j <= _c; ++j)
        cnt[i][s[j] - 'a']++;
    }
    long long res = 0;
    for (long long i = 0, _c = 4; i <= _c; ++i) {
      long long cnt_i = 0, tot = 0, ret = n;
      priority_queue<tuple<long long, long long, long long>> q;
      for (long long j = 1, _c = n; j <= _c; ++j) {
        cnt_i += cnt[j][i];
        tot += len[j];
        q.push(make_tuple(len[j] - cnt[j][i], -cnt[j][i], j));
      }
      if (!cnt_i) continue;
      while (tot - cnt_i * 2 >= 0 && q.size()) {
        auto [sz, num, idx] = q.top();
        num = -num;
        q.pop();
        tot -= len[idx];
        cnt_i -= num;
        ret--;
      }
      res = max(res, ret);
    }
    cout << res << "\n";
  }
}
