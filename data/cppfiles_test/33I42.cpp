#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
int n, a[1000010], smallest[2 * MAXN];
bool vis[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < 2 * MAXN; i++) {
    smallest[i] = -1;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (vis[a[i]]) continue;
    vis[a[i]] = 1;
    for (int j = 0; j < 2 * MAXN; j++) {
      if (smallest[j] != -1 && smallest[j] < a[i]) {
        int val = j ^ a[i];
        if (smallest[val] == -1)
          smallest[val] = a[i];
        else
          smallest[val] = min(smallest[val], a[i]);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < 2 * MAXN; i++) {
    if (smallest[i] != -1) cnt++;
  }
  cout << cnt << endl;
  for (int i = 0; i < 2 * MAXN; i++)
    if (smallest[i] != -1) cout << i << " ";
}
