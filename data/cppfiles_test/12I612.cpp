#include <bits/stdc++.h>
using namespace std;
void swap(long long int &x, long long int &y) {
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
}
template <typename T>
void print(T a) {
  for (auto i = a.begin(); i != a.end(); i++) cout << *i << " ";
  cout << endl;
}
bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  return false;
}
void sync() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  sync();
  long long int t;
  cin >> t;
  for (long long int testcase = 1; testcase <= t; testcase++) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (m % 2) {
      long long int mx = (m / 2) * n;
      if (k % 2 == 0 && (k <= mx))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (n % 2) {
        long long int o = m / 2;
        if (k == 0)
          cout << "NO" << endl;
        else if (k % o != 0)
          cout << "NO" << endl;
        else {
          k /= o;
          if (k % 2)
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        }
      } else {
        if (k % 2 == 0)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
    }
  }
}
