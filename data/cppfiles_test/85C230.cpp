#include <bits/stdc++.h>
using namespace std;
int n;
string a;
int main() {
  scanf("%d", &n);
  while (n--) {
    cin >> a;
    int l = 0, i = 0;
    for (; i < a.size() - 1; i++)
      if (a[i] != a[i + 1]) l++;
    if (!l && a[i] == '0')
      printf("1\n");
    else if (!l && a[i] == '1')
      printf("0\n");
    else if (l == 1)
      printf("1\n");
    else if (l == 2 && a[i] == '1')
      printf("1\n");
    else
      printf("2\n");
  }
}
