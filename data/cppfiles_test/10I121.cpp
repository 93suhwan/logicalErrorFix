#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long flag[10000000 + 1];
void sieve() {
  for (long long i = 1; i <= 10000000; i++) flag[i] = 1;
  flag[1] = 0;
  for (long long i = 2; i * i <= 10000000; i++) {
    if (flag[i] == 1) {
      for (long long j = i * i; j <= 10000000; j = j + i) flag[j] = 0;
    }
  }
}
long long bigMod(long long a, long long b, long long M) {
  if (b == 0) return 1 % M;
  long long x = bigMod(a, b / 2, M);
  x = ((x % M) * (x % M)) % M;
  if (b % 2 == 1) {
    long long y = ((x % M) * (a % M)) % M;
    return y;
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    vector<long long> v1, v2, v3, v4, v5;
    vector<pair<long long, long long>> vp, vp2;
    set<long long> st;
    set<long long>::iterator it;
    map<long long, long long> mp;
    long long k;
    cin >> n >> k;
    long long arr[n], arr2[n];
    memset(arr2, 0, sizeof(arr2));
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      mp[arr[i]]++;
      vp.push_back(make_pair(arr[i], i));
    }
    sort(vp.begin(), vp.end());
    long long sum = 0, x = 1;
    for (auto it : mp) {
      x = 1;
      if (it.second >= k) {
        for (long long i = 0; i < vp.size(); i++) {
          if (vp[i].first == it.first) {
            arr2[vp[i].second] = x;
            x++;
            if (x > k) break;
          }
        }
      } else {
        for (long long i = 0; i < vp.size(); i++) {
          if (vp[i].first == it.first) {
            vp2.push_back(make_pair(it.first, vp[i].second));
          }
        }
      }
      x = 1;
      long long z = vp2.size() % k;
      for (long long i = 0; i < vp2.size() - z; i++) {
        arr2[vp2[i].second] = x;
        if (x > k) x = 1;
        x++;
      }
      for (long long i = 0; i < n; i++) cout << arr2[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
