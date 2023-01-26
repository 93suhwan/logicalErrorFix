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
    int n,i,j,k,ma1=0,ma2=0,i1,i2;
    string s;
    vector<int>v1,v2;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        v1.push_back(k);
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
    }
    for(i=0;i<n;i++){
        if(v1[i1]<=v1[i] || v2[i1]<=v2[i] || v1[i2]<=v1[i] || v2[i2]<=v2[i]){
            s.push_back('1');
        }
        else{
            s.push_back('0');
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