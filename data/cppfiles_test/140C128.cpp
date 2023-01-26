#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007, N = 200001, M = 1000001;
int n;
map<long long, int> mp;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    mp.clear();
    scanf("%d", &n);
    for (long long i = 1; i * i <= n; i++) {
      mp[i * i]++;
    }
    for (long long i = 1; i * i * i <= n; i++) {
      mp[i * i * i]++;
    }
    printf("%d\n", mp.size());
  }
  return 0;
}
