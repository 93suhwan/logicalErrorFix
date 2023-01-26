#include <bits/stdc++.h>
const long long OO{(long long)(1e18)};
using namespace std;
void minz(int &A, int B) {
  if (A > B) A = B;
  return;
}
void maxz(int &A, int B) {
  if (A < B) A = B;
  return;
}
const int maxn{(int)(2e5 + 2911)};
const long long MOD{(long long)(1e9 + 7)};
vector<int> vi[maxn];
int n;
int deg[maxn], ndeg[maxn];
vector<int> tmpv, topo;
priority_queue<int, vector<int>, greater<int> > Q;
void codeforces() {
  cin >> n;
  for (int i = (int)(1); i <= (int)(n); ++i) {
    vi[i].clear();
  }
  tmpv.clear();
  for (int i = (int)(1); i <= (int)(n); ++i) {
    int x;
    cin >> deg[i];
    for (int j = (int)(1); j <= (int)(deg[i]); ++j) {
      cin >> x;
      vi[x].push_back(i);
    }
    if (deg[i] == 0) {
      Q.push(i);
      tmpv.push_back(i);
    }
    ndeg[i] = deg[i];
  }
  topo.clear();
  while (!tmpv.empty()) {
    int u;
    u = tmpv.back();
    tmpv.pop_back();
    topo.push_back(u);
    for (int v : vi[u]) {
      --ndeg[v];
      if (ndeg[v] == 0) tmpv.push_back(v);
    }
  }
  if (Q.empty() || (int)(topo.size()) != n) {
    cout << "-1" << '\n';
    return;
  }
  int ans = 0;
  while (!Q.empty()) {
    tmpv.clear();
    ++ans;
    while (!Q.empty()) {
      int u;
      u = Q.top();
      Q.pop();
      for (int v : vi[u]) {
        --deg[v];
        if (deg[v] == 0) {
          if (v > u)
            Q.push(v);
          else
            tmpv.push_back(v);
        }
      }
    }
    for (int v : tmpv) Q.push(v);
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T_T = 1;
  cin >> T_T;
  while (T_T--) {
    codeforces();
  }
  return 0;
}
