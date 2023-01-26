#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    for (int i = 1; pow(i, 3) <= x; i++) {
      s.insert(int(pow(i, 3) + 0.5));
    }
    for (int i = 1; pow(i, 2) <= x; i++) {
      s.insert(int(pow(i, 2) + 0.5));
    }
    printf("%d\n", s.size());
    s.clear();
  }
  return 0;
}
