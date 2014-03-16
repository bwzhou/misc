class Solution {
public:
/*
    void wordBreakHelper(vector<vector<int> > &mark, string s, int start, unordered_set<string> &dict, string buffer, vector<string> &result) {
        if (start == s.size()) {
            result.push_back(buffer);
            return;
        }
        for (auto &next : mark[start]) {
            wordBreakHelper(mark, s, next, dict, buffer + " " + s.substr(start, next - start), result);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<int> > mark(s.size(), vector<int>());
        vector<string> result;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                    mark[i].push_back(j + 1);
                }
            }
        }
        wordBreakHelper(mark, s, 0, dict, "", result);
        return result;
    }
*/
    void collect(vector<list<int>>& mark, int ind, const string& s, 
                string path, vector<string>& result){
        for(auto& stop: mark[ind]){
            string sub=s.substr(ind,stop-ind);
            string newpath=path+(ind==0?sub:" "+sub);
            if(stop==s.length()) result.push_back(newpath);
            else collect(mark,stop,s,newpath,result);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // first calculate all <i, j> pairs that form a word
        vector<list<int>> mark(s.length(),list<int>());
        for(int stop=s.length();stop>=0;stop--){
            if(stop<s.length()&&mark[stop].empty())continue;
            for(int start=stop-1;start>=0;start--)
                if(dict.count(s.substr(start,stop-start)))
                    mark[start].push_back(stop);
        }
        vector<string> result;
        // then recursively find all possible breakings
        collect(mark,0,s,"",result);
        return result;
    }

};