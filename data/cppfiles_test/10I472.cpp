#include <bits/stdc++.h>
using namespace std;
#define l1 long long int
#define mod 1000000007
#define FORN(n) for(int i=0;i<n;i++)
#define pb push_back
#define vi vector<int>

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//ios_base& scientific (ios_base& str);
int t=1;
cin>>t;
for(int i=0;i<t;i++){
int n,k;
cin>>n>>k;
int a[n];
for (int i = 0; i <n; ++i)
{
    cin>>a[i];
}

map<int , vector<int>> freq;
for (int i = 0; i < n; ++i)
{
    freq[a[i]].push_back(i);
}
int cl[n]={};
map<int , vector<int>>::iterator itr;
vector<int> storage;
for(itr  = freq.begin();itr!=freq.end();itr++){
    if(itr->second.size()>= k){
        for(int i = 1;i<=k;i++){
            cl[(itr->second)[i-1]]=i;
        }
    }
    else{
        for(auto g : itr->second){
            storage.push_back(g);
        }
    if(storage.size()>=k){
        for(int i = 1;i<=k;i++){
            cl[storage[i-1]]=i;
        }
        storage.clear();
    }
    }

}
for(int i =0;i<n;i++)cout<<cl[i]<<" ";
    cout<<endl;





}
return 0;
}

