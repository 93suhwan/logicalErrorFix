#include <bits/stdc++.h>
using namespace std;
void ppp(priority_queue<pair<long long, long long>> pq) {
  cout << "printing"
       << "\n";
  while (!pq.empty()) {
    cout << pq.top().first << " " << pq.top().second << "\n";
    pq.pop();
  }
  cout << "-done-"
       << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    priority_queue<pair<long long, long long>> pq;
    priority_queue<pair<long long, long long>> pq1;
    long long n, m, k;
    cin >> n >> m >> k;
    long long b = n % m;
    long long cb = n / m + 1;
    long long s = m - b;
    long long cs = n / m;
    for (long long i = 0; i < n; i++) {
      pq.push({0, i});
    }
    for (long long i = 0; i < k; i++) {
      for (long long j = 0; j < s; j++) {
        cout << cs << " ";
        long long uu = cs;
        while (uu) {
          pair<long long, long long> y = pq.top();
          pq.pop();
          cout << y.second + 1 << " ";
          pq1.push({y.first, y.second});
          uu--;
        }
        cout << "\n";
      }
      for (long long j = 0; j < b; j++) {
        cout << cb << " ";
        long long uu = cb;
        while (uu) {
          pair<long long, long long> y = pq.top();
          pq.pop();
          cout << y.second + 1 << " ";
          pq1.push({y.first + 1, y.second});
          uu--;
        }
        cout << "\n";
      }
      pq = pq1;
      pq1 = priority_queue<pair<long long, long long>>();
    }
    cout << "\n";
  }
}
