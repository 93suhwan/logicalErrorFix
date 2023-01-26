#include <bits/stdc++.h>
using namespace std;
const int N = 150000;
const int mod = 1000000000 + 7;
bool vis[N + 5];
int prime[N + 5], phi[N + 5], a[N + 5], n, ans = 0, cnt[100005], bj[100005];
vector<int> Div[N + 5];
inline int add(const int &x, const int &y) { return (x + y) % mod; }
inline int mul(const int &x, const int &y) { return (1ll * x * y) % mod; }
void Euler() {
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      prime[++prime[0]] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= prime[0] && prime[j] * i <= N; j++) {
      vis[prime[j] * i] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else
        phi[i * prime[j]] = phi[i] * phi[prime[j]];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &a[i]);
    x = a[i];
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        Div[i].push_back(j);
        if (j != x / j) Div[i].push_back(x / j);
      }
    }
  }
  Euler();
  phi[1] = 1;
  for (int x = 1; x <= n; x++) {
    vector<int> box;
    for (int i = 1; i * x <= n; i++)
      for (auto d : Div[i * x]) {
        if (bj[d] != x) {
          bj[d] = x;
          cnt[d] = 1;
          box.push_back(d);
        } else
          cnt[d]++;
      }
    for (auto y : box)
      ans = add(ans, mul(phi[x], mul(phi[y], mul(cnt[y], cnt[y]))));
  }
  printf("%d\n", ans);
  return 0;
}
