#include <bits/stdc++.h>
using namespace std;
int n;
string a;
int main() {
  scanf("%d", &n);
  while (n--) {
    cin >> a;
    if (a.find("0") == a.npos)
      printf("0\n");
    else if (a.find("1") == a.npos)
      printf("1\n");
    else {
      int l = 0, r = a.size() - 1;
      while (a[l] == a[l + 1]) l++;
      while (a[r] == a[r - 1]) r--;
      if (r - l > 1 && a[l] == '0')
        printf("2\n");
      else
        printf("1\n");
    }
  }
}
