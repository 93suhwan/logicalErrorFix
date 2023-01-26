#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long arr[105];
int main() {
  int tmp;
  cin >> tmp;
  while (tmp--) {
    int n;
    cin >> n;
    cin >> arr[1];
    bool flag = true;
    for (int i = 2; i <= n; i++) {
      cin >> arr[i];
      if (arr[i] == arr[i - 1]) {
        flag = false;
      }
    }
    printf("%lld\n", flag ? inf : 0);
  }
  return 0;
}
