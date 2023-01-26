#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const double PI = 3.141592653589793;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T;
  cin >> T;
  for (long long testcase = 0; testcase < T; ++testcase) {
    long long N;
    cin >> N;
    long long ans = N / 120 * 300;
    N %= 120;
    vector<long long> dp(N + 1, 2000000000000000000);
    dp.at(0) = 0;
    for (long long i = 0; i < N; ++i) {
      chmin(dp.at(min(N, i + 6)), dp.at(i) + 15);
      chmin(dp.at(min(N, i + 8)), dp.at(i) + 20);
      chmin(dp.at(min(N, i + 10)), dp.at(i) + 25);
    }
    cout << dp.at(N) + ans << "\n";
  }
}
