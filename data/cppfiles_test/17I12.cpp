#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type,
  less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
  OrdStat;

void processor()
{
  int n; cin >> n;
  vector<int> arr(n);
  OrdStat sorted;
  for(int i = 0; i < n; i++)
  {cin >> arr[i];}
  long long output = 0;
  map<int, int> hmap;
  for(int i = 0; i < n; i++)
  {
    hmap[arr[i]]++;
    sorted.insert(pair<int, int>(arr[i], 0));
    int left = sorted.order_of_key(pair<int, int>(arr[i], 0));
    int right = i - left - hmap[arr[i]] + 1;
    output += min(left, right);
  }
  cout << output << endl;
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int count, counter = 0;
  cin >> count;
  while(counter++ < count)
  {processor();}
  return 0;
}
//Programming isn't about what you know;
//it's about what you can figure out.
