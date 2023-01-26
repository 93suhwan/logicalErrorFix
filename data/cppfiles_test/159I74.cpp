#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int h[1000001];
unordered_map<int, int> M;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid = uniform_int_distribution<int>();
void PrintAns(int n, int x, int y) {
  int c = n - (x != 0) - (y != 0);
  printf("%d\n", c);
  for (int i = 1; i <= n; ++i) {
    if (i == x || i == y) {
      continue;
    }
    printf("%d ", i);
  }
  printf("\n");
}
void Find(int n) {
  int H = 0;
  for (int i = 1; i <= n; ++i) {
    H ^= h[i];
  }
  if (H == 0) {
    PrintAns(n, 0, 0);
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (h[i] == H) {
      PrintAns(n, i, 0);
      return;
    }
  }
  M.clear();
  for (int i = 2; i <= n; ++i) {
    auto it = M.find(H ^ h[i]);
    if (it != M.end()) {
      PrintAns(n, it->second, i);
      return;
    }
    M[h[i]] = i;
  }
  Find(n - 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    a[i] = i;
  }
  for (int i = 2; i <= n; ++i) {
    if (a[i] != i) {
      continue;
    }
    int hi = uid(rng);
    for (int j = i; j <= n; j += i) {
      int x = a[j];
      int hj = h[j];
      for (; x % i == 0; x /= i) {
        hj ^= hi;
      }
      a[j] = x, h[j] = hj;
    }
  }
  for (int i = 2; i <= n; ++i) {
    h[i] ^= h[i - 1];
  }
  Find(n);
  return 0;
}
