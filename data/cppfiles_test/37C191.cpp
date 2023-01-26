#include <bits/stdc++.h>
using namespace std;
long long n, T, m, a, b, c;
long long goc, N, cl[100005];
void outp() {
  for (long long i = 1; i <= n; i++) {
    if (cl[i] < N) {
      goc = i;
      break;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (i != goc) {
      cout << goc << " " << i << "\n";
    }
  }
}
void inp() {
  cin >> T;
  N = 0;
  for (long long t = 1; t <= T; t++) {
    N++;
    cin >> n >> m;
    for (long long i = 1; i <= m; i++) {
      cin >> a >> b >> c;
      cl[b] = N;
    }
    outp();
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  inp();
}
