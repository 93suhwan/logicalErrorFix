#include <bits/stdc++.h>
using namespace std;
long long a1[100010], a2[100010];
vector<long long> ind1, ind2;
void precompute() {
  for (int i = 0; i < 100010; i++) {
    if (i % 2 == 0) {
      a1[i] = 0;
      a2[i] = 1;
    } else {
      a1[i] = 1;
      a2[i] = 0;
    }
    if (a1[i] == 0) {
      ind1.push_back(i);
    }
    if (a2[i] == 0) {
      ind2.push_back(i);
    }
  }
}
int main() {
  long long t;
  cin >> t;
  precompute();
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long e, o;
    e = o = 0;
    vector<long long> ind;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] % 2 == 0) {
        arr[i] = 0;
        e++;
        ind.push_back(i);
      } else {
        arr[i] = 1;
        o++;
      }
    }
    if (abs(e - o) >= 2) {
      cout << -1 << endl;
      continue;
    }
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < ind.size(); i++) {
      sum1 += abs(ind[i] - ind1[i]);
      sum2 += abs(ind[i] - ind2[i]);
    }
    if (e == o)
      cout << min(sum1, sum2) << endl;
    else if (e > o)
      cout << sum1 << endl;
    else
      cout << sum2 << endl;
  }
  return 0;
}
