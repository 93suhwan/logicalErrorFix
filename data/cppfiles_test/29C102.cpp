#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long int min(long long int a, long long int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2)
    return ((b * power((b) * (b), (e - 1) / 2)));
  else
    return power((b) * (b), e / 2);
}
signed main() {
  long long int ts;
  cin >> ts;
  while (ts--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n, 0);
    long long int ze = 0, on = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] == 0) ze++;
      if (v[i] == 1) on++;
    }
    cout << (long long int)pow(2, ze) * on << "\n";
  }
}
