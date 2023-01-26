#include <bits/stdc++.h>
using namespace std;
struct sru {
  long long num;
  int color;
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    sru s[100];
    for (int i = 0; i < n; i++) cin >> s[i].num;
    int sum = 0;
    long long date = 0;
    for (long long i = 2; i < 100; i++) {
      for (int j = 0; j < n; j++) {
        if (s[j].num % i == 0 && s[j].num / i > 0)
          s[j].color = 1;
        else
          s[j].color = 0;
      }
      for (int j = 0; j < n - 1; j++) {
        if (s[j].color != s[j + 1].color)
          sum++;
        else
          continue;
      }
      if (sum == n - 1) {
        date = i;
        break;
      }
      sum = 0;
    }
    if (date)
      cout << date << endl;
    else
      cout << date << endl;
  }
}
