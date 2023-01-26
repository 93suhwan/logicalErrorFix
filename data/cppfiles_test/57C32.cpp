#include <bits/stdc++.h>
using namespace std;
long long a[2500];
vector<long long> answer;
long long find(long long v) {
  for (register long long i = 1;; i++)
    if (a[i] == v) return i;
  return -1;
}
void reverse(long long p) {
  if (p == 1) return;
  reverse(a + 1, a + p + 1);
  answer.push_back(p);
  return;
}
void work(void) {
  long long n;
  cin >> n;
  for (register long long i = 1; i <= n; i++) cin >> a[i];
  for (register long long i = 1; i <= n; i++)
    if (a[i] % 2 != i % 2) return cout << -1 << endl, void();
  answer.clear();
  for (register long long i = n; i > 1; i -= 2) {
    if (a[i] == i && a[i - 1] == i - 1) continue;
    long long p = find(i);
    reverse(p);
    p = find(i - 1);
    reverse(p - 1);
    reverse(p + 1);
    reverse(3);
    reverse(i);
  }
  cout << answer.size() << endl;
  for (vector<long long>::iterator i = answer.begin(); i != answer.end(); i++)
    cout << *i << ' ';
  cout << endl;
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  long long _ = 1;
  cin >> _;
  while (_--) work();
  return 0;
}
