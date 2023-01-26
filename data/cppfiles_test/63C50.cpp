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
struct Bracket {
  string S;
  int tot;
  int low;
  vector<int> cnt;
  void init() {
    int c = 0;
    low = 0;
    cnt.resize(1);
    for (char x : S) {
      if (x == '(') {
        c++;
      } else {
        c--;
        if (c <= low) {
          if (c < low) {
            low = c;
            cnt.resize(-c + 1);
          }
          cnt[-c]++;
        }
      }
    }
    tot = c;
  }
  int solve(int lvl) {
    if (lvl < cnt.size()) return cnt[lvl];
    return 0;
  }
};
int N;
Bracket brackets[20];
int sumtot[1 << 20];
int dp[1 << 20];
int solve(int mask) {
  int& ret = dp[mask];
  if (ret >= 0) return ret;
  int lvl = sumtot[((1 << N) - 1) ^ mask];
  if (lvl < 0) return ret = 0;
  ret = 0;
  for (int i = 0; i < N; i++)
    if (mask & (1 << i)) {
      int r = brackets[i].solve(lvl);
      if (lvl + brackets[i].low >= 0) r += solve(mask ^ (1 << i));
      maxi(ret, r);
    }
  return ret;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout.setf(ios::fixed);
  cin >> N;
  for (int i = 0; i < N; i++) {
    auto& b = brackets[i];
    cin >> b.S;
    b.init();
  }
  for (int m = 1; m < (1 << N); m++) {
    int lb = __builtin_ctz(m);
    sumtot[m] = sumtot[m ^ (1 << lb)] + brackets[lb].tot;
  }
  memset(dp, -1, sizeof(dp[0]) << N);
  cout << solve((1 << N) - 1) << endl;
  return 0;
}
