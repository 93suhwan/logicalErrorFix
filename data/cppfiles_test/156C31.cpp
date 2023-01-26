#include <bits/stdc++.h>
using namespace std;
void ans() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n);
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  stack<long long int> s;
  for (long long int i = 1; i < n; i++) s.push(a[i] - a[0]);
  long long int count = 0;
  long long int mini = INT_MAX;
  while (!s.empty() and sum > k) {
    mini = min(mini, count + (sum - k + count) / (count + 1));
    sum -= s.top();
    s.pop();
    count++;
  }
  if (sum > k) {
    count += (sum - k + count) / (count + 1);
  }
  cout << min(mini, count) << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    ans();
  }
}
