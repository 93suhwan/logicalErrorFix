#include <bits/stdc++.h>
using namespace std;
int t, n;
bool used[21000];
int que(int o2, int o3, int o4) {
  int o;
  cout << "? " << o2 << " " << o3 << " " << o4 << "\n";
  cin >> o;
  return o;
}
int mem[21000];
queue<int> q;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i < n / 3 + 1; i++) {
      int a = 3 * i - 2, b = 3 * i - 1, c = 3 * i;
      used[i] = que(a, b, c);
    }
    int l, r, ll, rr;
    for (int i = 1; i < n / 3; i++) {
      if ((used[i] == 1 && used[i + 1] == 0) ||
          (used[i] == 0 && used[i + 1] == 1)) {
        l = i;
        break;
      }
    }
    int ans[5];
    ans[1] = used[l];
    ans[4] = used[l + 1];
    ans[2] = que(3 * l - 1, 3 * l, 3 * l + 1);
    ans[3] = que(3 * l, 3 * l + 1, 3 * l + 2);
    int lll = l;
    for (int i = 1; i < 4; i++) {
      if (ans[i] != ans[i + 1]) {
        l = 3 * l - 3 + i;
        r = l + 3;
        if (ans[i] == 0) {
          ll = 0;
          rr = 1;
        } else {
          ll = 1;
          rr = 0;
        }
        break;
      }
    }
    int o1, o2;
    if (ll == 0) {
      o1 = l;
      o2 = r;
    } else {
      o1 = r;
      o2 = l;
    }
    for (int i = 1; i < n / 3 + 1; i++) {
      if (i == lll || i == lll + 1) {
        for (int j = 3 * i - 2; j < 3 * i + 1; j++) {
          if (l == j) {
            if (ll == 0) q.push(j);
          } else if (r == j) {
            if (rr == 0) q.push(j);
          } else {
            if (que(l, r, j) == 0) q.push(j);
          }
        }
      } else {
        if (used[i] == 1) {
          if (que(o1, 3 * i - 2, 3 * i - 1) == 1) {
            if (que(l, r, 3 * i) == 0) q.push(3 * i);
          } else {
            if (que(l, r, 3 * i - 1) == 0)
              q.push(3 * i - 1);
            else
              q.push(3 * i - 2);
          }
        } else {
          if (que(o2, 3 * i - 2, 3 * i - 1) == 0) {
            q.push(3 * i - 2);
            q.push(3 * i - 1);
            if (que(l, r, 3 * i) == 0) q.push(3 * i);
          } else {
            q.push(3 * i);
            if (que(l, r, 3 * i - 1) == 0)
              q.push(3 * i - 1);
            else
              q.push(3 * i - 2);
          }
        }
      }
    }
    cout << "! " << q.size() << " ";
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      cout << u << " ";
    }
    cout << "\n";
  }
}
