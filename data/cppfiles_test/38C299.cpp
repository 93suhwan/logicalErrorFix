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
    if (N % 2 == 1) {
      N += 1;
    }
    N /= 2;
    if (N < 3) {
      N = 3;
    }
    cout << N * 5 << "\n";
  }
}
