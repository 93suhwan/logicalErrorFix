#include <bits/stdc++.h>
using namespace std;
vector<long long> cun, cun1, cun2;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cun.clear();
    cun1.clear();
    cun1.push_back(0);
    long long x, sum = 1;
    long long ch[111];
    ch[0] = 0;
    for (long long i = 2; i <= n; i++) {
      sum *= 2;
    }
    sum /= 2;
    for (long long i = 1; i <= n; i++) {
      cin >> ch[i];
      x = ch[i];
      cun.push_back(x);
      long long m = cun1.size();
      if (i == n) m -= sum;
      if (i > 1) {
        cun1.push_back(ch[i] + ch[i - 1]);
      }
      for (long long j = 1; j < m; j++) {
        cun1.push_back(cun1[j] + x);
        cun1.push_back(cun1[j] - x);
      }
    }
    bool flag = false;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (i != j && cun[i] == cun[j]) flag = true;
      }
    }
    sort(cun1.begin(), cun1.end());
    cun1.erase(unique(cun1.begin(), cun1.end()), cun1.end());
    for (long long i = 0; i < cun.size(); i++) {
      if (find(cun1.begin(), cun1.end(), cun[i]) != cun1.end()) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
