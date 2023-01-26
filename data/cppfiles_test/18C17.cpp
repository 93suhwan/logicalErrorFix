#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const int mod = 1000000007;
void solv() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<bool> v(n);
  int anss = 0;
  for (int ind = 0; ind < n; ind++) {
    if (v[ind]) continue;
    int i = ind;
    int fr = -1, t = 0, ans = 0;
    int c = 0;
    while (1) {
      if (v[i]) break;
      v[i] = true;
      if (fr == -1 && a[i] == 0) fr = c;
      if (a[i] == 1)
        t++;
      else {
        ans = max(t, ans);
        t = 0;
      }
      c++;
      i += d;
      i %= n;
    }
    if (fr != -1)
      ans = max(ans, t + fr);
    else {
      cout << -1 << "\n";
      return;
    }
    anss = max(anss, ans);
  }
  cout << anss << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for (int curr_case = 1; curr_case <= test_cases; curr_case++) {
    solv();
  }
  return 0;
}
