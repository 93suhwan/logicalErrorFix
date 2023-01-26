#include <bits/stdc++.h>
using namespace std;
template <typename T>
void prll_vector(vector<T> path) {
  copy(path.begin(), path.end(), ostream_iterator<T>(cout, " "));
  cout << endl;
}
template <typename T>
void prll_array(T a, long long n) {
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
vector<long long> take_input(long long n) {
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  return v;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    vector<long long> a = take_input(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
