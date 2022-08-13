#include<bits/stdc++.h> 
using namespace std;

class SegmentTree(){

   vector<int> seg;
   SegmentTree(int n){
       seg.ressize(4*n+1);
   }
void build(int ind,int low,int high , int arr[])
{
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=low+high/2;

    build(ind*2+1,low,mid,arr );
    
    build(ind*2+2,mid+1,high,arr);

    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

void update(int ind,int low,int high, int i,int val,){
     if(low==high){
         seg[ind]==val;
     }
     int mid=low+high/2;
     if(i<=mid) update(2*ind+1,low,mid,i,val);
     else update(2*ind+2,mod+1,high,i,val );

    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r,)
{
   // no overlap
 
   if(r<low || high<l)   return INT_MAX;

  //complete overlapp
 
   if(low>=l && high<=r)  return seg[ind];

  //partial overlap
    
    int mid=low+high/2;

    int left=query(ind*2+1,low,mid,l,r);
    int right=query(ind*2+2,mid,high,l,r);

    return min(left,right);

    }
};
void solve(){
    int n;
    cin>>n; 
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int seg[4*n];
    build(0,0,n-1,arr,seg);
    int q;
    cin>>q;
    while(q--){
      
        int type;
        cin>>type;
        // type == give min in range
        if(type==1){
             int l,r;
           cin>>l;   cin>>r;
        cout<<query(0,0,n-1,l,r,seg);
        }
        //upadte
        else{
            int i,val;
            cin>>i>>val;
            update(0,0,n-1,i,val,seg);
            arr[i]=val;
        }

       
       
    } 
}
void solve2()
{
    int n1;
    int arr1[];
    cin>>n1;
    for(int i=0;i<n1;i++)  cin>>arr1[i];

}
int main(){
    solve();
}