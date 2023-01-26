#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
const int N = 1e6 + 10;
int n, a[N];
char s[N];
bool is[N];
vector<pair<int, int> > f[N];
vector<pair<int, int> > id[N];
long long ans;
pair<int, int> sta[N];
int top;
vector<int> in[N], out[N];
void work(int x) {
  if (((int)id[x].size()) == 0) return;
  for (auto &y : id[x])
    if (s[y.first] == '/') y.second *= -1;
  for (int i = 1; i < ((int)id[x].size()); i++)
    id[x][i].second += id[x][i - 1].second;
  top = 0;
  for (int i = ((int)id[x].size()) - 1; i >= 0; i--) {
    int now = (i == 0 ? 0 : id[x][i - 1].second);
    while (top && sta[top].second >= id[x][i].second) top--;
    sta[++top] = id[x][i];
    int l = 1, r = top;
    while (l != r) {
      int mid = (l + r) / 2 + 1;
      if (sta[mid].second < now)
        l = mid;
      else
        r = mid - 1;
    }
    if (sta[l].second < now) {
      in[id[x][i].first].push_back(sta[l].first - 1);
      if (i) out[id[x][i - 1].first].push_back(sta[l].first - 1);
    }
  }
}
priority_queue<int> pq;
int tot[N];
bool vis[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  for (int i = 2; i < N; i++) {
    if (is[i]) continue;
    for (int j = i; j < N; j += i) {
      int u = j, cnt = 0;
      is[j] = 1;
      while (u % i == 0) {
        cnt++;
        u /= i;
      }
      f[j].emplace_back(i, cnt);
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (auto x : f[a[i]]) id[x.first].emplace_back(i, x.second);
  }
  cin >> s + 1;
  for (int i = 0; i < N; i++) work(i);
  pq.push(-n);
  tot[n] = 1;
  vis[n] = 1;
  for (int i = n; i >= 1; i--) {
    for (auto x : in[i]) {
      if (!vis[x]) {
        pq.push(-x);
        vis[x] = 1;
      }
      tot[x]++;
    }
    for (auto x : out[i]) tot[x]--;
    while (!pq.empty()) {
      int u = -pq.top();
      if (tot[u] == 0) {
        pq.pop();
        vis[u] = 0;
      } else {
        ans += u - i + 1;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
