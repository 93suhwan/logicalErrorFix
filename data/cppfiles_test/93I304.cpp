#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int chuan = 1;
    int time = 0;
    int yc = 0;
    while (chuan <= k && pow(2, time + 1) <= n) {
      chuan = chuan * 2;
      time++;
    }
    yc += pow(2, time);
    time += (n - yc) / k;
    if ((n - yc) % k != 0) time++;
    printf("%ld\n", time);
  }
}
