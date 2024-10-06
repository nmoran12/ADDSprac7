#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

class PrefixMatcherTrieNode {
 public:
  int routerNumber = -1;
  unordered_map<char, PrefixMatcherTrieNode*> children;

  PrefixMatcherTrieNode();
};

class PrefixMatcher {
 private:
  PrefixMatcherTrieNode* root;

 public:
  PrefixMatcher();
  void insert(string address, int routerNumber);
  int selectRouter(string networkAddress);
};
