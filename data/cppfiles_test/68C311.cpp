#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2", "avx", "fma", "sse", "sse2", "sse3", "ssse3", "sse4")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T;
  cin >> T;
  for (; T-- > 0;) {
    long long int n, num, row, cl;
    cin >> n;
    num = (long long int)ceil(sqrt(n));
    long long int sq = num * num;
    long long int d = sq - n;
    if (d < num) {
      row = num;
      cl = d + 1;
    } else {
      cl = num;
      d -= num;
      d = num - d - 1;
      row = d;
    }
    cout << row << " " << cl << "\n";
  }
  exit(0);
  return (0);
}
