#include <bits/stdc++.h>
using namespace std;
const long long N = 5 * 1e5 + 1;
int main() {
  long long q;
  cin >> q;
  vector<long long> v(N);
  for (int i = 0; i <= N; i++) {
    v[i] = i;
  }
  deque<long long> dq;
  vector<pair<long long, long long>> pq(q);
  long long idx = 0;
  while (q--) {
    long long a;
    cin >> a;
    if (a == 1) {
      long long b;
      cin >> b;
      pq[idx].first = b;
      pq[idx].second = 0;
      idx++;
    } else {
      long long b, c;
      cin >> b >> c;
      pq[idx].first = b;
      pq[idx].second = c;
      idx++;
    }
  }
  for (int i = idx - 1; i >= 0; i--) {
    if (pq[i].first != 0 && pq[i].second != 0) {
      v[pq[i].first] = v[pq[i].second];
    } else {
      dq.push_front(v[pq[i].first]);
    }
  }
  for (auto it : dq) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
