#include <bits/stdc++.h>
const int int_reme = 2147483647;
const int log21e9_reme = 30;
const int maxn = 2e5 + 10;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
clock_t SS, TT;
using namespace std;
int time_ms() {
  TT = clock();
  return (int)(((double)(TT - SS) / CLOCKS_PER_SEC) * 1000);
}
int DATA[maxn];
int main() {
  SS = clock();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int temp = n % 3;
    if (temp == 0) {
      printf("%d %d\n", n / 3, n / 3);
    } else if (temp == 1) {
      printf("%d %d\n", n / 3 + 1, n / 3);
    } else if (temp == 2) {
      printf("%d %d\n", n / 3, n / 3 + 1);
    }
  }
  return 0;
}
