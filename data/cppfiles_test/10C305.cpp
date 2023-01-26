#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 17;
const long long inf = 1e18 + 1;
long long modi(long long numberToMod) {
  numberToMod += mod;
  numberToMod %= mod;
  return numberToMod;
}
long long powerWithMod(long long numberToPower, long long myPower) {
  if (!myPower) return long long(1);
  long long recursive = powerWithMod(numberToPower, myPower / long long(2));
  if (myPower % 2) return modi(modi(recursive * recursive) * numberToPower);
  return modi(recursive * recursive);
}
long long power(long long numberToPower, long long myPower) {
  if (!myPower) return long long(1);
  long long recursive = powerWithMod(numberToPower, myPower / long long(2));
  if (myPower % 2) return recursive * recursive * numberToPower;
  return recursive * recursive;
}
long long gcd(long long numberOne, long long numberTwo) {
  if (numberTwo == 0) return numberOne;
  return gcd(numberTwo, numberOne % numberTwo);
}
vector<long long> compute_pi(string pattern) {
  vector<long long> result(pattern.size());
  result[0] = 0;
  for (unsigned int i = 1; i < pattern.size(); i++) {
    result[i] = 0;
    int KMP_count = result[i - 1];
    while (KMP_count > 0 && pattern[KMP_count] != pattern[i])
      KMP_count = result[KMP_count - 1];
    if (pattern[KMP_count] == pattern[i]) result[i] = KMP_count + 1;
  }
  return result;
}
const int maxn = 2e5 + 10;
long long t;
long long m, x, k, a[maxn], n, c[maxn];
vector<int> v[maxn], save;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 0; i < n; i++) c[i] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      v[a[i]].push_back(i);
    }
    m = 0;
    x = 0;
    save.clear();
    for (int i = 1; i <= n; i++) {
      if (v[i].size() >= k) {
        for (int i2 = 0; i2 < k; i2++) c[v[i][i2]] = i2 + 1;
      } else {
        for (int i2 = 0; i2 < v[i].size(); i2++) save.push_back(v[i][i2]);
      }
    }
    x = int(save.size()) % k;
    for (int i = 0; i < save.size() - x; i++) c[save[i]] = (i % k) + 1;
    for (int i = 0; i < n; i++) cout << c[i] << " ";
    cout << endl;
  }
  return 0;
}
