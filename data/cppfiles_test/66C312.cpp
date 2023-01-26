#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
int a[1001] = {0};
void hack(int pp) {
  int n;
  cin >> n;
  if (a[0] == 0) {
    int t = 0;
    int k = 1;
    while (t <= 1000) {
      if (k % 3 != 0 & (k % 10) != 3) {
        a[t] = k;
        t++;
      }
      k++;
    }
  }
  cout << a[n - 1] << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  int l = 0;
  while (t--) {
    hack(l);
    l++;
  }
  return 0;
}
