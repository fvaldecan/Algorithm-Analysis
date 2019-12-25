#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <ctype.h>
#include <bits/stdc++.h>
#include <sstream>
//#include <iteratnderor>
#include <algorithm>


using namespace std;

vector<string>autoList;
vector<string>autoBSTList;
//used to get all the nodes for space complexity
int total,bstTotal = 0;
//----------------------------Trie-----------------------------------
// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 
  
// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isWordEnd is true if the node represents 
    // end of a word 
    bool isWordEnd; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode = new TrieNode; 
    pNode->isWordEnd = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 

    total++;
    return pNode; 
} 
  
// If not present, inserts key into trie.  If the 
// key is prefix of trie node, just marks leaf node 
void insert(struct TrieNode *root,  const string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int level = 0; level < key.length(); level++) 
    { 
        int index = CHAR_TO_INDEX(key[level]); 
        if (!pCrawl->children[index]) {
            total++;
            pCrawl->children[index] = getNode();
        }
        total++;
        pCrawl = pCrawl->children[index]; 
    } 
    total++;
    // mark last node as leaf 
    pCrawl->isWordEnd = true; 
} 
  
// Returns true if key presents in trie, else false 
bool search(struct TrieNode *root, const string key) 
{ 
    int length = key.length(); 
    struct TrieNode *pCrawl = root; 
    for (int level = 0; level < length; level++) 
    { 
        int index = CHAR_TO_INDEX(key[level]); 
  
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isWordEnd); 
} 
  
// Returns 0 if current node has a child 
// If all children are NULL, return 1. 
bool isLastNode(struct TrieNode* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return 0; 
    return 1; 
} 
  
// Recursive function to print auto-suggestions for given 
// node. 
void suggestionsRec(struct TrieNode* root, string currPrefix) 
{ 
    // found a string in Trie with the given prefix 
    if (root->isWordEnd) 
    { 
      //cout << currPrefix;
      //cout << endl;
        autoList.push_back(currPrefix); 
    } 
  
    // All children struct node pointers are NULL 
    if (isLastNode(root)) 
        return; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    { 
        if (root->children[i]) 
        { 
            // append current character to currPrefix string 
            currPrefix.push_back(97 + i);
	     
            // recur over the rest 
            suggestionsRec(root->children[i], currPrefix);
	    currPrefix.pop_back();
        } 
    } 
} 
  
// print suggestions for given query prefix. 
int printAutoSuggestions(TrieNode* root, const string query) 
{ 
    struct TrieNode* pCrawl = root;
     
    // Check if prefix is present and find the 
    // the node (of last level) with last character 
    // of given string. 
    
    int n = query.length();
    //cout << "query length is: " << n << endl;
    for (int level = 0; level < n; level++) 
    { 
        int index = CHAR_TO_INDEX(query[level]); 
  
        // no string in the Trie has this prefix 
        if (!pCrawl->children[index]) 
            return 0; 
  
        pCrawl = pCrawl->children[index];

    } 
  
    // If prefix is present as a word. 
    bool isWord = (pCrawl->isWordEnd == true); 
  
    // If prefix is last node of tree (has no 
    // children) 
    bool isLast = isLastNode(pCrawl); 
  
    // If prefix is present as a word, but 
    // there is no subtree below the last 
    // matching node. 
    if (isWord && isLast) 
    { 
        cout << query << endl; 
        return -1; 
    } 
  
    // If there are are nodes below last 
    // matching character. 
    if (!isLast) 
    { 
        string prefix = query; 
        suggestionsRec(pCrawl, prefix); 
        return 1; 
    } 
} 
  
  
//-------------------------End Trie--------------------------------
///////////// Binary Search Tree/ Binary Trie Tree/ Trienary Tree/ Binaryception Tree////////

struct BSTNode{
    bool endOfWord;
    BSTNode *right;
    BSTNode *left;
    BSTNode*next;
    char value;
};
struct BSTNode *getBSTNode(void)
{
    struct BSTNode *node = new BSTNode;
    node->right = nullptr;
    node->left = nullptr;
    node->endOfWord = false;
    return node;
}

bool searchBSTNode(BSTNode*root, char key);
BSTNode * insertBSTNode(BSTNode *root, const char &key);
BSTNode* traverseBST(BSTNode*root, const char &key);
void findResults(BSTNode*root, string&key, string&result);
void insertBST(struct BSTNode*root, const string& key){
    struct BSTNode *travelBST = root;
    for(int i = 0; i < key.length();i++){
        //Check if the letter is in the tree
        if(!searchBSTNode(travelBST,key[i])) {
            //Inserts new node
            travelBST = insertBSTNode(travelBST, key[i]);
            //Traverses to that Node
            travelBST = traverseBST(travelBST,key[i]);
            //Traverses to next BST
            travelBST = travelBST->next;
            //Make true at end of each word
            if(i == key.length()-1)
                travelBST->endOfWord = true;
        }else{//If the letter is in the tree travel to that node
            travelBST = traverseBST(travelBST,key[i]);
            //Traverses to next BST
            travelBST = travelBST->next;
        }
    }
}
bool searchBST(BSTNode*root,const string&key){
    struct BSTNode *finder = root;
    for(char i : key) {
        if(!searchBSTNode(root,i)) return false;
        else{
            finder = traverseBST(finder,i);
            finder = finder->next;
        }
    }
    return true;
}
BSTNode* traverseBST(BSTNode*root,const char& key){
    if(root == nullptr)
        return root;
    if (root->value == key)
        return root;
    if (root->value < key)
        return traverseBST(root->right, key);
    else if(root->value > key)
        return traverseBST(root->left, key);
}
BSTNode* insertBSTNode(BSTNode *root, const char &key) {
    if(root->next == nullptr){
        root->left = getBSTNode();
        root->right = getBSTNode();
        root->next = getBSTNode();
        root->value = key;
        bstTotal++;
        return root;
    }
    else if(root->value < key)
        root->right = insertBSTNode(root->right, key);
    else if(root->value > key)
        root->left = insertBSTNode(root->left,key);
    return root;
}
bool searchBSTNode(BSTNode*root, char key){
    if(root == nullptr)
        return false;
    if (root->value == key)
        return true;
    if (root->value < key)
        return searchBSTNode(root->right, key);
    else if(root->value > key)
        searchBSTNode(root->left, key);
    else return false;
}
void getWord(BSTNode*root, string&key,string&result){
    BSTNode*traverseWord = root;
    while(!traverseWord->next->endOfWord){
        result +=traverseWord->value;
        traverseWord = traverseWord->next;
    }
    result += traverseWord->value;
    autoBSTList.push_back(result);
}
void findResults(BSTNode*root, string&key, string&result){
    if(root->next==nullptr)
        return;
    //BSTNode*finder = root;
    findResults(root->left,key,result);
    getWord(root,key,result);
    result = key;
    findResults(root->right,key,result);
}
void printResult(BSTNode*root, string&key){
    struct BSTNode *finder = root;
    string result = key;
    for(char i : key) {
        finder = traverseBST(finder,i);
        finder = finder->next;
    }
    findResults(finder,key,result);
}
///////////// Binary Search Tree/ Binary Trie Tree/ Trienary Tree/ Binaryception Tree////////

int main(int argc, char*argv[])
{
  // For flags
  int flag = atoi(argv[2]);

    
  //variables and data bucket to be used
  ifstream input; string filename; string word; char c; vector<string>words;
  int n = 0;

  //User inputs file name and opens it
  //cout<<"Enter the file name: ";
  filename = argv[1];
  input.open(filename.c_str());

  while (input.get(c)){
    //if a character is a letter and if check whether its upper or lowercase, concatenate
    //it with other letters
    if (isalpha(c)){
      if(isupper(c)){
	c = tolower(c);
	word += c;
      }
      else{
	word += c;
      }
    }
    //if character is a given symbol, do nothing
    //probably not needed
    else if (c == ',' || c == '.' || c == ':' || c == ';' || c == '?'){
    }

    //if a character is a space or end of line
    //make word equal empty string
    else if (c == ' ' || c == '\n'){

      words.push_back(word);
      n++;
      word = "";
    }

  }

  //n is word count making an array of strings of size n
  //convert vector to array
  /*string keys[n];
  for (int i = 0; i < words.size(); i++) {
    keys[i] = words.at(i);
  }*/

  
  //prints array for debugging
  /*for(int i = 0; i < n; i++){
  cout << keys[i] << endl;
  }*/

  struct TrieNode *root = getNode();
  struct BSTNode *bstRoot = getBSTNode();
  // Construct trie
  clock_t start, end, start2, end2;

  //calculating time(start)
  start = clock();

  for (int i = 0; i < n; i++) {
    //cout << keys[i] << endl;
    insert(root, words.at(i));
  }

  //(end)
  end = clock();
  start2 = clock();
  for(int j = 0; j < n; j++){
      insertBST(bstRoot,words.at(j));
  }
  end2 = clock();
  
  double trieTime = ((double) (end - start)) / CLOCKS_PER_SEC;
  double bstTime = ((double) (end2 - start2)) / CLOCKS_PER_SEC;

  // Search for different keys
  //search(root, "ass")? cout << "Yes\n" : cout << "No\n";
  //search(root, "is")? cout << "Yes\n" : cout << "No\n";
  cout << "Time taken to build the standard Trie is " << flush;
  cout << trieTime << flush;
  cout << " and space occupied by it is " << flush;
  cout << total << endl << endl;
  //cout << " and space occupied by it is\n";
  //cout << endl;

  cout << "Time taken to build the standard BST is " << flush;
  cout << bstTime << flush;
  cout << " and space occupied by it is " << flush;
  cout << bstTotal << endl << endl;

  //Find all occurance with a user specified prefix
  if(flag == 1){
    
    string userString;
    //bool used to stop the do while, if using only "0" it will seg fault
    bool ans = true;
    do{
      cout << "Enter search string(enter 0 to exit): ";
      cin >> userString;
      if (userString == "0")
	ans = false;

      else{
	//Standard search for the string
	clock_t start, end;
	start = clock();
	search(root, userString);
	//end time for standard search
	end = clock();
	double searchTime = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Time taken to search in the standard Trie is " << flush;
	cout << searchTime << endl;
	//start time auto complete
	start = clock();
	int comp = printAutoSuggestions(root, userString);
	//end time to auto complete
	end = clock();
	double autoTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    //start time BST auto complete
    start2 = clock();
    printResult(bstRoot,userString);
    //end time to auto complete
    end2 = clock();
    double autoTime2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
	if(comp == -1)
	  cout << "No other strings found with prefix" << endl;

	else if(comp == 0)
	  cout << "No strings found with this prefix" << endl;

	else if(comp == 1){
        //printing the words found with commas
        cout << "Auto-complete results using standard Trie are: " << flush;
        for (auto iter = autoList.begin(); iter != autoList.end(); iter++) {
            if (iter != autoList.begin()) cout << ", ";
            cout << *iter;
        }
        cout << endl;

        cout << "Auto-complete results using standard BST are: " << flush;
        for (auto iter = autoBSTList.begin(); iter != autoBSTList.end(); iter++) {
            if (iter != autoBSTList.begin())
                cout << ", ";
            cout << *iter;
        }
    }
	//clearing the list for the next search
    autoBSTList.clear();
	autoList.clear();
	cout << endl;
	//printing the time taken
	cout << "Time taken to find auto-complete results in the standard Trie is " << flush;
	cout << autoTime << endl << endl;
    cout << "Time taken to find auto-complete results in the standard BST is " << flush;
	cout << autoTime2 << endl << endl;
    }
    

    }while(ans == true);
    
  }
  else{ //flag == 2
    //To search all the keys, no reason to change
    clock_t searchStart, searchEnd;
    searchStart = clock();
    for(int i = 0; i < n; i++)
      search(root,words.at(i));
    searchEnd = clock();
    double searchTime = ((double) (searchEnd - searchStart)) / CLOCKS_PER_SEC;
    cout << "Time taken to search all the strings in the standard Trie is ";
    cout << searchTime << endl;
  }
  return 0;
}