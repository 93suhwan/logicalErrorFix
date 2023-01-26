#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int t, n, op, a, b, c;
int arr[N];
string str;
int main() {
  scanf("%d", &t);
  while (t--) {
    cin >> n >> op >> str;
    for (int i = 0; i < n; i++) {
      if (i % 2 != 0) {
        if (str[i] == '+')
          c = 1;
        else
          c = -1;
      } else {
        if (str[i] == '-')
          c = 1;
        else
          c = -1;
      }
      arr[i + 1] = arr[i] + c;
    }
    for (int i = 0; i < op; i++) {
      cin >> a >> b;
      c = arr[b] - arr[a - 1];
      if (c == 0)
        puts("0");
      else if (c % 2 == 0)
        puts("2");
      else
        puts("1");
    }
  }
  return 0;
}
