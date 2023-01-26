#include <bits/stdc++.h>
using namespace std;
set<long long> st;
long long lst[3010000];
long long shit[3010000];
long long vis[3010000];
long long a[3010000];
long long b[3010000];
long long n;
long long BFS(long long now) {
  queue<long long> q;
  q.push(now);
  q.push(0);
  while (!q.empty()) {
    long long t = q.front();
    q.pop();
    long long num = q.front();
    q.pop();
    if (t - a[t] <= 0) {
      lst[0] = t;
      return num + 1;
    }
    vector<long long> vt;
    vt.clear();
    for (set<long long>::iterator it = st.lower_bound(t - a[t]); it != st.end();
         it++) {
      long long ed = *it;
      vt.push_back(ed);
      long long fk = ed + b[ed];
      if (vis[fk] == 0) {
        shit[fk] = ed;
        q.push(fk);
        q.push(num + 1);
        lst[fk] = t;
        vis[fk] = 1;
      }
    }
    for (long long i = 0; i < vt.size(); i++) {
      st.erase(vt[i]);
    }
  }
  return -1;
}
void dfs(long long now) {
  if (now == n) return;
  dfs(lst[now]);
  if (now == 0) {
    printf("0");
  } else
    printf("%lld ", shit[now]);
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    st.insert(i);
  }
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
  }
  long long ans = BFS(n);
  if (ans == -1) {
    printf("%lld", ans);
  } else {
    printf("%lld\n", ans);
    dfs(0);
  }
  return 0;
}
