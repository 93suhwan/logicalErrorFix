#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int a[N], b[N], ans[N];
int tag[N];
set<int> h;
int temp[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    h.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      ans[i] = tag[i] = 0;
      h.insert(i);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
    }
    int Max = 0, p;
    for (int i = 1; i <= n; i++) {
      if (a[i] > Max) {
        Max = a[i];
        p = i;
      }
    }
    h.erase(p);
    ans[p] = tag[p] = 1;
    int x = b[p];
    int Ty = 0;
    int Min = INT_MAX;
    int all = 0;
    while (1) {
      if (Ty == 0) {
        Min = INT_MAX;
        for (set<int>::iterator i = h.begin(); i != h.end(); i++) {
          int kk = *i;
          if (b[kk] > x) {
            ans[kk] = 1;
            if (!tag[kk]) {
              Min = min(Min, a[kk]);
              tag[kk] = 1;
            }
            temp[++all] = kk;
          }
        }
        if (Min == INT_MAX) {
          break;
        }
        x = Min;
        Ty ^= 1;
        for (int i = 1; i <= all; i++) {
          h.erase(i);
        }
        all = 0;
      } else {
        Min = INT_MAX;
        for (set<int>::iterator i = h.begin(); i != h.end(); i++) {
          int kk = *i;
          if (a[kk] > x) {
            ans[kk] = 1;
            if (!tag[kk]) {
              Min = min(Min, b[kk]);
              tag[kk] = 1;
            }
            temp[++all] = kk;
          }
        }
        if (Min == INT_MAX) {
          break;
        }
        x = Min;
        Ty ^= 1;
        for (int i = 1; i <= all; i++) {
          h.erase(i);
        }
        all = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d", ans[i]);
    }
    puts("");
  }
  return 0;
}
