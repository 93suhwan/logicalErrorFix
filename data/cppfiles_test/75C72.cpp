#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int l = 0, r = n - 1;
  while (l + 1 < n && a[l] < a[l + 1]) l++;
  while (r - 1 >= 0 && a[r] < a[r - 1]) r--;
  l++;
  r = n - r;
  (l % 2 || r % 2) ? cout << "Alice" : cout << "Bob";
}
