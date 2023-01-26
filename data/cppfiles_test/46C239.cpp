#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vs = vector<string>;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vii = vector<pi>;
using vvi = vector<vi>;
using vvii = vector<vii>;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << '\n';
  ;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
const ll MOD = 1e9 + 7;
inline ll read_int() {
  ll x;
  cin >> x;
  return x;
}
inline string read_str() {
  string x;
  cin >> x;
  return x;
}
inline char read_chr() {
  char x;
  cin >> x;
  return x;
}
inline void read(vi &x) {
  for (auto &i : (x)) cin >> i;
}
inline void read(pi &x) { cin >> x.first >> x.second; }
inline void out(vi &x) {
  for (int i = (0); (i) < ((int)x.size()); ++(i)) {
    if (i) cout << ' ';
    cout << x[i];
  }
  cout << '\n';
  ;
}
inline ll first(pi A) { return A.first; }
inline ll second(pi A) { return A.second; }
inline void out(pi &x) {
  cout << first(x) << ' ' << second(x) << '\n';
  ;
}
inline void out(string S) {
  cout << S << '\n';
  ;
}
inline void out(ll x) {
  cout << x << '\n';
  ;
}
inline ll exp(ll A, ll B, ll M) {
  ll ANS = 1;
  while (B) {
    if (B & 1) ANS = ANS * A % M;
    A = A * A % M;
    B >>= 1;
  }
  return ANS;
}
inline bool is_lex_smaller(string A, string B) {
  for (int i = (0); (i) < (min((int)A.size(), (int)B.size())); ++(i)) {
    if (A[i] < B[i])
      return true;
    else if (A[i] > B[i])
      return false;
  }
  return (int)A.size() < (int)B.size();
}
inline bool is_lex_greater(string A, string B) {
  for (int i = (0); (i) < (min((int)A.size(), (int)B.size())); ++(i)) {
    if (A[i] > B[i])
      return true;
    else if (A[i] < B[i])
      return false;
  }
  return (int)A.size() > (int)B.size();
}
inline bool is_valid_x_y(ll X, ll Y, ll N, ll M) {
  return (X >= 0 && X < N && Y >= 0 && Y < M);
}
int tc;
void test_case() {
  ll N = read_int();
  vi A(N);
  read(A);
  vi B = A;
  sort(B.begin(), B.end());
  if (A[N - 1] == B[N - 1]) {
    out(0);
    return;
  }
  ll K = A[N - 1];
  ll j = N - 1;
  ll ANS = 0;
  while (j >= 0 && A[j] != B[N - 1]) {
    while (j >= 0 && A[j] <= K) {
      j--;
    }
    if (j >= 0) ANS++, K = A[j];
  }
  out(ANS);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll TC = 1;
  TC = read_int();
  for (int i = (0); (i) < (TC); ++(i)) tc++, test_case();
  return 0;
}
