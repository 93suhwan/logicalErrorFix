#include <bits/stdc++.h>
using namespace std;
long long int a[10], b[10], book[10];
int main() {
  long long int n;
  scanf("%lld", &n);
  while (n--) {
    for (long long int i = 1; i <= 7; i++) {
      scanf("%lld", &a[i]);
    }
    long long int i1 = 0, j1 = 0, k1 = 0;
    for (long long int i = 1; i <= 7; i++) {
      for (long long int j = i + 1; j <= 7; j++) {
        for (long long int k = j + 1; k <= 7; k++) {
          long long int cnt = 0;
          book[1] = book[2] = book[3] = book[4] = 0;
          for (long long int x = 1; x <= 7; x++) {
            if (x == i || x == j || x == k)
              continue;
            else {
              b[1] = a[i] + a[j];
              b[2] = a[i] + a[k];
              b[3] = a[j] + a[k];
              b[4] = a[i] + a[j] + a[k];
              for (long long int y = 1; y <= 4; y++) {
                if (a[x] == b[y] && book[y] == 0) {
                  cnt++;
                  book[y] = 1;
                }
              }
            }
          }
          if (cnt == 4) {
            i1 = i;
            j1 = j;
            k1 = k;
          }
        }
      }
    }
    cout << a[i1] << " " << a[j1] << " " << a[k1] << " " << endl;
  }
}
