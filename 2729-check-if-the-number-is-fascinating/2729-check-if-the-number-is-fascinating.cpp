class Solution {
public:
    bool isFascinating(int n) {
        string number = to_string(n) + to_string(2*n) + to_string(3*n);
        sort(number.begin(),number.end());
        return number == "123456789";
    }
};