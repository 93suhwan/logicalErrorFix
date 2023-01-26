#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt_big = n % m;
    int num_big = ceil(1.0 * n / m);
    int cnt_small = m - n % m;
    int num_small = floor(1.0 * n / m);
    for (int i = 0; i < k; i++) {
      int v = 1ll * cnt_big * num_big % n * i % n;
      for (int j = 0; j < cnt_big; j++) {
        cout << num_big << " ";
        for (int t = 0; t < num_big; t++) {
          v = v % n + 1;
          cout << v << " ";
        }
        cout << endl;
      }
      for (int j = 0; j < cnt_small; j++) {
        cout << num_small << " ";
        for (int t = 0; t < num_small; t++) {
          v = v % n + 1;
          cout << v << " ";
        }
        cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
