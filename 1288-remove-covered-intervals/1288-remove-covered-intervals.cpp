class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), 
        [](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
            });
        int max_end=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            int e=intervals[i][1];
            if(max_end<e){
                max_end=e;
                cnt++;
            }
        }
        return cnt;
    }
};