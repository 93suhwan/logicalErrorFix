#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n;
double p[N];
int book[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(book, 0, sizeof(book));
    memset(p, 0, sizeof(p));
    cin >> n;
    double minn = -1e10;
    int j;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      if (p[i] > minn) minn = p[i], j = i;
    }
    book[j] = 1;
    double sum = 0;
    for (int i = 0; i < n; i++)
      if (!book[i]) sum += p[i];
    double a = p[j] + sum / (n - 1);
    printf("%.9lf\n", a);
  }
}
