#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 1;
long long int facts[mxN];
long long int modu = 998244353;
long long int power(long long int base, long long int exp) {
  long long int currVale = base;
  long long int res = 1;
  while (exp) {
    if (exp % 2) {
      res = ((res % modu) * (currVale % modu)) % modu;
    }
    exp /= 2;
    currVale = ((currVale % modu) * (currVale % modu)) % modu;
  }
  return res;
}
long long int invMod(long long int num) { return power(num, modu - 2); }
long long int binCo(long long int num, long long int r) {
  long long int res = facts[num];
  res = (res * invMod(facts[r])) % modu;
  res = (res * invMod(facts[num - r])) % modu;
  return res;
}
int main() {
  facts[0] = facts[1] = 1;
  for (long long int i = 2; i <= mxN; i++) {
    facts[i] = i * facts[i - 1];
  }
  long long int nofTC;
  cin >> nofTC;
  while (nofTC--) {
    long long int n;
    cin >> n;
    vector<long long int> tasks(n);
    for (long long int i = 0; i < n; i++) {
      cin >> tasks[i];
    }
    sort(tasks.begin(), tasks.end());
    long long int diff = tasks[n - 1] - tasks[n - 2];
    if (diff == 0) {
      cout << facts[n] << "\n";
      continue;
    } else if (diff >= 2) {
      cout << "0\n";
      continue;
    }
    long long int freqof2ndMax = 0;
    for (long long int i = 0; i < n; i++) {
      if (tasks[n - 2] == tasks[i]) {
        freqof2ndMax++;
      }
    }
    long long int res = facts[n];
    for (long long int i = freqof2ndMax; i < n; i++) {
      long long int notNice =
          ((binCo(i, freqof2ndMax) % modu) * (facts[freqof2ndMax] % modu) *
           (facts[n - freqof2ndMax - 1] % modu)) %
          modu;
      res = ((res % modu) - (notNice % modu) + modu) % modu;
    }
    cout << res % modu << "\n";
  }
}
