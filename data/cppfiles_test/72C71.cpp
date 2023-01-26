#include <bits/stdc++.h>
const int N = 2e5 + 100;
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
bool func(string num, int k) {
  set<char> s;
  for (int i = 0; i < num.length(); i++) {
    s.insert(num[i]);
  }
  if (s.size() <= k) {
    return false;
  } else {
    return true;
  }
}
int main() {
  file_i_o();
  startTime = clock();
  int t;
  cin >> t;
  while (t--) {
    string n;
    int k;
    cin >> n >> k;
    while (true) {
      set<char> s;
      for (auto c : n) s.insert(c);
      if (s.size() <= k) break;
      s.clear();
      int ptr = 0;
      for (;; ptr++) {
        s.insert(n[ptr]);
        if (s.size() > k) {
          while (n[ptr] == '9') ptr--;
          n[ptr]++;
          for (int i = ptr + 1; i < n.size(); i++) n[i] = '0';
          break;
        }
      }
    }
    cout << n << "\n";
  }
  return 0;
}
