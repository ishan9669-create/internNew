#include<iostream>
#include<vector>
#include<map>
using namespace std;
void f(int Xor,vector<int>&arr,vector<int>temp,int i,map<int,vector<vector<int>>>&mpp){

    if(i>=arr.size()) {
        if(mpp.size()==0) {
            mpp[Xor].push_back(temp);
            return ;
        }

       mpp[Xor].push_back(temp);
        return ;
    }

    temp.push_back(arr[i]);
    Xor = Xor^arr[i];
    f(Xor,arr,temp,i+1,mpp);

    Xor = Xor^temp[temp.size()-1];
    temp.pop_back();
    f(Xor,arr,temp,i+1,mpp);
}
int main(){
    vector<int> arr= {2,2,2,2};
   
    map<int,vector<vector<int>>> mpp;

    f(0,arr,{},0,mpp);
    for(auto itr=mpp.begin();itr!=mpp.end();itr++){
        
        cout<<"First->"<<itr->first<<endl;
            for(auto i:itr->second){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    
     
        }
    cout<<"Next"<<endl;
   
    }
    
    return 0;
}