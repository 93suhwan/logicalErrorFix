#include <bits/stdc++.h>
bool compare(std::string& a, std::string& b) {
  for (int i = 0; i < a.size(); ++i) {
    if (i % 2) {
      if (std::tolower(a[i]) > std::tolower(b[i])) {
        return true;
      }
      if (std::tolower(a[i]) < std::tolower(b[i])) {
        return false;
      }
    } else {
      if (std::tolower(a[i]) < std::tolower(b[i])) {
        return true;
      }
      if (std::tolower(a[i]) > std::tolower(b[i])) {
        return false;
      }
    }
  }
  return false;
}
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<std::string, int>> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i].first;
    arr[i].second = i + 1;
  }
  std::sort(arr.begin(), arr.end(),
            [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
              return compare(a.first, b.first);
            });
  for (std::pair<std::string, int>& a : arr) {
    std::cout << a.second << '\n';
  }
}
