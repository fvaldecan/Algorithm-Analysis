#include "Trie.cpp"
using namespace std;

struct BSTNode{
    BSTNode* leftChilid;
    BSTNode* rightChilid;
    TrieNode* next;
    char letter;
};

/*void buildBST(string word){
    for(int i = 0; i < word.length; i++){
        //char c;
    }

}*/