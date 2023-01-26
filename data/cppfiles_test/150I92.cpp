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
void run_case() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int &a : A) cin >> a;
  int MX = *max_element(A.begin(), A.end()) / 3;
  int best = MX + 100;
  for (int ones = 0; ones <= 5; ++ones)
    for (int twos = 0; twos <= 5; ++twos)
      for (int threes = max(MX - 3, 0); threes <= MX + 3; ++threes) {
        bool good = true;
        for (int i = 0; i < N; ++i) {
          int th = A[i] / 3;
          int tw = A[i] % 3 + max(0, (th - threes) * 3);
          int o = tw % 2 + max(0, (tw / 2 - twos) * 2);
          if (ones < o) good = false;
        }
        if (good) best = min(best, threes + twos + ones);
      }
  cout << best << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--) run_case();
}
