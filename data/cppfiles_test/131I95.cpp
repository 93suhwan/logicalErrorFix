#include <bits/stdc++.h>
using namespace std;
const int N = 7e6;
int n, m, q;
int a[N], fa[N];
map<int, int> M;
vector<int> ve[N];
int mx[N], mx2[N], jl1[N], jl2[N], jl11, jl22;
int ans = 0;
void dfs(int x) {
  for (auto v : ve[x]) {
    dfs(v);
    if (mx[v] > mx[x]) {
      jl2[x] = jl1[x];
      jl1[x] = jl1[v];
      mx2[x] = mx[x];
      mx[x] = mx[v];
    } else if (mx[v] > mx2[x]) {
      mx2[x] = mx[v];
      jl2[x] = jl1[v];
    }
  }
  if (mx[x] && mx2[x]) {
    if (mx[x] + mx2[x] > ans) {
      jl11 = jl1[x];
      jl22 = jl2[x];
      ans = mx[x] + mx2[x];
    }
  }
  if (!mx[x]) jl1[x] = x;
  mx[x]++;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    M[a[i]] = ++cnt;
  }
  for (int i = 1; i <= cnt; i++) {
    if (a[i] == 0) continue;
    int now = 1;
    for (int j = 0; j <= 30; j++) {
      if (now >= a[i]) {
        if (!M[now - a[i]]) {
          M[now - a[i]] = ++cnt;
          a[cnt] = now - a[i];
        }
        fa[M[a[i]]] = M[now - a[i]];
        ve[M[now - a[i]]].push_back(M[a[i]]);
        break;
      }
      now *= 2;
    }
  }
  for (int i = 1; i <= cnt; i++)
    if (!fa[i]) dfs(i);
  cout << jl11 << " " << jl22 << " " << ans << endl;
  return 0;
}
