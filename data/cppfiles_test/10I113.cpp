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
    vector<pair<long long, long long>> vpp, vp2;
    set<long long> st;
    set<long long>::iterator it;
    map<long long, long long> mp;
    long long k;
    cin >> n >> k;
    vector<long long> vp[n + 1];
    long long arr[n + 1];
    memset(arr, 0, sizeof(arr));
    long long sum = 0, x = 1;
    for (long long i = 0; i < n; i++) {
      cin >> x;
      mp[x]++;
      vp[x].push_back(i);
    }
    long long number = 1, index;
    for (auto it : mp) {
      long long a = it.first;
      long long b = it.second;
      if (b >= k) {
        long long number = 1;
        for (long long i = 0; i < k; i++) {
          index = vp[a][i];
          arr[index] = number;
          number++;
        }
      } else {
        for (long long i = 0; i < vp[a].size(); i++)
          vp2.push_back(make_pair(a, vp[a][i]));
      }
    }
    long long baki = vp2.size() - (vp2.size() % k);
    for (long long i = 0; i < baki; i++) {
      index = vp2[i].second;
      arr[index] = x;
      x++;
      if (x > k) x = 1;
    }
    for (long long i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}
