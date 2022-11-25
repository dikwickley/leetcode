class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        set<string> visited;
        set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> que;
        
        que.push({beginWord, 0});
        
        while(!que.empty()){
            
            string word = que.front().first;
            int dist = que.front().second;
            que.pop();
            
            if(word == endWord) return dist+1;
            
            for(int i=0;i<word.size();i++){
                for(int j=0;j<26;j++){
                    if(word[i] != 'a' + j){
                        string new_word = word;
                        new_word[i] = 'a'+j;
                        if(words.count(new_word)!=0 && visited.count(new_word)==0){
                            visited.insert(new_word);
                            que.push({new_word, dist+1});
                        }
                    }
                    
                }
            }
        }
        return 0;
    }
};