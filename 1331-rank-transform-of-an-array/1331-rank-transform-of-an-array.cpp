class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy=arr;
        sort(copy.begin(),copy.end());
        unordered_map<int,int> mp;
        vector<int> res;
        int i=0;
        int rank = 1;
        while(i<copy.size()){
            if(i-1>=0 && copy[i-1]==copy[i]){
                while(i>0 && i<copy.size() && copy[i-1]==copy[i]){
                    mp[copy[i]]=mp[copy[i-1]];
                    i++;
                }
            }
            else{
                mp[copy[i]]=rank++;
                i++;
            }
        }
        for(int i=0;i<arr.size();i++){
            res.push_back(mp[arr[i]]);
        }
        return res;
    }
};