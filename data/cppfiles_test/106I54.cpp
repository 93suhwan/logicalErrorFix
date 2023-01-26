#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int NMAX = 20;
const int TWO_TO_NMAX = (1 << NMAX);
int n, K, two_to_n;
int a[TWO_TO_NMAX];
int g[TWO_TO_NMAX][NMAX];
bool cmp(int i, int j) {
  if (a[i] < a[j]) return true;
  return false;
}
int max_edge;
int matchX[TWO_TO_NMAX];
int matchY[TWO_TO_NMAX];
bool vst[TWO_TO_NMAX];
bool isInLeftSide[TWO_TO_NMAX];
queue<int> q;
void build_left_right_set() {
  q.push(0);
  isInLeftSide[0] = true;
  vst[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      int v = g[u][i];
      if (vst[v]) continue;
      vst[v] = true;
      if (!isInLeftSide[u]) isInLeftSide[v] = true;
      q.push(v);
    }
  }
}
int d[TWO_TO_NMAX];
int sign[TWO_TO_NMAX], signCnt;
int trace[TWO_TO_NMAX];
bool isUsedY[TWO_TO_NMAX];
vector<int> blackList;
bool inBlackList[TWO_TO_NMAX];
int vvBlack[TWO_TO_NMAX];
int blackG[TWO_TO_NMAX][NMAX + 1];
bool isInQueue[TWO_TO_NMAX];
multiset<pair<int, int> > nonBlack;
int cost(int u, int v) { return max_edge + 1 - a[u] - a[v]; }
int min_augmenting_path() {
  signCnt++;
  for (int i = 0; i < (int)blackList.size(); i++) {
    int u = blackList[i];
    if (matchX[u] == -1) {
      d[u] = 0;
      sign[u] = signCnt;
      q.push(u);
      isInQueue[u] = true;
    }
  }
  int res = INF;
  int lastY = -1;
  if (!nonBlack.empty()) {
    multiset<pair<int, int> >::iterator it = nonBlack.end();
    --it;
    res = cost((*it).second, g[(*it).second][n - 1]);
    lastY = g[(*it).second][n - 1];
    trace[lastY] = (*it).second;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    isInQueue[u] = false;
    if (isInLeftSide[u]) {
      for (int i = 0; i < blackG[u][n]; i++) {
        int v = blackG[u][i];
        if (v == matchX[u]) continue;
        if (sign[v] != signCnt || d[v] > d[u] + cost(u, v)) {
          sign[v] = signCnt;
          d[v] = d[u] + cost(u, v);
          trace[v] = u;
          if (!isInQueue[v]) {
            q.push(v);
            isInQueue[v] = true;
          }
        }
      }
      if (vvBlack[u] != -1) {
        int v = vvBlack[u];
        if (sign[v] != signCnt || d[v] > d[u] + cost(u, v)) {
          sign[v] = signCnt;
          d[v] = d[u] + cost(u, v);
          trace[v] = u;
          if (!isInQueue[v]) {
            q.push(v);
            isInQueue[v] = true;
          }
        }
      }
    } else {
      if (matchY[u] == -1) {
        if (d[u] < res) {
          res = d[u];
          lastY = u;
        }
      } else {
        int v = matchY[u];
        if (sign[v] != signCnt || d[v] > d[u] - cost(u, v)) {
          sign[v] = signCnt;
          d[v] = d[u] - cost(u, v);
          trace[v] = u;
          if (!isInQueue[v]) {
            q.push(v);
            isInQueue[v] = true;
          }
        }
      }
    }
  }
  if (lastY != -1) {
    isUsedY[lastY] = true;
    for (int i = 0; i < n; i++) {
      int x = (lastY ^ (1 << i));
      inBlackList[x] = true;
      if (blackG[x][n] == 0) {
        blackList.push_back(x);
        multiset<pair<int, int> >::iterator it =
            nonBlack.find(pair<int, int>(a[x] + a[g[x][n - 1]], x));
        nonBlack.erase(it);
      }
      blackG[x][blackG[x][n]++] = lastY;
      if (isUsedY[vvBlack[x]]) {
        vvBlack[x] = -1;
        for (int j = n - 1; j >= 0; j--) {
          if (!isUsedY[g[x][j]]) {
            vvBlack[x] = g[x][j];
            break;
          }
        }
      }
    }
    while (lastY != -1) {
      int y = lastY, x = trace[y], z = trace[x];
      matchX[x] = y;
      matchY[y] = x;
      lastY = z;
    }
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &K);
  two_to_n = (1 << n);
  for (int i = 0; i < two_to_n; i++) {
    scanf("%d", &a[i]);
    matchX[i] = -1;
    matchY[i] = -1;
    trace[i] = -1;
  }
  for (int mask = 0; mask < two_to_n; mask++) {
    for (int i = 0; i < n; i++) {
      g[mask][i] = (mask ^ (1 << i));
    }
  }
  build_left_right_set();
  for (int mask = 0; mask < two_to_n; mask++) {
    if (isInLeftSide[mask]) {
      sort(g[mask], g[mask] + n, cmp);
      vvBlack[mask] = g[mask][n - 1];
      nonBlack.insert(pair<int, int>(a[mask] + a[g[mask][n - 1]], mask));
    }
  }
  for (int mask = 0; mask < two_to_n; mask++)
    max_edge = max(max_edge, a[mask] + a[g[mask][n - 1]]);
  int res = 0;
  for (int timer = 1; timer <= K; timer++) {
    int p = min_augmenting_path();
    if (p == INF) {
      res -= (max_edge + 1) * (timer - 1);
      break;
    } else {
      res += p;
      if (timer == K) res -= (max_edge + 1) * K;
    }
  }
  printf("%d\n", -res);
  return 0;
}
