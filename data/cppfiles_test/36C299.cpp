#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int x, sum = 0, odd;
    vector<pair<long long int, long long int>> v;
    pair<long long int, long long int> pi;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x % 2 != 0) {
        pi.first = x;
        pi.second = i;
      }
      sum += x;
      v.push_back(make_pair(x, i + 1));
    }
    vector<pair<long long int, long long int>>::iterator it;
    it = v.begin() + pi.second;
    if (isPrime(sum)) {
      v.erase(it);
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i].second << " ";
    }
    cout << endl;
  }
  return 0;
}
