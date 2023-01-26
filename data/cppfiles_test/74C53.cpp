#include <bits/stdc++.h>
#pragma optimize(Ofast)
using namespace std;
int Max = 1e9;
int vis[30000007];
vector<int> stk;
vector<vector<int> > ans;
int res;
bool search(int i, int n, int *b, int need, int sum) {
  if (need == 0) {
    if (vis[sum]) {
      res = sum;
      return true;
    } else
      vis[sum] = 1;
    return false;
  }
  if (i == n + 1) return false;
  for (int j = i; j <= n; j++) {
    if (search(j + 1, n, b, need - 1, sum + b[j])) return true;
  }
  return false;
}
bool go(int i, int n, int *b, int need, int sum, int res) {
  if (need == 0) {
    if (sum == res) {
      ans.push_back(stk);
    }
    if (ans.size() == 2) return true;
    return false;
  }
  if (i == n + 1) return false;
  for (int j = i; j <= n; j++) {
    stk.push_back(j);
    if (go(j + 1, n, b, need - 1, sum + b[j], res)) return true;
    stk.pop_back();
  }
  return false;
}
void solve() {
  int n;
  scanf("%d", &n);
  int b[1005];
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  sort(b, b + n);
  if (n == 2) {
    if (b[0] != b[1]) {
      printf("NO\n");
      return;
    } else {
      printf("YES\n%d %d\n", 0, b[0]);
    }
  } else if (n == 3) {
    int tot = b[0] + b[1] + b[2];
    if (tot % 2 == 1) {
      if (b[0] == b[1]) {
        printf("YES\n0 %d %d\n", b[1], b[2]);
      } else if (b[1] == b[2]) {
        printf("YES\n0 %d %d\n", b[0], b[1]);
      } else
        printf("NO\n");
    } else {
      tot /= 2;
      printf("YES\n%d %d %d\n", tot - b[0], tot - b[1], tot - b[2]);
    }
  } else {
    for (int i = 0; i + 1 < n; i++) {
      if (b[i] == b[i + 1]) {
        printf("YES\n");
        printf("0");
        for (int j = 0; j < n; j++) {
          if (j == i) continue;
          printf(" %d", b[j]);
        }
        printf("\n");
        return;
      }
    }
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
      if (b[i] % 2 == 0) {
        even.push_back(b[i]);
      } else {
        odd.push_back(b[i]);
      }
    }
    if (even.size() >= 3) {
      int tot = even[0] + even[1] + even[2];
      tot /= 2;
      int a[3] = {tot - even[0], tot - even[1], tot - even[2]};
      printf("YES\n");
      printf("%d %d %d", a[0], a[1], a[2]);
      for (auto it : odd) printf(" %d", it - a[0]);
      for (int i = 3; i < even.size(); i++) {
        printf(" %d", even[i] - a[0]);
      }
      printf("\n");
      return;
    } else if (odd.size() >= 2 && even.size() >= 1) {
      int tot = odd[0] + odd[1] + even[0];
      tot /= 2;
      int a[3] = {tot - odd[0], tot - odd[1], tot - even[0]};
      printf("YES\n");
      printf("%d %d %d", a[0], a[1], a[2]);
      for (int i = 2; i < odd.size(); i++) {
        printf(" %d", odd[i] - a[0]);
      }
      for (int i = 1; i < even.size(); i++) {
        printf(" %d", even[i] - a[0]);
      }
      printf("\n");
      return;
    } else {
      for (int i = 2; i <= n; i++) {
        fill(vis, vis + i * 1000000 + 1, 0);
        if (search(0, n, b, i, 0)) {
          go(0, n, b, i, 0, res);
          vector<int> q;
          for (int j = 0; j < i; j++)
            q.push_back(ans[0][j]), q.push_back(ans[1][j]);
          int a[1005];
          a[0] = 0;
          int vis[1005];
          memset(vis, 0, sizeof(vis));
          for (int i = 0; i + 1 < q.size(); i++) {
            a[i + 1] = b[q[i]] - a[i];
            vis[q[i]] = 1;
          }
          vis[q.back()] = 1;
          assert(a[0] + a[i * 2 - 1] == b[q.back()]);
          printf("YES\n");
          for (int i = 0; i < q.size(); i++) printf("%d ", a[i]);
          for (int i = 0; i < n; i++) {
            if (!vis[i]) printf("%d ", b[i]);
          }
          printf("\n");
          return;
        }
      }
      printf("NO\n");
    }
  }
}
int main() {
  int t = 1;
  0000;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
