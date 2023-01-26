#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int n = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = 10 * n + (c ^ '0');
    c = getchar();
  }
  return f * n;
}
vector<int> even, odd;
bool isComposite(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return true;
    }
  }
  return false;
}
int main() {
  int t = read();
  for (int ca = 1; ca <= t; ca++) {
    int n = read(), sum = 0;
    for (int i = 1; i <= n; i++) {
      int k = read();
      sum += k;
      if (k & 1) {
        odd.push_back(i);
      } else {
        even.push_back(i);
      }
    }
    if (isComposite(sum)) {
      printf("%d\n", n);
      for (int i = 1; i <= n; i++) {
        printf("%d ", i);
      }
      puts("");
    } else {
      printf("%d\n", even.size() + odd.size() / 2 * 2);
      for (int i = 0; i < even.size(); i++) {
        printf("%d ", even[i]);
      }
      for (int i = 1; i < odd.size(); i++) {
        printf("%d ", odd[i]);
      }
      puts("");
    }
  }
  return 0;
}
