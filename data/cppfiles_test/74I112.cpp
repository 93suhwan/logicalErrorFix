#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
inline int read() {
  int num = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) num = num * 10 + (c ^ 48), c = getchar();
  return num * f;
}
inline int re1d() {
  char c = getchar();
  while (c < 48 || c > 49) c = getchar();
  return c & 1;
}
inline int min(int a, int b) { return a > b ? b : a; }
inline int max(int a, int b) { return a < b ? b : a; }
int a[1005], p[1000006], c[1000005], d[1005];
signed main() {
  int n = read();
  for (int i = 1; i <= (n); i++) {
    a[i] = read();
  }
  if (n == 2) {
    if (a[1] == a[2]) {
      puts("YES");
      printf("%d %d\n", a[1], 0);
    } else {
      puts("NO");
    }
    return 0;
  }
  std::sort(a + 1, a + 1 + n, [&](int x, int y) { return (x & 1) < (y & 1); });
  if (a[3] & 1) {
    if (a[2] & 1) {
      if (a[1] & 1) {
        for (int i = 1; i <= (n); i++) {
          c[a[i]]++;
        }
        for (int i = 1; i <= (n); i++) {
          for (int j = 1; j <= (n); j++) {
            if (i != j && a[i] >= a[j]) p[a[i] - a[j]]++;
          }
        }
        if (p[0]) {
          puts("YES");
          int f = 0, g = 0;
          for (int i = 1; i <= (n); i++) {
            if (c[a[i]] >= 2 && f == 0)
              d[i] = 1, g = i, f = 1;
            else if (a[i] == a[g] && f == 1)
              f = 2, d[i] = 1;
          }
          printf("%d ", a[g]), printf("%d ", 0);
          for (int i = 1; i <= (n); i++) {
            if (!d[i]) printf("%d ", a[i]);
          }
        } else {
          clock_t AA = clock();
          for (int i = 1; i <= (10000000); i++) {
            std::random_shuffle(a + 1, a + 1 + n);
            for (int i = 1; i <= (n); i++) {
              d[i] = d[i - 1] + a[i];
            }
            for (int i = 1; i <= (n >> 1); i++) {
              std::unordered_map<int, int> mp;
              for (int j = 1; j <= (n); j++) {
                if (j < i) continue;
                int s = d[j] - d[j - i];
                if (mp[s]) {
                  puts("YES");
                  int k = 0;
                  for (int g = 1; g <= (i); g++) {
                    printf("%d ", k), k = a[mp[s] + 1 - g] - k;
                    printf("%d ", k);
                    k = a[j + 1 - g] - k;
                    p[mp[s] + 1 - g] = p[j + 1 - g] = 1;
                  }
                  for (int i = 1; i <= (n); i++) {
                    if (p[i] == 0) printf("%d ", a[i]);
                  }
                  return 0;
                } else
                  mp[s] = j;
              }
            }
            if ((double)(clock() - AA) / CLOCKS_PER_SEC > 0.9) break;
          }
          puts("NO");
        }
      } else {
        int A = a[1], B = a[2], C = a[3], D = A + B + C >> 1;
        puts("YES");
        printf("%d ", D - A), printf("%d ", D - B), printf("%d ", D - C);
        D -= A;
        for (int i = 1; i <= (n); i++) {
          if (i > 3) printf("%d ", a[i] - D);
        }
      }
    } else {
      if (n == 3) {
        if (a[1] == a[2]) {
          puts("YES");
          printf("%d %d %d\n", a[1], 0, a[3] - a[1]);
        } else
          puts("NO");
      } else {
        a[1] ^= a[4] ^= a[1] ^= a[4];
        int A = a[1], B = a[2], C = a[3], D = A + B + C >> 1;
        puts("YES");
        printf("%d ", D - A), printf("%d ", D - B), printf("%d ", D - C);
        D -= A;
        for (int i = 1; i <= (n); i++) {
          if (i > 3) printf("%d ", a[i] - D);
        }
      }
    }
  } else {
    int A = a[1], B = a[2], C = a[3], D = A + B + C >> 1;
    puts("YES");
    printf("%d ", D - A), printf("%d ", D - B), printf("%d ", D - C);
    D -= A;
    for (int i = 1; i <= (n); i++) {
      if (i > 3) printf("%d ", a[i] - D);
    }
  }
  return 0;
}
