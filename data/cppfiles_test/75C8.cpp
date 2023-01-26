#include <bits/stdc++.h>
void print_winner(bool is_alice) {
  if (is_alice) {
    std::cout << "Alice" << std::endl;
  } else {
    std::cout << "Bob" << std::endl;
  }
}
int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int llen = 1;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] >= a[i + 1]) {
      llen = i + 1;
      break;
    }
  }
  int rlen = 1;
  for (int i = n - 1; i > 0; --i) {
    if (a[i] >= a[i - 1]) {
      rlen = n - i;
      break;
    }
  }
  int l = 0;
  int r = n - 1;
  bool is_alice = true;
  while (l < n && r >= 0) {
    if (llen == 1 || rlen == 1) {
      print_winner(is_alice);
      return 0;
    }
    if (a[l] >= a[r]) {
      if (llen % 2 == 1) {
        print_winner(is_alice);
        return 0;
      }
      --r;
      --rlen;
    } else if (a[r] >= a[l]) {
      if (rlen % 2 == 1) {
        print_winner(is_alice);
        return 0;
      }
      ++l;
      --llen;
    }
    is_alice = !is_alice;
  }
  std::cout << "error!" << std::endl;
  return -1;
}
