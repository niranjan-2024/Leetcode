class Encrypter {
public:
    
    unordered_map<char,string> encryptCode;
    unordered_map<string,int> encryptedCount;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++){
            encryptCode[keys[i]] = values[i];
        }
        for(int i=0;i<dictionary.size();i++){
            encryptedCount[encrypt(dictionary[i])]++;
        }
    }
    
    string encrypt(string word1) {
        string ans = "";
        for(auto c:word1){
            if(!encryptCode.count(c)){
                return "";
            }
            ans += encryptCode[c];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        return encryptedCount[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */