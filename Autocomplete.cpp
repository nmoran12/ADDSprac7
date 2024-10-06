#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
  bool is_end_word = false;
};

class Autocomplete {
 private:
  TrieNode* root;

  void findAllWords(TrieNode* node, string prefix, vector<string>& foundWords) {
    if (node->is_end_word) {
      foundWords.push_back(prefix);
    }

    for (auto child : node->children) {
      findAllWords(child.second, prefix + child.first, foundWords);
    }
  }

 public:
  Autocomplete() { root = new TrieNode(); }

  void insert(string key) {
    TrieNode* node = root;
    for (char letter : key) {
      if (!node->children[letter]) {
        node->children[letter] = new TrieNode;
      }
      node = node->children[letter];
    }
    node->is_end_word = true;
  }

  vector<string> search(string prefix) {
    TrieNode* node = root;
    for (char letter : prefix) {
      auto it = node->children.find(letter);
      if (it == node->children.end()) {
        return {};
      }
      node = node->children[letter];
    }
    vector<string> autocompletedWords;
    findAllWords(node, prefix, autocompletedWords);
    return autocompletedWords;
  }
};