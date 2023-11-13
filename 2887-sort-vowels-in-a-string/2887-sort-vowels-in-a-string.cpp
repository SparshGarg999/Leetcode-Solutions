class Solution {
public:
    bool is(char c) {
    c = tolower(c);
    return c == 'e' || c == 'a' || c == 'u' || c == 'o' || c == 'i';
}
    string solver(string &v, string & rev,int n,int z,int cnt){
            int vowelIndex = 0;
        string ans;
    for (int i = 0; i < n; i++) {
        if (is(rev[i])) {
            rev[i] = v[vowelIndex++];
        }else cnt++;
    }
        if(cnt) z++;
        else cnt++;
           ans = rev;
    return rev;
    }
    void solve(int n, string &rev,string & v,int z,int cnt){
    for (int i = 0; i < n; i++) {
        if (is(rev[i])) {
            v.push_back(rev[i]);
        }
    }
                if(cnt) z++;
        else cnt++;
    }
    string sortVowels(string s) {
            string rev= s;
    int n = rev.size();
        int f= 1, z=0,c=0;
        int cnt=0;
        string vowels;
        if(f){
            cnt++;
            
                solve(n,rev,vowels,z,c);
            if(z) cnt--;
            else cnt++;
    sort(vowels.begin(), vowels.end());
    string str=  solver(vowels,rev,n,z,c);
            return str;
        }else{
                solve(n,rev,vowels,z,c);
    sort(vowels.begin(), vowels.end());
            if(z) cnt--;
            else cnt++;
    string str=  solver(vowels,rev,n,z,c);
            return str;
        }
    
    }
};