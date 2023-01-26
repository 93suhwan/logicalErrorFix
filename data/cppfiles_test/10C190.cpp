#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t;
int br[N], cr[N], dr[N];
struct node {
  int x, y;
} ar[N];
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    memset(br, 0, sizeof br);
    memset(cr, 0, sizeof cr);
    memset(dr, 0, sizeof dr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> ar[i].x;
      ar[i].y = i;
      br[ar[i].x]++;
    }
    int z = 0;
    long long int ans = 0;
    for (int i = 0; i <= n; i++) {
      if (br[i] >= k)
        z++;
      else
        ans += br[i];
    }
    z = z + ans / k;
    sort(ar, ar + n, cmp);
    int mm = 1;
    for (int i = 0; i < n; i++) {
      if (z == 0)
        cr[ar[i].y] = 0;
      else if (dr[ar[i].x] < k) {
        dr[ar[i].x]++;
        cr[ar[i].y] = mm;
        mm++;
        if (mm > k) {
          mm = 1;
          z--;
        }
      } else
        cr[ar[i].y] = 0;
    }
    for (int i = 0; i < n; i++) {
      cout << cr[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
