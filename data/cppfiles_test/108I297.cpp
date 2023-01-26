#include<bits/stdc++.h>
using namespace std;

#include <iostream> 
using namespace std; 
  
// Important header files  
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
  
// Declaring ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

typedef long long int ll;


void solve(){
    int n,i,j,k,ma1=0,ma2=0,i1,i2,mn1=0,mn2=0;
    string s;
    vector<int>v1,v2;
    vector<pair<int,int>>a1,a2;
    cin>>n;
    for(i=0;i<n;i++){
        s.push_back('0');
    }
    for(i=0;i<n;i++){
        cin>>k;
        v1.push_back(k);
        a1.push_back({k,i});
        if(ma1<k){
            ma1=k;
            i1=i;
        }
    }
    for(i=0;i<n;i++){
        cin>>k;
        if(ma2<k){
            ma2=k;
            i2=i;
        }
        v2.push_back(k);
        a2.push_back({k,i});
    }
    
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    for(i=0;i<n;i++){
        mn1=max(mn1,v2[a1[i].second]);
        if(v2[i1]<=mn1){
            s[i]='1';
        }
    }
    for(i=0;i<n;i++){
        mn2=max(mn2,v1[a2[i].second]);
        if(v1[i2]<=mn2){
            s[i]='1';
        }
    }
    cout<<s<<endl;
    return;
    
    
}
    
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}