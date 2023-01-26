#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N];
void solve() {
  int n, k;
  cin >> n >> k;
  int a1, a2, a3, o1, o2, o3;
  cout << "and 1 2\n";
  cout.flush();
  cin >> a1;
  cout << "and 1 3\n";
  cout.flush();
  cin >> a2;
  cout << "and 2 3\n";
  cout.flush();
  cin >> a3;
  cout << "or 1 2\n";
  cout.flush();
  cin >> o1;
  cout << "or 1 3\n";
  cout.flush();
  cin >> o2;
  cout << "or 2 3\n";
  cout.flush();
  cin >> o3;
  for (int i = 30; i >= 0; i--) {
    bool b = false;
    if ((1 << i) & a1) a[1] += (1 << i), a[2] += (1 << i), b = true;
    if ((1 << i) & a2) a[1] += (1 << i), a[3] += (1 << i), b = true;
    if ((1 << i) & a3) a[2] += (1 << i), a[3] += (1 << i), b = true;
    if (((1 << i) & a1) && ((1 << i) & a2)) a[1] -= (1 << i);
    if (((1 << i) & a1) && ((1 << i) & a3)) a[2] -= (1 << i);
    if (((1 << i) & a2) && ((1 << i) & a3)) a[3] -= (1 << i);
    if (b) continue;
    if ((1 << i) & o1 && (1 << i) & o2) a[1] += (1 << i);
    if ((1 << i) & o2 && (1 << i) & o3) a[3] += (1 << i);
    if ((1 << i) & o1 && (1 << i) & o3) a[2] += (1 << i);
  }
  for (int i = 4; i <= n; i++) {
    int curr1, curr2;
    cout << "or 1 " << i << "\n";
    cout.flush();
    cin >> curr1;
    cout << "and 1 " << i << "\n";
    cout.flush();
    cin >> curr2;
    for (int j = 30; j >= 0; j--) {
      if ((1 << j) & curr2)
        a[i] += (1 << j);
      else if (((1 << j) & curr1) && !(a[1] & (1 << j)))
        a[i] += (1 << j);
    }
  }
  sort(a + 1, a + 1 + n);
  cout << "finish " << a[k] << "\n";
  cout.flush();
}
int main() { solve(); }
