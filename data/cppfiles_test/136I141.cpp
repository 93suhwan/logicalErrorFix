#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto& i : a) {
      cin >> i;
      sum += i;
    }
    int p = n * (n + 1) / 2;
    if (sum % p != 0) {
      cout << "NO\n";
      continue;
    }
    sum /= p;
    vector<int> ans(n);
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int temp = a[i] - a[(i + 1) % n] + sum;
      if (temp % n || temp <= 0) {
        cout << "NO\n";
        ok = true;
        break;
      }
      ans[(i + 1) % n] = temp / n;
    }
    if (ok) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto i : ans) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
