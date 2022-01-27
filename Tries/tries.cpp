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
    void reduceStart(){
        cntStartsWith--;
    }
    void reduceEnd(){
        cntEndsWith++;
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
            }
            node = node->get(word[i]);
            node->increaseStart();
        }
        node->increaseEnd();
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

    int countWordsEqualTo(string word){
        Node *node = root;
        for(int i=0;i<word.length();i++){
             if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->cntEndsWith;
    }

    int countWordsStartingWith(string word){
        Node *node = root;
        for(int i=0;i<word.length();i++){
             if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->cntStartsWith;
    }
};

int main(){
    Trie root = Trie();

    string s = "apple";
    root.insert(s);
    root.insert("apple");
    root.insert("app");
    root.insert("apple");
    cout<<root.countWordsEqualTo("app")<<endl;
    cout<<root.countWordsEqualTo("apple")<<endl;
    cout<<root.countWordsStartingWith("app")<<endl;

    return 0;
}
