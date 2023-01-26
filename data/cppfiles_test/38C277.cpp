#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long int N, count;
    cin >> N;
    if (N <= 6)
      count = 15;
    else if (N <= 8)
      count = 20;
    else if (N <= 10)
      count = 25;
    else if (N % 6 == 0 || N % 6 == 5) {
      long long int x = N / 6;
      if (N % 6 == 5) x++;
      count = x * 15;
    } else if (N % 6 == 1 || N % 6 == 2) {
      long long int x = N / 6;
      x--;
      count = x * 15 + 20;
    } else {
      long long int x = N / 6;
      x--;
      count = x * 15 + 25;
    }
    cout << count << "\n";
  }
  return 0;
}
