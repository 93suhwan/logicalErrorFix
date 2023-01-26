#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  int v[10];
  int tol;
  int ave;
} ma[N];
char s[N];
bool cmp(node A, node B) { return A.ave > B.ave; }
void run() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int j = 0; j < 5; j++) ma[i].v[j] = 0;
    int len = strlen(s);
    for (int j = 0; j < len; j++) {
      ma[i].v[s[j] - 'a']++;
    }
    ma[i].tol = len;
  }
  int maxx = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 1; j <= n; j++) ma[j].ave = ma[j].v[i] * 2 - ma[j].tol;
    sort(ma + 1, ma + 1 + n, cmp);
    int s = 0;
    for (int j = 1; j <= n; j++) {
      if (s + ma[j].ave > 0) {
        s += ma[j].ave;
        maxx = max(j, maxx);
      } else
        break;
    }
  }
  printf("%d\n", maxx);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    run();
  }
}
