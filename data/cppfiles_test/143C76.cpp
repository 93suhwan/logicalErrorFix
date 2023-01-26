#include <bits/stdc++.h>
using namespace std;
int num[200010];
map<int, int> pNum;
long long ppA[200010];
map<int, int> use;
long long check(int x) {
  if (x > 0 && ppA[x - 1] == -1) {
    ppA[x] = -1;
    return -1;
  }
  long long ans = 0;
  if (x > 0) ans += ppA[x - 1];
  if (x > 0 && pNum[x - 1] == 0) {
    if (use.empty()) {
      ppA[x] = -1;
      return -1;
    }
    int pp = use.rbegin()->first;
    use.rbegin()->second--;
    if (use.rbegin()->second == 0) {
      use.erase(use.rbegin()->first);
    }
    ans += x - 1 - pp;
  }
  if (pNum[x] > 1) {
    use[x] = pNum[x] - 1;
  }
  ppA[x] = ans;
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
    for (int i = 0; i <= n; i++) printf("%lld ", check(i));
    printf("\n");
    pNum.clear();
  }
  return 0;
}
