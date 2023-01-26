#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
long long n, a[N];
char s[N];
bool is[N];
vector<pair<long long, long long> > f[N];
vector<pair<long long, long long> > id[N];
long long mn[N], ans;
pair<long long, long long> sta[N];
long long top;
vector<long long> in[N], out[N];
void work(long long x) {
  for (auto &y : id[x])
    if (s[y.first] == '/') y.second *= -1;
  for (long long i = 1; i < ((long long)id[x].size()); i++)
    id[x][i].second += id[x][i - 1].second;
  top = 0;
  for (long long i = ((long long)id[x].size()) - 1; i >= 0; i--) {
    long long now = (i == 0 ? 0 : id[x][i - 1].second);
    while (top && sta[top].second >= id[x][i].second) top--;
    sta[++top] = id[x][i];
    long long l = 1, r = top;
    while (l != r) {
      long long mid = (l + r) / 2 + 1;
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
priority_queue<long long> pq;
long long tot[N];
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  for (long long i = 2; i < N; i++) {
    if (is[i]) continue;
    for (long long j = i; j < N; j += i) {
      long long u = j, cnt = 0;
      while (u % i == 0) {
        cnt++;
        u /= i;
      }
      f[j].emplace_back(i, cnt);
    }
  }
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    for (auto x : f[a[i]]) id[x.first].emplace_back(i, x.second);
    mn[i] = n;
  }
  cin >> s + 1;
  for (long long i = 0; i < N; i++) work(i);
  pq.push(-n);
  tot[n] = 1;
  for (long long i = n; i >= 1; i--) {
    for (auto x : in[i]) {
      if (!tot[x]++) pq.push(-x);
    }
    for (auto x : out[i]) tot[x]--;
    while (!pq.empty()) {
      long long u = -pq.top();
      if (tot[u] == 0)
        pq.pop();
      else {
        ans += u - i + 1;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
