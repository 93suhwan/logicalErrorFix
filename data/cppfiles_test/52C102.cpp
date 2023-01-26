#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int a[100005];
int mymax;
double sum;
int main() {
  cin >> t;
  while (t--) {
    mymax = -0x7f7f7f7f;
    sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      mymax = max(mymax, a[i]);
      sum = sum + a[i];
    }
    printf("%.9f\n", mymax + (sum - mymax) / (n - 1));
  }
  return 0;
}
