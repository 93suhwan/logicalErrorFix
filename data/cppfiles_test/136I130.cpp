#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long arr[N];
long long ans[N];
int main() {
  int tmp;
  cin >> tmp;
  while (tmp--) {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &arr[i]);
      sum += arr[i];
    }
    long long down = n * (n + 1) / 2;
    if (sum % down) {
      puts("NO");
      continue;
    }
    sum /= down;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      ans[i] = (sum - arr[i] + arr[(i - 1 + n) % n]) / n;
      if (ans[i] <= 0) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      puts("NO");
    } else {
      puts("YES");
      for (int i = 0; i < n; i++) {
        printf("%lld%c", ans[i], i + 1 == n ? '\n' : ' ');
      }
    }
  }
  return 0;
}
