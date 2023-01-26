#include <bits/stdc++.h>
using namespace std;
const int NUM_GROUPS = 32;
int a[200005];
vector<pair<int, int> > group[NUM_GROUPS];
int best[NUM_GROUPS];
int bestIndx[NUM_GROUPS];
int findGroup(int x) {
  if (x == 0) {
    return 0;
  }
  return __builtin_ctz(x) + 1;
}
int maxLength(int x) {
  if (x == 0) {
    return 0;
  }
  return __builtin_ctz(x + (x & 1));
}
int floor_log2(int x) {
  if (x == 0) {
    return 0;
  }
  return 31 - __builtin_clz(x);
}
int calc(int x) {
  if (x == 0) {
    return 0;
  }
  x >>= __builtin_ctz(x);
  x >>= 1;
  int ans = 1;
  while (x) {
    int y = ((2 << floor_log2(x)) - 1);
    x = (~x) & ((2 << floor_log2(x)) - 1);
    ans++;
  }
  return ans;
}
int calcDist(int x, int y) {
  if (x == y) {
    return 0;
  }
  if (x == 0 || y == 0) {
    return calc(max(x, y));
  }
  int k = __builtin_ctz(x);
  if (k != __builtin_ctz(y)) {
    return calc(x) + calc(y);
  }
  x >>= k;
  x >>= 1;
  y >>= k;
  y >>= 1;
  int ans = 0;
  while (1) {
    int p = maxLength(x);
    int q = maxLength(y);
    if (p != q) {
      break;
    }
    x >>= p;
    y >>= p;
  }
  return calc((x << 1) | 1) + calc((y << 1) | 1) - 2;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    group[findGroup(a[i])].emplace_back(a[i], i);
  }
  for (int i = 0; i < NUM_GROUPS; i++) {
    best[i] = -1;
    for (pair<int, int> j : group[i]) {
      int res = calc(j.first);
      if (res > best[i]) {
        best[i] = res;
        bestIndx[i] = j.second;
      }
    }
  }
  int best2 = -1;
  int bestIndx2 = -1;
  int secondBest2 = -1;
  int secondBestIndx2 = -1;
  for (int i = 0; i < NUM_GROUPS; i++) {
    if (best[i] > best2) {
      secondBest2 = best2;
      secondBestIndx2 = bestIndx2;
      best2 = best[i];
      bestIndx2 = bestIndx[i];
    } else if (best[i] > secondBest2) {
      secondBest2 = best[i];
      secondBestIndx2 = bestIndx[i];
    }
  }
  tuple<int, int, int> best3 = tuple<int, int, int>(-1, -1, -1);
  if (bestIndx2 != -1 && secondBestIndx2 != -1) {
    best3 =
        tuple<int, int, int>(best2 + secondBest2, bestIndx2, secondBestIndx2);
  }
  for (int i = 0; i < NUM_GROUPS; i++) {
    for (pair<int, int> j : group[i]) {
      if (j.second == bestIndx[i]) {
        continue;
      }
      best3 = max(best3, tuple<int, int, int>(calcDist(j.first, a[bestIndx[i]]),
                                              j.second, bestIndx[i]));
    }
  }
  printf("%d %d %d\n", get<1>(best3), get<2>(best3), get<0>(best3));
  return 0;
}
