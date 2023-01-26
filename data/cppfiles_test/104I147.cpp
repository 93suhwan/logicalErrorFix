#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int SIZE = 1000002;
const long long INF = 1LL << 60;
const double eps = 1e-6;
const double PI = 3.1415926535897932;
int a[200009];
int rs[200009];
int n;
vector<int> ans;
int main() {
  int ___T, case_n = 1;
  scanf("%d ", &___T);
  while (___T-- > 0) {
    scanf("%d", &(n));
    int oddz = -1;
    for (int i = 0; i < (n); ++i) {
      scanf("%d", &(a[i]));
      rs[i + 1] = rs[i] ^ a[i];
      if ((i + 1) % 2 && rs[i + 1] == 0) {
        oddz = i + 1;
      }
    }
    if (oddz == -1 || rs[n]) {
      puts("NO");
      continue;
    }
    if (oddz) {
      ans.clear();
      for (int i = oddz + 1; i + 2 <= n; i += 2) {
        if (rs[i + 1]) ans.push_back(i);
      }
      for (int i = oddz - 2; i >= 1; i -= 2) {
        if (rs[i]) ans.push_back(i);
      }
    }
    for (int i = 1; i + 2 <= n; i += 2) {
      if (rs[i + 1]) ans.push_back(i);
    }
    puts("YES");
    printf("%d\n", ((int)(ans).size()));
    for (int i = 0; i < (((int)(ans).size())); ++i) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    puts("");
    case_n++;
  }
}
