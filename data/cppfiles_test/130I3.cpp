#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chmax(T &x, const T &y) {
  return (x < y) ? (x = y, true) : false;
};
template <typename T>
bool chmin(T &x, const T &y) {
  return (x > y) ? (x = y, true) : false;
};
constexpr long long int MOD = 998244353;
constexpr long long int INF = 2e18;
int q(int a, int b, int c) {
  a++, b++, c++;
  cout << "? " << a << " " << b << " " << c << endl;
  int res;
  cin >> res;
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = -1, y = -1;
    vector<long long int> flg(n / 3);
    for (long long int i = 0; i < (n / 3); i++) {
      int res = q(i * 3, i * 3 + 1, i * 3 + 2);
      flg[i] = res;
      if (res == 0)
        x = i * 3;
      else
        y = i * 3;
    }
    int xx, yy;
    int xp = -1;
    vector<long long int> ans(n, -1);
    for (long long int i = 0; i < (3); i++) {
      int cnt = 0;
      if (xp == -1) {
        for (long long int j = 0; j < (3); j++) {
          int res = q(x + i, x + (i + 1) % 3, y + j);
          if (res == 1) {
            xp = y + j;
            ans[y + j] = 1;
            cnt += 1;
          }
        }
      } else {
        int res = q(x + i, x + (i + 1) % 3, xp);
        if (res == 1) cnt += 1;
      }
      if (cnt == 0) {
        ans[x + i] = 0;
        ans[x + (i + 1) % 3] = 0;
        xx = x + i;
        break;
      }
    }
    for (long long int i = 0; i < (3); i++) {
      int cnt = 0;
      int res = q(y + i, y + (i + 1) % 3, xx);
      if (res == 0) cnt += 1;
      if (cnt == 0) {
        ans[y + i] = 1;
        ans[y + (i + 1) % 3] = 1;
        yy = y + i;
        break;
      }
    }
    for (long long int i = 0; i < (n / 3); i++) {
      if (ans[i * 3] == -1 && ans[i * 3 + 1] == -1 && ans[i * 3 + 2] == -1) {
        int resx, resy;
        if (flg[i] == 0) {
          resx = q(yy, i * 3, i * 3 + 1);
          resy = q(yy, i * 3 + 1, i * 3 + 2);
          ans[i * 3] = 0;
          ans[i * 3 + 1] = 0;
          ans[i * 3 + 2] = 0;
          if (resx == 1 && resy == 1)
            ans[i * 3 + 1] = 1;
          else if (resx == 1)
            ans[i * 3] = 1;
          else
            ans[i * 3 + 2] = 1;
        } else {
          resx = q(xx, i * 3, i * 3 + 1);
          resy = q(xx, i * 3 + 1, i * 3 + 2);
          ans[i * 3] = 1;
          ans[i * 3 + 1] = 1;
          ans[i * 3 + 2] = 1;
          if (resx == 0 && resy == 0)
            ans[i * 3 + 1] = 0;
          else if (resx == 0)
            ans[i * 3] = 0;
          else
            ans[i * 3 + 2] = 0;
        }
      }
    }
    for (long long int i = 0; i < (n); i++) {
      if (ans[i] == -1) ans[i] = q(xx, yy, i);
    }
    vector<long long int> a;
    for (long long int i = 0; i < (n); i++) {
      if (ans[i] == 0) a.push_back(i);
    }
    cout << "! " << a.size();
    for (auto i : a) cout << " " << i + 1;
    cout << endl;
  }
  return 0;
}
