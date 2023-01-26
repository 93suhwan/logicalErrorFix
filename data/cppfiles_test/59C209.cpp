#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 1][10];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> arr[i][j];
      }
    }
    int flag = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int a = 0;
        int b = 0;
        int comm = 0;
        for (int k = 0; k < n; k++) {
          if (arr[k][i]) {
            a++;
          }
          if (arr[k][j]) {
            b++;
          }
          if (arr[k][i] && arr[k][j]) {
            comm++;
          }
        }
        int maj = n / 2;
        if (a >= maj && b >= maj) {
          a = (a - maj);
          int temp = max(0, comm - a);
          b -= temp;
          if (b >= maj) {
            flag = 1;
            break;
          }
        }
      }
    }
    if (flag) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
