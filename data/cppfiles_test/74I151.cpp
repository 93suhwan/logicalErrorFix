#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void _debug() { std::cerr << std::endl; }
template <typename T, typename... U>
void _debug(T t, U... args) {
  std::cerr << " " << t;
  _debug(args...);
}
const int maxn = 1e3 + 10;
int a[maxn], n, cnt[2];
int d[maxn * maxn];
map<int, int> dm[maxn * maxn];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i] & 1]++;
  }
  if (n == 2) {
    if (a[0] == a[1]) {
      printf("YES\n%d %d\n", 0, a[0]);
    } else
      puts("NO");
    return 0;
  }
  sort(a, a + n);
  int m = unique(a, a + n) - a;
  if (m < n) {
    puts("YES");
    for (int i = 0; i < m; i++) printf("%d ", a[i]);
    printf("%d ", 0);
    for (int i = m + 1; i < n; i++) printf("%d ", 0);
    return 0;
  } else if (n == 3) {
    int sum = (a[0] + a[1] + a[2]);
    if (sum % 2 == 0) {
      sum /= 2;
      puts("YES");
      printf("%d %d %d\n", sum - a[0], sum - a[1], sum - a[2]);
    } else
      puts("NO");
  } else if (cnt[0] > 0) {
    vector<int> vec[2];
    for (int i = 0; i < n; i++) {
      vec[a[i] & 1].push_back(i);
    }
    vector<int> val;
    vector<bool> vis(n);
    if (vec[0].size() >= 3) {
      for (int i = 0; i < 3; i++) {
        val.push_back(a[vec[0][i]]);
        vis[vec[0][i]] = 1;
      }
    } else {
      vis[vec[0][0]] = 1;
      val.push_back(a[vec[0][0]]);
      for (int i = 0; i < 2; i++)
        val.push_back(a[vec[1][i]]), vis[vec[1][i]] = 1;
    }
    int sum = 0;
    for (int i : val) sum += i;
    sum /= 2;
    puts("YES");
    for (int i = 0; i < 3; i++) printf("%d ", sum - val[i]);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) printf("%d ", a[i] - (sum - val[0]));
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int diff = a[j] - a[i];
        int all = d[diff];
        int cov = dm[diff][j] + dm[diff][i];
        assert(all >= cov);
        if (all > cov) {
          for (int ii = 0; ii < n; ii++) {
            if (ii == i || ii == j) continue;
            for (int jj = ii + 1; jj < n; jj++) {
              if (jj == i || jj == j) continue;
              int diff2 = a[jj] - a[ii];
              if (diff == diff2) {
                vector<bool> vis(n);
                vis[ii] = vis[jj] = vis[i] = vis[j] = 1;
                puts("YES");
                printf("%d %d %d %d ", a[i], a[j], 0, a[ii] - a[i]);
                for (int i = 0; i < n; i++) {
                  if (!vis[i]) printf("%d ", a[i]);
                }
                return 0;
              }
            }
          }
          assert(0);
        }
        d[diff]++;
        dm[diff][i]++;
        dm[diff][j]++;
      }
    }
    puts("NO");
  }
}
