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
std::vector<int> A;
int dp[10010][2048];
int solve(int base, int pos) {
  if (base > 2048) return base;
  int& ret = dp[pos][base];
  if (ret >= 0) return ret;
  if (pos == A.size()) return ret = base;
  ret = solve(base + A[pos], pos + 1);
  if (base >= A[pos]) mini(ret, max(base, solve(base - A[pos], pos + 1)));
  return ret;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout.setf(ios::fixed);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    readv(A);
    int N = A.size();
    int ret = INT_MAX;
    for (int i = 0; i <= A.size(); i++) memset(dp[i], -1, sizeof(dp[i]));
    for (int b = 0; b <= 1000; b++) mini(ret, solve(b, 0));
    cout << ret << endl;
  }
  return 0;
}
