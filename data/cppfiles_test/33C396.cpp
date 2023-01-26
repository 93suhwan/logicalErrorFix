#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000000")
#pragma GCC optimization("O3")
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    int n;
    cin >> n;
    vector<long long> p(n);
    for (auto& i : p) cin >> i;
    long long ans = 0;
    for (int i = 1; i < n; i++) ans = max(ans, p[i] * p[i - 1]);
    cout << ans << '\n';
  }
}
