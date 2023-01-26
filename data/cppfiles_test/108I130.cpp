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
  vector<int> A(N), B(N);
  for (int &a : A) {
    cin >> a;
  }
  for (int &b : B) {
    cin >> b;
  }
  string T = string(N, '0');
  int index1 = max_element(A.begin(), A.end()) - A.begin(),
      index2 = max_element(B.begin(), B.end()) - B.begin();
  T[index1] = T[index2] = '1';
  int min_x = A[index1], min_y = (B[index2]);
  auto simulate = [&]() {
    bool ans = false;
    for (int i = 0; i < N; i++) {
      if (T[i] == '0') {
        if (A[i] > min_x) {
          T[i] = '1';
          ans = true;
        } else if (B[i] > min_y) {
          T[i] = '1';
          ans = true;
        }
      }
      if (T[i] == '1') {
        min_x = min(min_x, A[i]);
        min_y = min(min_y, B[i]);
      }
    }
    return ans;
  };
  while (simulate()) {
  }
  cout << T;
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
