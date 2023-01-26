#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void fun() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int res = 0;
  for (int i = 0; i < n - 2; i++) {
    if (str[i] != '0') {
      res += (str[i] - '0') + 1;
      str[i] = '0';
    }
  }
  if (n == 1) {
    cout << str << "\n";
    return;
  }
  res += str[n - 2] == '0' ? 0 : (str[n - 2] - '0' + 1);
  res += str[n - 1] - '0';
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    fun();
  }
  return 0;
}
