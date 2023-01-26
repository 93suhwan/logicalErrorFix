#include <bits/stdc++.h>
using namespace std;
int a[20];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<int> v;
    int y = n;
    while (y) {
      v.push_back(y % 10);
      y /= 10;
    }
    reverse(v.begin(), v.end());
    int sz = v.size();
    if (k == 1) {
      bool les = 0, bg = 0;
      for (int i = 1; i < sz; i++) {
        if (v[i] < v[0])
          les = 1;
        else if (v[i] > v[0]) {
          bg = 1;
          break;
        }
      }
      if (!les && bg)
        for (int i = 0; i < sz; i++) a[i] = v[0] + 1;
      else
        for (int i = 0; i < sz; i++) a[i] = v[0];
      for (int i = 0; i < sz; i++) cout << a[i];
      cout << '\n';
      continue;
    }
    int cnt[11] = {0};
    int cc = 0;
    for (auto i : v)
      if (!cnt[i]) cc++, cnt[i]++;
    if (cc <= k) {
      cout << n << '\n';
      continue;
    }
    for (int i = 0; i < 10; i++) cnt[i] = 0;
    cc = 0;
    int mn = 10, mx = -1;
    for (int i = 0; i < sz; i++) {
      int x = v[i];
      if (!cnt[x]) {
        cc++;
      }
      if (cc > k) {
        if (x > mx) {
          int sum = 0;
          for (int j = i - 1; j >= 0; j--) {
            if (v[j] != mx) break;
            sum++;
          }
          if (sum == cnt[mx]) {
            for (int j = i - 1; j >= 0; j--) {
              if (v[j] == mx)
                a[j] = mn;
              else {
                a[j + 1] = mx + 1;
                break;
              }
            }
            for (int j = i; j < sz; j++) a[j] = mn;
          } else {
            for (int j = i - 1; j >= 0; j--) {
              if (v[j] != mx) {
                int y, nx;
                if (cnt[v[j]] == 1) {
                  y = v[j] + 1, nx;
                  if (cnt[y]) {
                    nx = 0;
                  } else {
                    if (v[j] == mn)
                      nx = y;
                    else
                      nx = mn;
                  }
                } else {
                  for (y = v[j] + 1; y < 10; y++) {
                    if (cnt[y]) break;
                  }
                  nx = mn;
                }
                a[j] = y;
                for (int q = j + 1; q < sz; q++) {
                  a[q] = nx;
                }
                break;
              }
            }
          }
        } else {
          for (int j = x + 1; j < 10; j++) {
            if (cnt[j]) {
              a[i] = j;
              break;
            }
          }
          for (int j = i + 1; j < sz; j++) a[j] = mn;
        }
        break;
      }
      a[i] = x;
      cnt[x]++;
      mn = min(mn, x), mx = max(mx, x);
    }
    for (int i = 0; i < sz; i++) cout << a[i];
    cout << '\n';
  }
  return 0;
}
