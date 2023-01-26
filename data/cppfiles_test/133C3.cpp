#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[200500];
long long vis[200500];
long long arr[200500];
long long sum;
void DFS(long long x) {
  vis[x] = 1;
  sum = sum + arr[x];
  for (long long next : adj[x]) {
    if (!vis[next]) DFS(next);
  }
}
void solve() {
  long long x;
  cin >> x;
  char ss[1000], c;
  char ss2[1000];
  long long cnt = 0, cnt1 = 0;
  bool flaga = 1;
  getchar();
  while (1) {
    scanf("%c", &c);
    if (c == '\n')
      break;
    else if (c == ' ')
      continue;
    else
      ss[++cnt] = c;
  }
  for (long long i = 1; i <= cnt; i++) {
    if (i % 2 == 0) {
      if (ss[i] == ss[i + 1]) {
        ss2[cnt1++] = ss[i++];
      } else
        ss2[cnt1++] = ss[i];
    } else
      ss2[cnt1++] = ss[i];
  }
  for (long long i = 0; i < cnt1; i++)
    if (ss2[i] != 'a') flaga = 0;
  while (cnt1 < x)
    if (!flaga)
      ss2[cnt1++] = 'a';
    else
      ss2[cnt1++] = 'b';
  for (long long i = 0; i < cnt1; i++) cout << ss2[i];
  cout << '\n';
}
int main() {
  long long n;
  cin >> n;
  while (n--) solve();
}
