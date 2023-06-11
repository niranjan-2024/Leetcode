class SnapshotArray {
public:
    vector<vector<pair<int,int>>>v;
    int t=0;
    SnapshotArray(int length) {
        v.resize(length);
        for(int i=0; i< length;++i){
            v[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        int n = v[index].size();
        int a = v[index][n-1].first;
        if(a==t){
            v[index][n-1].second = val;
        }else{
            v[index].push_back({t,val});
        }
    }
    
    int snap() {
        return t++;
    }
    
    int get(int index, int snap_id) {
        int i=0,j=v[index].size()-1;
        while(i <= j){
            int m = i + (j - i)/2;
            if(v[index][m].first < snap_id){
                i = m+1;
            }else if(v[index][m].first > snap_id){
                j = m-1;
            }else{
                return v[index][m].second;
            }
        }
        return v[index][j].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */