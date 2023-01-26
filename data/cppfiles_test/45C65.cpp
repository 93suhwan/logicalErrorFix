#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int xorTillN(int n) {
  if (n % 4 == 0) {
    return n;
  } else if (n % 4 == 1) {
    return 1;
  } else if (n % 4 == 2) {
    return n + 1;
  } else if (n % 4 == 3) {
    return 0;
  }
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int n;
  cin >> n;
  int arr[n];
  int h = 1;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long i = 0; i < n; i++) {
    if (i != 0) {
      if (arr[i] == 0 && arr[i - 1] == 0) {
        cout << -1 << endl;
        return;
      } else if (arr[i] == 0 && arr[i - 1] == 0) {
        h = h;
      } else if (arr[i] == 1 && arr[i - 1] == 1) {
        h += 5;
      } else if (arr[i] == 1 && arr[i - 1] == 0) {
        h++;
      }
    }
  }
  if (arr[0] == 1) {
    h++;
  }
  cout << h << endl;
}
int main() {
  fast();
  {
    int t;
    cin >> t;
    while (t--) {
      solve();
    }
    return 0;
  }
}
