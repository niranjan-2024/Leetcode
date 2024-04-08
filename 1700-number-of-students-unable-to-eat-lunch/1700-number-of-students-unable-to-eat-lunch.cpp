class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> s;

        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }

        for(int i=students.size()-1;i>=0;i--){
            s.push(sandwiches[i]);
        }

        int count = 0;

        while(!q.empty() && count<q.size()){

            if(q.front() == s.top()){
                q.pop();
                s.pop();
                count = 0;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }

        }

        return q.size();
    }
};