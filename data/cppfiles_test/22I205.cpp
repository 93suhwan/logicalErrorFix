#include <bits/stdc++.h>
using namespace std;
int n, k;
int len[45];
bool fl;
int q[15][45];
int a[45];
void yes() { cout << "ACCEPTED" << endl; }
void no() { cout << "REJECTED" << endl; }
void recur(int pos) {
  if (pos == k + 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i] == -1) {
        fl = 0;
        return;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i > 1 && a[i] < a[i - 1]) {
        fl = 0;
        return;
      }
    }
  } else {
    int tmp[45];
    for (int i = 1; i <= n; i++) {
      tmp[i] = a[i];
    }
    int sum = 0;
    int sum2 = 0;
    int nw = 0;
    for (int i = 1; i <= len[pos]; i++) {
      int cur = q[pos][i];
      if (a[cur] == -1) {
        ++nw;
      } else if (a[cur] == 0) {
        ++sum;
      } else {
        ++sum2;
      }
    }
    for (int w = 0; w <= nw; w++) {
      for (int i = 1; i <= len[pos]; i++) {
        int cur = q[pos][i];
        if (i <= sum + w) {
          a[cur] = 0;
        } else {
          a[cur] = 1;
        }
      }
      recur(pos + 1);
      if (!fl) return;
      for (int i = 1; i <= n; i++) {
        a[i] = tmp[i];
      }
    }
  }
}
void solve() {
  fl = 1;
  cin >> n >> k;
  if (k == 0) {
    if (n == 1) {
      yes();
    } else {
      no();
    }
  }
  for (int i = 1; i <= k; i++) {
    cin >> len[i];
    for (int j = 1; j <= len[i]; j++) {
      cin >> q[i][j];
    }
  }
  memset(a, -1, sizeof(a));
  recur(1);
  if (fl)
    yes();
  else
    no();
}
int main() {
  solve();
  return 0;
}
