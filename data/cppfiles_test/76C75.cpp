#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 4e6 + 10, mod = 1e9 + 7;
int n, m;
set<int> s[N];
int main() {
  cin >> n >> m;
  srand(time(NULL));
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    s[a].insert(b);
    s[b].insert(a);
  }
  for (int i = 0; i < (int)1e6; i++) {
    int a[6];
    for (int i = 0; i < 5; i++) a[i] = rand() % n + 1;
    bool ff = false;
    int k = s[a[0]].count(a[1]);
    for (int j = 0; j < 5; j++)
      for (int p = j + 1; p < 5; p++)
        if (a[j] == a[p] || s[a[j]].count(a[p]) != k) {
          ff = true;
          break;
        }
    if (!ff) {
      for (int j = 0; j < 5; j++) cout << a[j] << " ";
      return 0;
    }
  }
  cout << -1;
  return 0;
}
