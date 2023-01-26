#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
priority_queue<pair<int, int> > q;
int n, a[maxn], win[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int x = 1, y = n;
  while (x <= n && a[x] < a[x + 1]) x++;
  while (y >= 1 && a[y] < a[y - 1]) y--;
  y = n - y + 1;
  if (x % 2 == 1 || y % 2 == 1)
    cout << "Alice\n";
  else
    cout << "Bob\n";
  return 0;
}
