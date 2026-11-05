class Solution {
public:
bool canship(vector<int>&arr,int mid, int d){
        int capacity=0;
        int day=1;
        for(int i=0;i<arr.size();i++){
            if(capacity+arr[i]<=mid){
                capacity+=arr[i];
            }
            else{

                day++;
                capacity=arr[i];
            }
           
        }
         if(day<=d){
                return true;
            }
            return false;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
         // code here
        int capacity =0;
        int max_capacity=0;
       
        int current_capacity=0;
        for(int i=0;i<weights.size();i++){
            capacity=max(capacity,weights[i]);
            max_capacity+=weights[i];
        }
      current_capacity=capacity;
     
       while(capacity<=max_capacity){
           int mid=(capacity+max_capacity)/2;
           if (canship(weights,mid,days)){
               max_capacity=mid-1;
               
           }
           else{
               capacity=mid+1;
           }
       }
       return capacity;
    }
};