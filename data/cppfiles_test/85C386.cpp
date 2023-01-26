#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
void input() {
  string second;
  cin >> second;
  long long int ans = 2, a = 0;
  for (int i = 0; i < second.size(); i++) {
    if (second[i] == '0') {
      while ((i + 1) < second.size() && second[i + 1] == '0') {
        i++;
      }
      a += 1;
    } else {
      while ((i + 1) < second.size() && second[i + 1] == '1') {
        i++;
      }
    }
  }
  ans = min(ans, a);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    input();
  }
  return 0;
}
