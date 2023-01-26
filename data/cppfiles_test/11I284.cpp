#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const long long mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
const long double pie = acos(-1);
long long ind = 0;
bool comp(string &a, string &b) {
  long long cnt[2][5] = {};
  for (char x : a) {
    cnt[0][x - 'a']++;
  }
  for (char x : b) {
    cnt[1][x - 'a']++;
  }
  return cnt[0][ind] > cnt[1][ind];
}
void solve_LOL() {
  long long n;
  cin >> n;
  vector<string> vec(n);
  for (long long i = 0; i <= n - 1; i++) {
    cin >> vec[i];
  }
  long long ans = 0;
  for (long long j = 0; j <= 4; j++) {
    ind = j;
    sort((vec).begin(), (vec).end(), comp);
    long long tot = 0;
    long long cnt = 0;
    long long temp = 0;
    vector<bool> used(n);
    for (long long i = 0; i <= n - 1; i++) {
      long long c = 0;
      long long t = 0;
      for (char x : vec[i]) {
        t++;
        if (x - 'a' == j) c++;
      }
      if (2 * (cnt + c) > t + tot) {
        cnt += c;
        tot += t;
        temp++;
        used[i] = true;
      }
    }
    for (long long i = 0; i <= n - 1; i++) {
      if (used[i]) continue;
      long long c = 0;
      long long t = 0;
      for (char x : vec[i]) {
        t++;
        if (x - 'a' == j) c++;
      }
      if (2 * (cnt + c) > t + tot) {
        cnt += c;
        tot += t;
        temp++;
        used[i] = true;
      }
    }
    ans = max(ans, temp);
  }
  cout << ans;
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long _t = 1;
  cin >> _t;
  for (long long i = 1; i <= _t; i++) {
    solve_LOL();
  }
  return 0;
}
