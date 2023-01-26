#include <bits/stdc++.h>
using namespace std;
long long n, m;
typedef struct node {
  long long val, idx;
} node;
node a[(int)3e2 + 10];
map<long long, long long> mp;
bool visited[(int)3e2 + 10];
bool cmp(node a, node b) {
  if (a.val == b.val) {
    return a.idx > b.idx;
  }
  return a.val < b.val;
}
int main() {
  int t;
  cin.tie(0);
  cin >> t;
  while (t--) {
    mp.clear();
    cin >> n >> m;
    for (long long i = 1; i <= m; i++) {
      cin >> a[i].val;
      a[i].idx = i;
      mp[a[i].val]++;
    }
    long long ans = 0;
    memset(visited, 0, sizeof(visited));
    for (long long i = 1; i <= m; i++) {
      long long cnt = 0;
      for (long long j = i + 1; j <= m; j++) {
        if (a[j].val > a[i].val) {
          cnt++;
        }
      }
      long long idx;
      long long tmp = 0;
      for (long long k = m; k >= 1 && tmp <= cnt; k--) {
        if (!visited[k]) {
          tmp++;
        }
        idx = k;
      }
      for (long long j = idx; j >= 1; j--) {
        if (visited[j]) {
          continue;
        }
        for (long long k = 1; k < j; k++) {
          if (visited[k]) {
            ans++;
          }
        }
        visited[j] = true;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
