#include <bits/stdc++.h>
using namespace std;
void work() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  cout << (a + c) % 2 << '\n';
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
}
