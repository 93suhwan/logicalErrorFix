#include <bits/stdc++.h>
using namespace std;
vector<long long> v3;
vector<long long> v1[100001];
vector<long long> v2[100001];
long long c1[100001];
long long c2[100001];
vector<pair<long long, long long>> v5;
long long sum1;
long long k1;
long long k3 = -1;
int main() {
  long long i, t;
  cin >> t;
  for (i = 0; i < t; i++) {
    long long k;
    cin >> k;
    long long l1 = 1;
    long long t1 = 0;
    long long k1 = 0;
    while (l1 <= 2000) {
      if (!(l1 % 3 == 0 || l1 % 10 == 3)) {
        t1++;
        if (t1 == k) {
          k1 = l1;
          break;
        }
      }
      l1++;
    }
    cout << k1 << endl;
  }
  return 0;
}
