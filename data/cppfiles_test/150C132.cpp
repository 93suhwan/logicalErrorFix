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
  int MX = *max_element(A.begin(), A.end()) / 3 + 100;
  int best = MX;
  for (int ones = 0; ones <= 2; ++ones)
    for (int twos = 0; twos <= 2; ++twos) {
      int threes = 0;
      for (int a : A) {
        int least = MX;
        for (int one = 0; one <= ones; ++one)
          for (int two = 0; two <= twos; ++two) {
            int want = a - two * 2 - one;
            if (want % 3 != 0 || want < 0) continue;
            least = min(least, want / 3);
          }
        threes = max(threes, least);
      }
      best = min(best, ones + twos + threes);
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
