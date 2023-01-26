#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_case;
  cin>>test_case;
  while (test_case--){
    long long N,K;
    cin>>N>>K;
    vector<long long>A(N);
    for(auto &i:A)cin>>i;
    long long sum=accumulate(A.begin(),A.end(),0ll);
    if(sum<=K){
      cout<<"0\n";
      continue;
    }
    long long ans=sum-K;
    sort(A.begin(),A.end(),greater{});
    long long T=A.back();
    for(auto &i:A)i-=T;
    long long sa=sum-K;
    for(int i=0;i<N-1;i++){
      A[i+1]+=A[i];
    }
    for(int i=0;i<N-1;i++){
      ans=min(ans,i+1+(sa-A[i]+i+1)/(i+2));
    }
    cout<<ans<<'\n';
  }
}