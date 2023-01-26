#include <bits/stdc++.h>
template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}
char buffer[2000000];
int n, m;
char *inp[1000000];
int perm[1000000];
int bucket[1000000];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  char *offset = buffer;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    inp[i] = offset;
    offset += m + 1;
    std::cin >> std::ws;
    std::cin.getline(inp[i], 2 * (m + 1));
    perm[i] = i;
    bucket[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int c = 0;
    while (c < n) {
      int b = c;
      if (i % 2 == 0) {
        for (char ch = 'A'; ch <= 'Z'; ch++) {
          int buck = b;
          for (; c < n && bucket[buck] == bucket[c]; c++) {
            if (inp[perm[c]][i] == ch) {
              swap(perm[c], perm[b]);
              b++;
            }
          }
          for (int j = buck; j < b; j++) {
            bucket[j] = buck;
          }
          c = b;
          if (b < n && bucket[b] != bucket[buck]) {
            break;
          }
        }
      } else {
        for (char ch = 'Z'; ch >= 'A'; ch--) {
          int buck = b;
          for (; c < n && bucket[buck] == bucket[c]; c++) {
            if (inp[perm[c]][i] == ch) {
              swap(perm[c], perm[b]);
              b++;
            }
          }
          for (int j = buck; j < b; j++) {
            bucket[j] = buck;
          }
          c = b;
          if (b < n && bucket[b] != bucket[buck]) {
            break;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << perm[i] + 1 << " ";
  }
  std::cout << std::endl;
  return 0;
}
