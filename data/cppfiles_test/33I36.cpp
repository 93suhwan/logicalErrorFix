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
  os << '[';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << ']';
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const int A_MAX = 501;
void steal() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int &a : A) cin >> a;
  vector<int> dp(A_MAX * 10);
  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < A[i]; ++j)
      if (dp[j]) {
        dp[A[i] ^ j] = 1;
      }
  }
  int total = 0;
  for (int i : dp) total += i;
  cout << total << '\n';
  for (int i = 0; i < int(dp.size()); ++i)
    if (dp[i]) cout << i << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  steal();
}
