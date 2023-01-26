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
struct point {
  int x, y;
};
long long choose2(long long n) { return n * (n - 1) / 2; }
long long choose3(long long n) { return n * (n - 1) * (n - 2) / 6; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<point> pt(N);
  for (int i = 0; i < N; ++i) {
    cin >> pt[i].x >> pt[i].y;
  }
  vector<long long> freq(4);
  for (int i = 0; i < N; ++i) {
    freq[((pt[i].x / 2) % 2) + (((pt[i].y / 2) % 2) << 1)]++;
  };
  long long total = choose3(N);
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      for (int k = j + 1; k < 4; ++k) {
        total -= freq[i] * freq[j] * freq[k];
      }
    }
  }
  cout << total << "\n";
  return 0;
}
