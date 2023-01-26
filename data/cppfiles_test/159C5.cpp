#include <bits/stdc++.h>
using namespace std;
bool check(long long x) {
  int y = int(sqrt(x) + 0.5);
  return 1ll * y * y == x;
}
vector<int> solve(int n) {
  vector<int> rt;
  if (n % 4 == 0) {
    rt.push_back(n / 2);
    return rt;
  }
  if (n % 4 == 1) {
    rt = solve(n - 1);
    rt.push_back(n);
    return rt;
  }
  if (n % 4 == 2) {
    if (check(n + 2)) {
      rt.push_back(n / 2 + 1);
      return rt;
    }
    rt.push_back(2);
    rt.push_back(n / 2);
    return rt;
  }
  rt = solve(n - 1);
  rt.push_back(n);
  if (check(1ll * n * (n - 3) / 2) && rt.size() > 2) {
    rt.clear();
    rt.push_back((n - 5) / 2);
    rt.push_back(n - 2);
  }
  return rt;
}
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("1\n1");
    return 0;
  }
  vector<int> de = solve(n);
  printf("%d\n", int(n - de.size()));
  for (int i = 1; i <= n; i++) {
    bool zd = false;
    for (int x : de) {
      if (i == x) {
        zd = true;
        break;
      }
    }
    if (!zd) printf("%d ", i);
  }
  return 0;
}
