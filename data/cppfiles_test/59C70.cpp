#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 1000;
int n, m;
int monster[MAXN];
int gain[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];
int prv[MAXN];
long long visitpower[MAXN];
bool can(int startpower) {
  for (int i = (0); i < (n); ++i) visited[i] = false;
  visited[0] = true;
  long long curpower = startpower;
  while (true) {
    for (int i = (0); i < (n); ++i) prv[i] = -2;
    bool change = false;
    queue<int> q;
    for (int i = (0); i < (n); ++i)
      if (visited[i]) prv[i] = -1, visitpower[i] = curpower, q.push(i);
    while (!q.empty() && !change) {
      int at = q.front();
      q.pop();
      for (int to : adj[at]) {
        if (visited[at] && visited[to]) continue;
        if (!visited[to] && visitpower[at] <= monster[to]) continue;
        if (to == prv[at]) continue;
        if (prv[to] == -2) {
          assert(!visited[to]);
          prv[to] = at, visitpower[to] = visitpower[at] + gain[to], q.push(to);
        } else {
          vector<int> path;
          for (int x = at; x != -1; x = prv[x]) path.push_back(x);
          reverse(path.begin(), path.end());
          for (int x = to; x != -1; x = prv[x]) path.push_back(x);
          if (visitpower[at] < visitpower[to])
            reverse(path.begin(), path.end());
          assert(((int)(path).size()) >= 3 && visited[path[0]] &&
                 visited[path[((int)(path).size()) - 1]]);
          bool any = false;
          for (int i = (1); i < (((int)(path).size()) - 1); ++i) {
            assert(curpower > monster[path[i]]);
            if (!visited[path[i]]) {
              curpower += gain[path[i]];
              visited[path[i]] = true;
              any = true;
            }
          }
          assert(any);
          change = true;
          break;
        }
      }
    }
    if (!change) break;
  }
  for (int i = (0); i < (n); ++i)
    if (!visited[i]) return false;
  return true;
}
int solve() {
  int mxmonster = 0;
  for (int i = (1); i < (n); ++i) mxmonster = max(mxmonster, monster[i]);
  int lo = 0, hi = mxmonster + 1;
  while (lo + 1 < hi) {
    int mi = lo + (hi - lo) / 2;
    if (can(mi))
      hi = mi;
    else
      lo = mi;
  }
  return hi;
}
void run() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i < (n); ++i) scanf("%d", &monster[i]);
  for (int i = (1); i < (n); ++i) scanf("%d", &gain[i]);
  for (int i = (0); i < (m); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  printf("%d\n", solve());
  for (int i = (0); i < (n); ++i) adj[i].clear();
}
int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int i = (1); i <= (ncase); ++i) run();
  return 0;
}
