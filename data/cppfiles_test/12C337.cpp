#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long n, m, k, xx, t, cnt, cnt1, bb[N][N];
char ans[N][N], ans1[N][N];
void go(int i, int j) {
  if (k > 0) {
    if (bb[i][j] == 1) {
      ans[i][j] = 'a';
      ans[i][j + 1] = 'a';
      ans[i + 1][j] = 'b';
      ans[i + 1][j + 1] = 'b';
    } else {
      ans[i][j] = 'c';
      ans[i][j + 1] = 'c';
      ans[i + 1][j] = 'd';
      ans[i + 1][j + 1] = 'd';
    }
    k -= 2;
  } else {
    if (bb[i][j] == 1) {
      ans[i][j] = 'a';
      ans[i + 1][j] = 'a';
      ans[i][j + 1] = 'b';
      ans[i + 1][j + 1] = 'b';
    } else {
      ans[i][j] = 'c';
      ans[i + 1][j] = 'c';
      ans[i][j + 1] = 'd';
      ans[i + 1][j + 1] = 'd';
    }
  }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        cout << "YES" << endl;
        cnt1 = 0;
        continue;
      }
      cout << "NO" << endl;
      continue;
    }
    long long fff = 0;
    if (n % 2 == 1) swap(n, m), k = (n * m) / 2 - k, fff = 1;
    if (k % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }
    xx = n * m - n;
    xx /= 2;
    if (k > xx) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
}
