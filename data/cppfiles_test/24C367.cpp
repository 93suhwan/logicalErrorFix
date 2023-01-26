#include <bits/stdc++.h>
using namespace std;
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
template <typename T>
void print(const T &t) {
  cout << t << '\n';
}
template <typename T, typename... F>
void print(const T &t, const F &...f) {
  cout << t << " ";
  print(f...);
}
template <typename T>
void input_array(vector<T> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
}
template <typename T>
void print_array(const T &arr, char c = ' ') {
  for (auto x : arr) {
    cout << x << c;
  }
  cout << '\n';
}
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  file_i_o();
  startTime = clock();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = n / 10;
    if (n % 10 == 9) {
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
