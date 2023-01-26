#include <bits/stdc++.h>
using namespace std;
int T, N, M;
vector<int> p[500010];
vector<int> lmax[500010], lmin[500010], rmax[500010], rmin[500010];
struct seg {
  int x, y, id;
};
seg t[500010];
bool cmp1(seg a, seg b) {
  if (a.y != b.y) return a.y > b.y;
  if (a.x != b.x) return a.x > b.x;
  return a.id > b.id;
}
bool cmp2(seg a, seg b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.id < b.id;
}
long long hash1[500010] = {0};
long long hash2[500010] = {0};
long long MOD = 998244353;
long long has;
bool vis[500010] = {0};
void prepare() {
  cin >> N >> M;
  int tmp;
  for (int i = 0; i < N; i++) {
    p[i].clear();
    lmax[i].clear();
    lmin[i].clear();
    rmax[i].clear();
    rmin[i].clear();
    for (int j = 0; j < M; j++) {
      scanf("%d", &tmp);
      p[i].push_back(tmp);
    }
  }
  int Min, Max = 0;
  for (int i = 0; i < N; i++) {
    Min = 100000000;
    Max = -1;
    for (int j = 0; j < M; j++) {
      Min = min(Min, p[i][j]);
      Max = max(Max, p[i][j]);
      lmax[i].push_back(Max);
      lmin[i].push_back(Min);
    }
  }
  for (int i = 0; i < N; i++) {
    Min = 100000000;
    Max = -1;
    for (int j = M - 1; j >= 0; j--) {
      Min = min(Min, p[i][j]);
      Max = max(Max, p[i][j]);
      rmax[i].push_back(Max);
      rmin[i].push_back(Min);
    }
  }
  int cnt1, cnt2, pos1, pos2, l, r;
  for (int k = 0; k < M - 1; k++) {
    for (int i = 0; i < N; i++) {
      t[i].id = i;
      t[i].x = lmin[i][k];
      t[i].y = lmax[i][k];
    }
    sort(t, t + N, cmp1);
    pos1 = 0;
    has = 1;
    while (pos1 < N) {
      l = t[pos1].x;
      hash1[pos1] = -1;
      has = (has * t[pos1].id) % MOD;
      while (pos1 + 1 < N && t[pos1 + 1].y >= l) {
        pos1++;
        has = (has * t[pos1].id) % MOD;
        hash1[pos1] = -1;
        l = min(l, t[pos1].x);
      }
      hash1[pos1] = has;
      pos1++;
    }
    for (int i = 0; i < N; i++) {
      t[i].id = i;
      t[i].x = rmin[i][M - 2 - k];
      t[i].y = rmax[i][M - 2 - k];
    }
    sort(t, t + N, cmp2);
    pos2 = 0;
    has = 1;
    while (pos2 < N) {
      r = t[pos2].y;
      hash2[pos2] = -1;
      has = (has * t[pos2].id) % MOD;
      while (pos2 + 1 < N && t[pos2 + 1].x <= r) {
        pos2++;
        has = (has * t[pos2].id) % MOD;
        hash2[pos2] = -1;
        r = max(r, t[pos2].y);
      }
      hash2[pos2] = has;
      pos2++;
    }
    for (int i = 0; i < N - 1; i++) {
      if (hash1[i] == hash2[i] && hash1[i] != -1) {
        cout << "YES" << endl;
        for (int j = 0; j < N; j++) vis[j] = 0;
        for (int j = 0; j <= i; j++) {
          vis[t[j].id] = 1;
        }
        for (int j = 0; j < N; j++) {
          if (vis[j] == 0)
            printf("B");
          else
            printf("R");
        }
        cout << " " << k + 1;
        cout << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
void solve() {}
int main() {
  cin >> T;
  while (T--) {
    prepare();
    solve();
  }
  return 0;
}
