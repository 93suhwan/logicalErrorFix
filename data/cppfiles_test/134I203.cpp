#include <bits/stdc++.h>
using namespace std;
struct sru {
  long long num;
  int color;
};
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    sru s[1000];
    for (long long i = 0; i < n; i++) {
      cin >> s[i].num;
    }
    long long sum = 0;
    long long date = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (s[j].num % s[i].num == 0 && s[j].num / s[i].num > 0)
          s[j].color = 1;
        else
          s[j].color = 0;
      }
      for (long long j = 0; j < n - 1; j++) {
        if (s[j].color != s[j + 1].color)
          sum++;
        else
          continue;
      }
      if (sum == n - 1) {
        date = s[i].num;
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
