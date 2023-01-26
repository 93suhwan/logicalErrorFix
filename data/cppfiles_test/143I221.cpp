#include <bits/stdc++.h>
using namespace std;
int num[200010];
map<int, int> pNum;
int check(int x) {
  int ans = 0;
  map<int, int> use;
  for (int i = 0; i < x; i++) {
    if (pNum[i] == 0) {
      if (use.empty()) return -1;
      int pp = use.rbegin()->first;
      if (use.rbegin()->second == 1) {
        use.erase(use.rbegin()->first);
      }
      ans += i - pp;
    } else if (pNum[i] > 1) {
      use[i] = pNum[i] - 1;
    }
  }
  ans += pNum[x];
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &num[i]);
      pNum[num[i]]++;
    }
    for (int i = 0; i <= n; i++) printf("%d ", check(i));
    printf("\n");
    pNum.clear();
  }
  return 0;
}
