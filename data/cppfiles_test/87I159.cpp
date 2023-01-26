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
void dbg_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
void run_case() {
  int N;
  cin >> N;
  vector<int> A(N);
  int max_val = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    max_val = max(max_val, A[i]);
  }
  int index = 0;
  while (A[index] != max_val) {
    index++;
  }
  cout << max(0, max_val - (index + 1));
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    run_case();
    cout << '\n';
  }
}
