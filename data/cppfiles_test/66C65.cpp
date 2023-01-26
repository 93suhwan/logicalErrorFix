#include <bits/stdc++.h>
using namespace std;
vector<int> ord;
void Get_ord() {
  for (int i = 1; i <= 10000; ++i)
    if (i % 3 && i % 10 != 3) ord.push_back(i);
}
void into() {
  int n;
  scanf("%d", &n);
  printf("%d\n", ord[n - 1]);
}
void work() {}
void outo() {}
int main() {
  int T = 1;
  scanf("%d", &T);
  Get_ord();
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
