  #include <vector>
  #include <iostream>
  #include <stack>
  #include <queue>
  #include <cmath>
  #include <algorithm>
  #include <string>
  #include <set>
  #include <map>
  #include <bitset>
  #include <climits>
  #define forloop(i,s,e) for(int i=s;i<=e;i++)
  #define MOD 1000000007
  using ll = long long;
  using namespace std;

  int main(){
    int t;
    cin>>t;
    while(t--){
      int m;cin>>m;
      ll a[2][100001]={0};
      forloop(i,0,m-1){
        cin>>a[0][i];
      }
      forloop(i,0,m-1){
        cin>>a[1][i];
      }
      ll prefixsum[m]={0};
      prefixsum[0]=a[1][0];
      ll suffixsum[m]={0};
      forloop(i,1,m-1){
        prefixsum[i]=prefixsum[i-1]+a[1][i];
      }
      suffixsum[m-1]=a[0][m-1];
      for(int i=m-2;i>=0;i--){
        suffixsum[i]=suffixsum[i+1]+a[0][i];
      }
      ll minlength=LLONG_MAX;
      forloop(i,0,m-1){
        if(i==0){
          minlength=min(minlength,suffixsum[i+1]);
        }
        else if(i==m-1){
          minlength=min(minlength,prefixsum[i-1]);
        }
        else minlength=min(max(suffixsum[i+1],prefixsum[i-1]),minlength);
      }
      cout<<minlength<<"\n";
    }



  return 0;
}
