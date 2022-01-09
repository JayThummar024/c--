#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;
    int cntEndsWith = 0;
    int cntStartsWith = 0;
    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }
    void put(Node *node , char ch){
        links[ch - 'a'] = node;
    }
    void increaseEnd(){
        cntEndsWith++;
    }
    void increaseStart(){
        cntStartsWith++;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(new Node(),word[i]);
                node->cntStartsWith();
            }
            node = node->get(word[i]);
        }
        node->cntEndsWith();
        node->setEnd();
    }

    bool search(string word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }

};

int main(){
    Trie root = Trie();

    // string s = "apple";
    // root.insert(s);
    // root.insert("app");
    // root.insert("apx");
    // cout<<root.search("apple")<<endl;
    // cout<<root.startsWith("app")<<endl;


    return 0;
}
