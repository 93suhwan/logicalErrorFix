#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    int64_t n;
    std::cin >> n;
    int numInteresting = (n + 1) / 10;
    std::cout << numInteresting << std::endl;
  }
}
