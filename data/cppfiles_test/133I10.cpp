#include <bits/stdc++.h>
#pragma GCC optimize(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           \
    "-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", \
    3)
#pragma GCC target("avx", "sse2")
using namespace std;
clock_t START_TIME, END_TIME;
template <typename T>
void Print(T value) {
  std::cout << value << '\n';
}
template <typename Head, typename... Rail>
void Print(Head head, Rail... rail) {
  std::cout << head << ", ";
  Print(rail...);
}
long long read() {
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
long long t, n;
string w[800005];
signed main(void) {
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n - 2; i++) cin >> w[i];
    string ans = "";
    ans = ans + w[1][0];
    for (long long i = 2; i <= n - 2; i++) {
      if (w[i][0] != w[i - 1][1]) {
        ans = ans + w[i - 1][1];
        ans = ans + w[i][0];
        cout << ans << '\n';
      }
      ans = ans + w[i][0];
    }
    while (ans.length() < n) ans = ans + 'a';
    cout << ans << '\n';
  }
  return 0;
}
