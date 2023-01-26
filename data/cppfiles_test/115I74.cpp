#include <bits/stdc++.h>
using namespace std;
void io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
const int MAXN = 1e6 + 5;
const int MAXM = 1e3 + 5;
const int MAXL = 16;
const int INF = 0x3f3f3f3f;
const long long MOD = 998244353;
const int inv2 = 500000004;
int n, m;
int cnth[3];
int cntc[3];
int cnthc[3];
int numh[MAXN][2];
int numc[MAXN][2];
int numhc[2];
struct Int {
  int num;
  Int(int _num = -1) : num(_num) {}
  operator int() const { return num; }
};
map<pair<int, int>, Int> g;
long long fpow(long long base, int t) {
  long long ans = 1;
  while (t) {
    if (t & 1) {
      ans = ans * base % MOD;
    }
    base = base * base % MOD;
    t >>= 1;
  }
  return ans;
}
long long slove() {
  long long ansh = 0, ansc = 0, anshc = 0;
  if (!cnth[0]) {
    ansh = fpow(2, cnth[2]);
  }
  if (!cntc[0]) {
    ansc = fpow(2, cntc[2]);
  }
  if (!cnthc[0]) {
    anshc = fpow(2, cnthc[2]);
  }
  return (ansh + ansc - anshc + MOD) % MOD;
}
void erase(int x, int y) {
  if (g[{x, y}] == -1) {
    return;
  }
  int c = g[{x, y}];
  if (numh[x][c ^ (y & 1)] == 1) {
    if (numh[x][c ^ (y & 1) ^ 1]) {
      cnth[0]--;
      cnth[1]++;
    } else {
      cnth[1]--;
      cnth[2]++;
    }
  }
  numh[x][c ^ (y & 1)]--;
  if (numc[y][c ^ (x & 1)] == 1) {
    if (numc[y][c ^ (x & 1) ^ 1]) {
      cntc[0]--;
      cntc[1]++;
    } else {
      cntc[1]--;
      cntc[2]++;
    }
  }
  numc[y][c ^ (x & 1)]--;
  if (numhc[c ^ (x & 1) ^ (y & 1)] == 1) {
    if (numhc[c ^ (x & 1) ^ (y & 1) ^ 1]) {
      cnthc[0]--;
      cnthc[1]++;
    } else {
      cnthc[1]--;
      cnthc[2]++;
    }
  }
  numhc[c ^ (x & 1) ^ (y & 1)]--;
}
void insert(int x, int y, int c) {
  int hv = c ^ (y & 1);
  if (!numh[x][hv]) {
    if (numh[x][hv ^ 1]) {
      cnth[1]--;
      cnth[0]++;
    } else {
      cnth[2]--;
      cnth[1]++;
    }
  }
  numh[x][hv]++;
  int cv = c ^ (x & 1);
  if (!numc[y][cv]) {
    if (numc[y][cv ^ 1]) {
      cntc[1]--;
      cntc[0]++;
    } else {
      cntc[2]--;
      cntc[1]++;
    }
  }
  numc[y][cv]++;
  int hcv = c ^ (x & 1) ^ (y & 1);
  if (!numhc[hcv]) {
    if (numhc[hcv ^ 1]) {
      cnthc[1]--;
      cnthc[0]++;
    } else {
      cnthc[2]--;
      cnthc[1]++;
    }
  }
  numhc[hcv]++;
  g[{x, y}] = Int(c);
}
int main() {
  io();
  cin >> n >> m;
  cnth[2] = n;
  cntc[2] = m;
  cnthc[2] = 1;
  int k;
  cin >> k;
  while (k--) {
    int x, y, t;
    cin >> x >> y >> t;
    erase(x, y);
    if (t == 0 || t == 1) {
      insert(x, y, t);
    }
    cout << slove() << '\n';
  }
}
