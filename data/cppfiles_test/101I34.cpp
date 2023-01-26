#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
void run_cases() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto& u : A) cin >> u;
  string S;
  cin >> S;
  vector<int> blue, red;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') {
      red.push_back(A[i]);
    } else {
      blue.push_back(A[i]);
    }
  }
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());
  for (int i = 1; i <= N; i++) {
    int blue_places = upper_bound(blue.begin(), blue.end(), i) - blue.begin();
    int red_places = red.end() - lower_bound(red.begin(), red.end(), i);
    debug() << " ["
            << "red_places"
               ": "
            << (red_places)
            << "] "
               " ["
            << "blue_places"
               ": "
            << (blue_places) << "] ";
    if (blue_places > i) {
      cout << "NO\n";
      return;
    }
    if (red_places > N - i + 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int tests = 1;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    run_cases();
  }
}
