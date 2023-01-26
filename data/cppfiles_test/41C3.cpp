#include <bits/stdc++.h>
using namespace std;
int color(int a, int b, int K) {
  int c = 0;
  while (a != b) {
    ++c;
    a /= K, b /= K;
  }
  return c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k, pw = 1, c = 0;
  cin >> n >> k;
  while (pw < n) {
    pw *= k;
    ++c;
  }
  cout << c << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << color(i, j, k) << ' ';
    }
  }
  cout << '\n';
  return 0;
}
