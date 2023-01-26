#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  scanf("%d", &x);
  while (x--) {
    int y;
    scanf("%d", &y);
    int arr;
    scanf("%d", &arr);
    if (y <= arr / 2) {
      printf("%d\n", arr %= (arr / 2) + 1);
    } else {
      printf("%d\n", arr % y);
    }
  }
}
