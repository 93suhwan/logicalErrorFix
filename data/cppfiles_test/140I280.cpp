#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int tx[] = {-1, 0, 1, 0};
int ty[] = {0, 1, 0, -1};
void Madaa() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int main() {
  cout << fixed << setprecision(0);
  ;
  Madaa();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << (long long)(sqrt(n)) + (long long)(pow(n * 1.0L, 1.0L / 3)) -
                (long long)(pow(n * 1.0L, 1.0L / 6))
         << "\n";
  }
}
