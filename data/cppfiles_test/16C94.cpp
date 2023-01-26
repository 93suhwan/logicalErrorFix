#include <bits/stdc++.h>
using namespace std;
void yn(bool b1) { cout << (b1 ? "YES\n" : "NO\n"); }
long long fact1(long long m1) {
  return m1 == 0 || m1 == 1 ? 1 : m1 * fact1(m1 - 1);
}
bool sbs(const pair<long long, long long> &pa1,
         const pair<long long, long long> &pa2) {
  return (pa1.second < pa2.second);
}
long long pow1(long long m1, long long m2) {
  if (!m2)
    return 1;
  else if (!(m2 % 2))
    return pow1(m1, m2 / 2) * pow1(m1, m2 / 2);
  else
    return m1 * pow1(m1, m2 / 2) * pow1(m1, m2 / 2);
}
vector<bool> sieveOfEratosthenes(long long m1) {
  vector<bool> res(m1 + 1, 1);
  for (long long i = 2; i < sqrt(m1) + 1; i++) {
    if (res[i])
      for (long long j = i * i; j < m1 + 1; j++) {
        res[j] = 0;
        j += i - 1;
      }
  }
  return res;
}
void solution() {
  long long n;
  cin >> n;
  vector<vector<long long>> res;
  priority_queue<pair<long long, long long>> pq1;
  for (long long i = 0; i < n; i++) {
    long long temp1;
    cin >> temp1;
    if (temp1) pq1.push({temp1, i + 1});
  }
  while (pq1.size() > 1) {
    pair<long long, long long> p1 = pq1.top();
    pq1.pop();
    pair<long long, long long> p2 = pq1.top();
    pq1.pop();
    res.push_back({p1.second, p2.second});
    p1.first--;
    p2.first--;
    if (p1.first) pq1.push(p1);
    if (p2.first) pq1.push(p2);
  }
  cout << res.size() << "\n";
  for (long long i = 0; i < res.size(); i++) {
    for (long long c1 = 0; c1 < res[i].size(); c1++) cout << res[i][c1] << " ";
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solution();
}
