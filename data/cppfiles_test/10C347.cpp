#include <bits/stdc++.h>
using namespace std;
struct Pair {
  int val, index;
  Pair(int a = 0, int b = 0) {
    val = a;
    index = b;
  }
};
Pair a[200010];
int cnt[200010];
int col[200010];
bool comp(const Pair& a, const Pair& b) { return a.val < b.val; }
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].val);
      a[i].index = i;
    }
    sort(a + 1, a + n + 1, comp);
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0;
      col[i] = 0;
    }
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
      if (cnt[a[i].val] < k) {
        pos.push_back(a[i].index);
        cnt[a[i].val]++;
      }
    }
    int max_n = pos.size();
    max_n = max_n - max_n % k;
    for (int i = 0; i < max_n; i++) {
      col[pos[i]] = i % k + 1;
    }
    for (int i = 1; i <= n; i++) printf("%d ", col[i]);
    printf("\n");
  }
}
