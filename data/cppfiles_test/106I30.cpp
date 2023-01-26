#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, K;
int a[(1 << 20) + 5];
vector<int> g[(1 << 20) + 5];
bool cmp(int i, int j) {
  if (a[i] < a[j]) return true;
  return false;
}
int max_edge;
int matchX[(1 << 20) + 5];
int matchY[(1 << 20) + 5];
set<int> usedY;
bool vst[(1 << 20) + 5];
vector<int> vX, vY;
bool isInLeftSide[(1 << 20) + 5];
queue<int> q;
void build_left_right_set() {
  q.push(0);
  isInLeftSide[0] = true;
  vst[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i];
      if (vst[v]) continue;
      vst[v] = true;
      if (!isInLeftSide[u]) isInLeftSide[v] = true;
      q.push(v);
    }
  }
}
int d[(1 << 20) + 5];
int trace[(1 << 20) + 5];
int isUsedY[(1 << 20) + 5], isUsedYCnt;
int blackList[(1 << 20) + 5], blackListCnt;
int cost(int u, int v) { return max_edge + 1 - a[u] - a[v]; }
void build_blackList(vector<int> usedYVec) {
  blackListCnt++;
  for (int i = 0; i < (int)usedYVec.size(); i++) {
    int u = usedYVec[i];
    for (int j = 0; j < (int)g[u].size(); j++) {
      int v = g[u][j];
      blackList[v] = blackListCnt;
    }
  }
}
int min_augmenting_path() {
  vector<int> usedYVec;
  isUsedYCnt++;
  for (set<int>::iterator it = usedY.begin(); it != usedY.end(); it++) {
    int u = (*it);
    isUsedY[u] = isUsedYCnt;
    usedYVec.push_back(u);
  }
  build_blackList(usedYVec);
  for (int i = 0; i < (1 << n); i++) {
    if (!isInLeftSide[i])
      d[i] = INF;
    else {
      if (matchX[i] != -1)
        d[i] = INF;
      else {
        d[i] = 0;
        q.push(i);
      }
    }
    trace[i] = -1;
  }
  int res = INF;
  int lastY = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (isInLeftSide[u]) {
      int vv = -1;
      if (blackList[u] == blackListCnt) {
        for (int i = (int)g[u].size() - 1; i >= 0; i--) {
          int v = g[u][i];
          if (isUsedY[v] != isUsedYCnt) {
            if (vv == -1) vv = v;
            continue;
          }
          if (d[v] > d[u] + cost(u, v)) {
            d[v] = d[u] + cost(u, v);
            trace[v] = u;
            q.push(v);
          }
        }
      }
      if (vv != -1) {
        if (d[vv] > d[u] + cost(u, vv)) {
          d[vv] = d[u] + cost(u, vv);
          trace[vv] = u;
          q.push(vv);
        }
      } else if (blackList[u] != blackListCnt) {
        int v = g[u][(int)g[u].size() - 1];
        if (d[v] > d[u] + cost(u, v)) {
          d[v] = d[u] + cost(u, v);
          trace[v] = u;
          q.push(v);
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
        if (d[v] > d[u] - cost(u, v)) {
          d[v] = d[u] - cost(u, v);
          trace[v] = u;
          q.push(v);
        }
      }
    }
  }
  set<int> tempUsedY;
  while (lastY != -1) {
    int y = lastY, x = trace[y], z = trace[x];
    matchX[x] = y;
    matchY[y] = x;
    tempUsedY.insert(y);
    lastY = z;
  }
  usedY = tempUsedY;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> K;
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[i];
    matchX[i] = -1;
    matchY[i] = -1;
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      g[mask].push_back(mask ^ (1 << i));
      max_edge = max(max_edge, a[mask] + a[mask ^ (1 << i)]);
    }
  }
  build_left_right_set();
  for (int mask = 0; mask < (1 << n); mask++) {
    if (isInLeftSide[mask]) {
      sort(g[mask].begin(), g[mask].end(), cmp);
    }
  }
  int res = 0;
  for (int timer = 1; timer <= K; timer++) {
    cout << "timer = " << timer << endl;
    int p = min_augmenting_path();
    if (p == INF) {
      res -= (max_edge + 1) * (int)(timer - 1);
      break;
    } else {
      res += p;
      if (timer == K) res -= (max_edge + 1) * (int)K;
    }
  }
  cout << -res << endl;
  return 0;
}
