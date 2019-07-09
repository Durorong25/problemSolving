#include <iostream>
#include <vector>
#include <algorithm>
  
using namespace std;
  
int main() {
    int T, N, a, track, count;
    bool dup;
    vector<int>::iterator it;
    vector<int> A;
    cin>>T;
  
    for(int i=0; i<T; i++){
        cin>>N;
        A.clear();
        for(int j=0; j<N; j++){
            cin>>a;
            A.push_back(a);
        }
        sort(A.begin(), A.end());
 
        count = 0;
        for(int j=0; j<A.size()-1; j++){
            track=A.at(j);
            dup=true;
            for(int k=j+1; k<A.size(); k++){
                if(track==A.at(k)){
                    dup=!dup;
                    if(k==A.size()-1){
                        j=k-1;
                        count+=dup;
                    }
                }
                else{
                    j=k-1;
                    count+=dup; 
                    break;
                }
            }
             
        }
 
        if(A.at(A.size()-1)!=A.at(A.size()-2)) count++;
        cout<<"#"<<i+1<<" "<<count<<'\n';
    }
      
    return 0;
}