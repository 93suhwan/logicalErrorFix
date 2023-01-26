#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int num[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  int l = 1, r = n;
  while (l < n && num[l] < num[l + 1]) l++;
  while (r > 1 && num[r] < num[r - 1]) r--;
  int ma = 0;
  for (int i = 1; i <= l; i++) ma = max(ma, num[i]);
  for (int i = n; i >= r; i--) ma = max(ma, num[i]);
  int sum1 = l, sum2 = n - r + 1;
  if (sum2 % 2 == 1 || sum1 % 2 == 1)
    cout << "Alice\n";
  else
    cout << "Bob\n";
  return 0;
}
