#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
long long vec[2000005];
void solve() {
  long long m, n;
  cin >> n >> m;
  vec[1] = 1;
  long long sum = 1;
  for (int i = 2; i < n + 1; i++) {
    vector<long long> v;
    for (int l = 2, r = 0; l <= i; l++) {
      r = i / (i / l);
      vec[i] += vec[i / r] * (r - l + 1);
      l = r;
    }
    vec[i] += sum;
    sum %= m;
    vec[i] %= m;
    sum += vec[i];
  }
  cout << vec[n] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  n = 1;
  while (n--) solve();
}
