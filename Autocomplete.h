#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
 public:
  bool is_end_word = false;
  unordered_map<char, TrieNode*> children;
};

class Autocomplete {
 private:
  TrieNode* root;

 public:
  Autocomplete();
  void insert(string key);
  void findAllWords(TrieNode* node, string prefix, vector<string>& foundWords);
  vector<string> getSuggestions(string prefix);
};