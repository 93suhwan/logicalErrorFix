#include <bits/stdc++.h>
using namespace std;
long long int dx[] = {0, 1, 0, -1};
long long int dy[] = {1, 0, -1, 0};
long long int dxx[] = {0, 1, 0, -1, 1, 1, -1, -1};
long long int dyy[] = {1, 0, -1, 0, 1, -1, 1, -1};
void solve() {
  int n;
  int m;
  scanf("%d%d", &n, &m);
  int a[n + 2];
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    int a1;
    scanf("%d", &a1);
    int x = n - (a1 - i);
    if (x >= n) x -= n;
    a[x]++;
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x = n - a[i];
    x++;
    x /= 2;
    if (x <= m) v.push_back(i);
  }
  cout << v.size();
  for (auto it : v) {
    cout << " " << it;
  }
  cout << "\n";
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
