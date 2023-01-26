#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e5 + 10;
bool check(int x) {
  if (x % 3 == 0 || x % 10 == 3) return false;
  return true;
}
int main() {
  vector<int> v;
  for (int i = 1; i < N; i++) {
    if (check(i)) v.push_back(i);
  }
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", v[n - 1]);
  }
  return 0;
}
