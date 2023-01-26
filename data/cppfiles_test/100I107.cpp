#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end());
    long long kuota = (-1) * v[0], minim = v[0];
    priority_queue<long long> pq;
    for (long long i = 1; i < n; i++) {
      if (v[i] + kuota > minim) {
        pq.push(v[i] + kuota);
      }
      minim = v[i] + kuota;
      kuota -= minim;
    }
    if (!pq.empty())
      printf("%lld\n", pq.top());
    else
      printf("%lld\n", v[0]);
  }
  return 0;
}
