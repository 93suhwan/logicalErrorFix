#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int modu = 998244353;
  long long int nofTC;
  cin >> nofTC;
  while (nofTC--) {
    long long int n;
    cin >> n;
    vector<long long int> facts(n + 1, 1);
    for (long long int i = 2; i <= n; i++) {
      facts[i] = ((i % modu) * (facts[i - 1] % modu)) % modu;
    }
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
          ((((facts[i] % modu) * (facts[freqof2ndMax] % modu) *
             (facts[n - freqof2ndMax - 1] % modu)) %
            modu) /
           (((facts[freqof2ndMax] % modu) * (facts[i - freqof2ndMax] % modu))) %
           modu) %
          modu;
      res = ((res % modu) - (notNice % modu) + modu) % modu;
    }
    cout << res << "\n";
  }
}
