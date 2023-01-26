#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, temp = 0;
  bool res = 0;
  deque<int> a;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &i);
    a.push_back(i);
  }
  while (a.size() > 0 && (a.front() > temp || a.back() > temp)) {
    if (a.front() > a.back()) {
      temp = a.front();
      a.pop_front();
    } else {
      temp = a.back();
      a.pop_back();
    }
    res = !res;
  }
  if (res)
    printf("Alice");
  else
    printf("Bob");
  return 0;
}
