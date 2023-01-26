#include <bits/stdc++.h>
template <class C>
C& mini(C& a, C b) {
  if (b < a) a = b;
  return a;
}
template <class C>
C& maxi(C& a, C b) {
  if (a < b) a = b;
  return a;
}
template <typename T>
void read(std::vector<T>& A) {
  for (T& x : A) std::cin >> x;
}
template <typename T>
void readv(std::vector<T>& A) {
  int N;
  std::cin >> N;
  A.resize(N);
  read(A);
}
using namespace std;
int getmask(int N) {
  int b = 1;
  while (b <= N) b <<= 1;
  return b - 1;
}
int solve(int N, int M) {
  if (N == 0) return M + 1;
  if (N > M) return 0;
  int m = getmask(N);
  int left = M & ~m, right = M & m;
  if (left == 0) {
    assert(right);
    if (((right + 1) & right) == 0) return M + 1;
    int b = (m + 1) >> 1;
    assert(N & b);
    assert(M & b);
    return solve(N ^ b, M ^ b);
  } else {
    return left ^ solve(N, M ^ left);
  }
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout.setf(ios::fixed);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, M;
    cin >> N >> M;
    cout << solve(N, M) << '\n';
  }
  return 0;
}
