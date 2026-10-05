class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //find the max element of all the piles
        int n = piles.size();
        int maxelem = 0;
        
        cout<<maxelem<<endl;
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int mid = (l+r)/2;
        
        while(l<=r){
            cout<<"mid elem = "<<mid<<endl;
            int hrs = 0;
            for(int i = 0;i<n;i++){
                if(piles[i]%mid==0) hrs+=(piles[i]/mid);
                else hrs += ((piles[i]/mid) + 1);
            }
            cout<<"Total hrs = "<<hrs<<endl;
            if(hrs<=h) r = mid -1;
            else{
                l = mid+1;
            }
            
            mid = (l+r)/2;
        }

        return mid+1;
        
       
        
    }
};
