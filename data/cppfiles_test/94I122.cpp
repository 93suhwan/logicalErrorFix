#include <bits/stdc++.h>
using namespace std;
vector<long long> pwr(35);
long long fun(long long n1, long long n2) {
  vector<long long> arr1, arr2;
  vector<long long> car(35, 0);
  long long p, i, j, k;
  p = n1;
  while (p) arr1.push_back(p % 10), p /= 10;
  p = n2;
  while (p) arr2.push_back(p % 10), p /= 10;
  while ((long long)arr1.size() < 35) arr1.push_back(0);
  while ((long long)arr2.size() < 35) arr2.push_back(0);
  long long ans = 0;
  long long didcarry = 0;
  for (i = 0; i < 35; i++) {
    long long a1 = arr1[i], a2 = arr2[i];
    long long a3 = car[i];
    if (a2 >= a1 + a3) {
      long long rem = a2 - (a1 + a3);
      ans = (ans) + rem * pwr[i];
    } else {
      didcarry = 1;
      if (i + 2 < 35) car[i + 2] += 1;
      a2 += 10;
      long long rem = a2 - (a1 + a3);
      ans = (ans) + rem * pwr[i];
    }
  }
  if (!didcarry)
    return 0;
  else
    return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  {
    long long i;
    pwr[0] = 1;
    for (i = 1; i <= 34; i++) pwr[i] = pwr[i - 1] * 10;
  }
  while (t--) {
    long long i, j, k, l, m, n;
    cin >> n;
    long long normal = 1;
    long long a1 = n;
    while (a1) {
      long long p = a1 % 10;
      normal *= (p + 1);
      a1 /= 10;
    }
    normal -= 2;
    for (i = 1; (i * i) < n; i++) {
      normal = max(normal, i);
    }
    cout << normal << "\n";
  }
  return 0;
}
