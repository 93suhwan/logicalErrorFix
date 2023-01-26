#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200005];
int fina[200005];
int a[200005][5] = {0};
int sum[200005];
int cha[200005];
struct node {
  int now;
  int other;
} nd[200005];
bool cmp(int a, int b) { return a > b; }
void init(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 4; j++) {
      a[i][j] = 0;
    }
    sum[i] = 0;
    cha[i] = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    init(n);
    for (int j = 1; j <= n; j++) {
      string s1;
      cin >> s1;
      for (int i = 0; i < s1.length(); i++) {
        a[j][s1[i] - 'a']++;
      }
      for (int i = 0; i <= 4; i++) {
        sum[j] += a[j][i];
      }
      bool flag = false;
    }
    int maxn = -1;
    for (int j = 0; j <= 4; j++) {
      for (int i = 1; i <= n; i++) {
        cha[i] = a[i][j] - (sum[i] - a[i][j]);
      }
      sort(cha + 1, cha + 1 + n, cmp);
      int ans = 0;
      int p = 0;
      for (int i = 1; i <= n; i++) {
        if (ans + cha[i] <= 0) break;
        ans += cha[i];
        p++;
      }
      maxn = max(maxn, p);
    }
    cout << maxn << endl;
  }
  return 0;
}
