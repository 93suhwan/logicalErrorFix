/*BISMILLHIR RAHMANIR RAHIM*/
#include<bits\stdc++.h>
using namespace std;
int main()
{
   int y;
   cin>>y;
   while(y--){
       int t,s=0,m=0;
       cin>>t;
       int a[t];
       for(int i=0;i<t;i++)
       cin>>a[i];
       sort(a,a+t);
       for(int i=0;i<t;i++){
           if(a[i+1]>a[i]){
               if(a[i+1]%2==0&&a[i]%2==0){
                   s+=abs(a[i+1]-a[i])-1;
                   
               }
               else
                   s+=abs(a[i+1]-a[i]);
           }
       }
       cout<<s<<endl;
   }
   return 0;
}
//ALHAMDULLILAH
