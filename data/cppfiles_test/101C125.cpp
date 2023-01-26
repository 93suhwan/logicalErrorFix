#include <bits/stdc++.h>
using namespace std;
void sad() {
  int n, blue = 0, red = 0;
  scanf("%d", &n);
  vector<pair<int, int>> v(n);
  for (auto &x : v) scanf("%d", &x.first);
  string a;
  cin >> a;
  vector<int> reds, blues;
  for (int i = 0; i < a.length(); i++) {
    v[i].second = a[i];
    if (a[i] == 'R')
      reds.push_back(v[i].first);
    else
      blues.push_back(v[i].first);
  }
  sort(reds.rbegin(), reds.rend());
  sort(blues.begin(), blues.end());
  for (int i = 0; i < reds.size(); i++) {
    if ((n - i) - reds[i] < 0) {
      puts("NO");
      return;
    }
  }
  for (int i = 0; i < blues.size(); i++) {
    if (blues[i] - (1 + i) < 0) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
int main() {
  int n = 1;
  scanf("%d", &n);
  while (n--) sad();
  return 0;
}
