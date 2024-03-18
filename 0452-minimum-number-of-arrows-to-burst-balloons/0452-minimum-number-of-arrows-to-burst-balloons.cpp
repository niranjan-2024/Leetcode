class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        int last_arrow_index = 0;

        sort(points.begin(),points.end(),cmp);

        for(int i=0;i<points.size();i++){
            if(ans==0 || last_arrow_index < points[i][0]){
                ans++;
                last_arrow_index = points[i][1];
            }
        }

        return ans;
    }
};