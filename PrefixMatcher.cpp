#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

#include "PrefixMatcher.h"

PrefixMatcherTrieNode::PrefixMatcherTrieNode() { routerNumber = -1; };

PrefixMatcher::PrefixMatcher() : root(new PrefixMatcherTrieNode()) {};

void PrefixMatcher::insert(string address, int routerNumber) {
  PrefixMatcherTrieNode* node = root;
  for (char bit : address) {
    if (node->children.count(bit) == 0) {
      node->children[bit] = new PrefixMatcherTrieNode();
    }
    node = node->children[bit];
  }
  node->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress) {
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