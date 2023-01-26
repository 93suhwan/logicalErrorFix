#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    vector<int> x1;
    vector<int> x2;
    vector<int> y1;
    vector<int> y2;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      x1.push_back(x);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      x2.push_back(x);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      y1.push_back(x);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      y2.push_back(x);
    }
    int maxArea = INT_MIN;
    int minEle = *min_element((x1).begin(), (x1).end());
    int maxEle = *max_element((x1).begin(), (x1).end());
    int area = h * (maxEle - minEle);
    maxArea = max(maxArea, area);
    minEle = *min_element((x2).begin(), (x2).end());
    maxEle = *max_element((x2).begin(), (x2).end());
    area = h * (maxEle - minEle);
    maxArea = max(maxArea, area);
    minEle = *min_element((y1).begin(), (y1).end());
    maxEle = *max_element((y1).begin(), (y1).end());
    area = w * (maxEle - minEle);
    maxArea = max(maxArea, area);
    minEle = *min_element((y2).begin(), (y2).end());
    maxEle = *max_element((y2).begin(), (y2).end());
    area = w * (maxEle - minEle);
    maxArea = max(maxArea, area);
    cout << maxArea << "\n";
  }
  return 0;
}
