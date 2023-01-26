#include <bits/stdc++.h>
using namespace std;
int ans;
int x, y;
void rec(vector<int> v, int *a) {
  int d[4]{0};
  int l[4];
  vector<int> w0, w1;
  for (int i : v) {
    for (int j = 0; j < 30; j++) {
      if ((1 << j) >= a[i]) {
        if (j > d[a[i] & 3]) {
          d[a[i] & 3] = j;
          l[a[i] & 3] = i;
        }
        break;
      }
    }
    if ((a[i] & 3) == 0 || (a[i] & 3) == 3)
      w0.push_back(i);
    else
      w1.push_back(i);
  }
  if (d[0] + d[1] + 1 > ans) {
    ans = d[0] + d[1] + 1;
    x = l[0];
    y = l[1];
  }
  if (d[2] + d[3] + 1 > ans) {
    ans = d[2] + d[3] + 1;
    x = l[2];
    y = l[3];
  }
  if (d[0] + d[2] > ans) {
    ans = d[0] + d[2];
    x = l[0];
    y = l[2];
  }
  if (d[1] + d[3] > ans) {
    ans = d[1] + d[3];
    x = l[1];
    y = l[3];
  }
  for (int i : v) a[i] >>= 1;
  if ((int)w0.size() >= 2) rec(w0, a);
  if ((int)w1.size() >= 2) rec(w1, a);
}
int main() {
  int n;
  cin >> n;
  vector<int> v[32];
  int a[200005];
  int d[32]{0};
  int l[32]{0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 30; j++) {
      int b = a[i];
      int c = 0;
      while (b) {
        for (int j = 0; j <= 30; j++) {
          if ((1 << j) >= b) {
            b = (1 << j) - b;
            break;
          }
        }
        c++;
      }
      if ((a[i] >> j) & 1) {
        v[j].push_back(i);
        if (c > d[j]) {
          d[j] = c;
          l[j] = i;
        }
        break;
      }
    }
  }
  for (int i = 0; i < 30; i++) {
    for (int j = i + 1; j < 30; j++) {
      if (d[i] + d[j] > ans) {
        ans = d[i] + d[j];
        x = l[i];
        y = l[j];
      }
    }
  }
  for (int k = 0; k < 30; k++) {
    for (int i : v[k]) a[i] >>= k + 1;
    rec(v[k], a);
  }
  cout << x + 1 << " " << y + 1 << " " << ans << endl;
}
