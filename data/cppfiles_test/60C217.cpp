#include <bits/stdc++.h>
using namespace std;
void solve_here() {
  long long n;
  cin >> n;
  long long a_rr[n];
  long long sum = 0;
  map<int, int> map;
  for (long long i = 0; i < n; i++) {
    cin >> a_rr[i];
    sum += a_rr[i];
  }
  sum *= 2;
  if (sum % n != 0) {
    cout << 0 << "\n";
    return;
  }
  sum /= n;
  long long var = 0;
  for (long long i = 0; i < n; i++) {
    long long tmp = sum - a_rr[i];
    var += map[tmp];
    map[a_rr[i]]++;
  }
  cout << var << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test_case;
  cin >> test_case;
  while (test_case--) {
    solve_here();
  }
}
