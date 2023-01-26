#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int i = 0, j = n - 1;
  while (i + 1 < n && a[i] < a[i + 1]) i++;
  while (j - 1 >= 0 && a[j] < a[j - 1]) j--;
  i++;
  j = n - j;
  cout << (i % 2 || j % 2 ? "Alice" : "Bob") << '\n';
  return 0;
}
