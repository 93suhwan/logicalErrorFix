#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 10000000;
double eps = 1e-12;
void solve() {
  long long n;
  cin >> n;
  string ans = "";
  long long o;
  long long flag = 0;
  if (n == 1) {
    cout << "a" << endl;
    return;
  }
  if (n % 2 == 0) {
    o = n / 2;
    for (long long i = 0; i < o; ++i) {
      ans.push_back('a');
    }
    ans.push_back('b');
    for (long long i = 0; i < o - 1; i++) {
      ans.push_back('a');
    }
    cout << ans << endl;
    return;
  } else {
    n--;
    o = n / 2;
    for (long long i = 0; i < o; ++i) {
      ans.push_back('a');
    }
    ans.push_back('b');
    ans.push_back('c');
    for (long long i = 0; i < o - 1; i++) {
      ans.push_back('a');
    }
    cout << ans << endl;
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
