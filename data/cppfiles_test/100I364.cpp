#include <bits/stdc++.h>
using namespace std;
const long long limit = 2e5 + 1;
const long long mod = 998244353;
long long fact[limit];
int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  long long t;
  cin >> t;
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < limit; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  map<long long, long long> freq;
  while (t--) {
    freq.clear();
    long long n;
    cin >> n;
    long long num;
    for (long long i = 0; i < n; i++) {
      cin >> num;
      freq[num]++;
    }
    if (freq.size() == 1) {
      cout << fact[freq[num]] << endl;
      continue;
    }
    auto itr = freq.rbegin();
    pair<long long, long long> lastNum = *itr;
    itr++;
    pair<long long, long long> secondNum = *itr;
    if ((lastNum.first - secondNum.first) > 1) {
      cout << 0 << endl;
      continue;
    }
    long long elementNo = secondNum.second;
    long long ans = fact[elementNo];
    for (int i = 0; i < lastNum.second; i++) {
      ans = (ans * elementNo) % mod;
      elementNo++;
    }
    while (n != elementNo) {
      ans = (ans * (elementNo + 1)) % mod;
      elementNo++;
    }
    cout << ans << endl;
  }
}
