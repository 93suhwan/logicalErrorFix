#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using multi_ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;



int main(){
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 int t; cin>>t;
 
 while(t--){

int n; cin>>n; char c; cin>>c; string s; cin>>s;

int ct=0; int ct2=0;

for(int i=0;i<n;i++){
  if(s[i] != c){ct++; break;}
 // ct2++;
}
   
if(ct==0){ cout<<0<<'\n'; continue;}
if(s[n-1]==c){ cout<<1<<'\n'<<n<<'\n'; continue;}

for(int i=0;i<n;i++){
  
  if(s[i] != c){ ct2++;}
  
}

if(ct2==n){cout<<2<<'\n'; cout<<n<<" "<<n-1<<'\n'; continue;}

vector <int> v;

for(int i=0;i<n;i++){
  if(s[i]==c){v.push_back(i+1);}
}

int flag = 1; int idx = 0;

for(int i=0;i<(int)v.size();i++){
  
  int x = v[i]; int ct=2; int j = x*ct;
  
  while(j<=n){
    if(s[j-1] != c){flag = 3; break;}
    ct++; j = ct*x;
  }
  
  if(flag != 3){flag=2; idx = v[i]; break;}
  
}

if(flag==2){ //cout<<"here"<<'\n';
  cout<<1<<'\n'; cout<<idx<<'\n';
}

else{
  cout<<2<<'\n'; cout<<n<<" "<<n-1<<'\n';
}

    
  
}  
 
    return 0;
}