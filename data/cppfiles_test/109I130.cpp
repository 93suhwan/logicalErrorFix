#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
double eps = 1e-12;
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long cnt_zero_mid = 0;
  long long cnt = 0, flag = 0;
  long long f1 = 0, f2 = 0;
  for (long long i = 0; i < (s.length()); ++i) {
    if (s[i] != '0') {
      f1 = 1;
    }
    if (f1 == 1 && s[i] != '0') {
      flag++;
    }
    if (f1 == 1 && s[i] == '0') {
      f2 = 1;
      cnt_zero_mid++;
    }
    cnt += s[i] - '0';
  }
  if (cnt != 0) {
    flag--;
  }
  if (cnt_zero_mid == 1) {
    f2 = 0;
  }
  cout << cnt + f2 + flag << "\n";
  ;
  return 0;
}
int main() {
  fast_io();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
