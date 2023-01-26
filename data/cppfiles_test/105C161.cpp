#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int d[3000][3000];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    std::vector<std::vector<int> > col(n);
    for (int i = 0; i < n; i++) a[i]--;
    for (int i = 0; i < n; i++) col[a[i]].push_back(i);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) d[i][j] = n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < i + 1; j++) d[i][j] = 0;
    for (int l = 2; l < n + 1; l++) {
      for (int s = 0; s < n - l + 1; s++) {
        int e = s + l - 1;
        d[s][e] = min(d[s][e], d[s][e - 1] + 1);
        for (auto f : col[a[e]]) {
          if (f > e) break;
          if (f < s) continue;
          if (f == s) {
            d[s][e] = d[s + 1][e];
            break;
          }
          int cand = d[s][f - 1] + 1 + d[f][e];
          d[s][e] = min(d[s][e], cand);
        }
      }
    }
    printf("%d\n", d[0][n - 1]);
  }
}
