#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class PrefixMatcherTrieNode {
 public:
  unordered_map<char, PrefixMatcherTrieNode*> children;
  int routerNumber;

  PrefixMatcherTrieNode() { routerNumber = -1; };
};

class PrefixMatcher {
 private:
  PrefixMatcherTrieNode* root;

 public:
  PrefixMatcher() : root(new PrefixMatcherTrieNode()) {}

  void insert(string address, int routerNumber) {
    PrefixMatcherTrieNode* node = root;
    for (char bit : address) {
      if (node->children.count(bit) == 0) {
        node->children[bit] = new PrefixMatcherTrieNode();
      }
      node = node->children[bit];
    }
    node->routerNumber = routerNumber;
  }

  int selectRouter(string networkAddress) {
    PrefixMatcherTrieNode* node = root;
    int longestMatchRouter = -1;
    for (char bit : networkAddress) {
      if (node->routerNumber != -1) {
        longestMatchRouter = node->routerNumber;
      }
      if (node->children.find(bit) == node->children.end()) {
        break;
      }
      node = node->children[bit];
    }
    return longestMatchRouter;
  }
};