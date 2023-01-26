#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
int gcd(int x, int y) {
  if (x == 0 || y == 0) return x + y;
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}
const int N = 200009;
int a[N + 1];
int main(int argc, const char* argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = (1); i <= (n); ++i) {
      scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int it = (0); it <= (30); ++it) {
      int cur = 0;
      for (int i = (1); i <= (n); ++i) {
        if (a[i] & (1 << it))
          cur++;
        else {
          ans = gcd(ans, cur);
          cur = 0;
        }
      }
      ans = gcd(ans, cur);
    }
    vector<int> ret;
    for (int i = 1; i * i <= ans; i++) {
      if (ans % i == 0) {
        ret.push_back(i);
        if (i != ans / i) ret.push_back(ans / i);
      }
    }
    if (ans == 0) {
      for (int i = (1); i <= (n); ++i) ret.push_back(i);
    }
    for (auto x : ret) printf("%d ", x);
    cout << endl;
  }
  return 0;
}
