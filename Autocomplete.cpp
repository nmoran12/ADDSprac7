#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

#include "Autocomplete.h"

Autocomplete::Autocomplete() { root = new TrieNode(); }

void Autocomplete::findAllWords(TrieNode* node, string prefix,
                                vector<string>& foundWords) {
  if (node->is_end_word) {
    foundWords.push_back(prefix);
  }

  for (auto child : node->children) {
    findAllWords(child.second, prefix + child.first, foundWords);
  }
}

void Autocomplete::insert(string key) {
  TrieNode* node = root;
  for (char letter : key) {
    if (!node->children[letter]) {
      node->children[letter] = new TrieNode;
    }
    node = node->children[letter];
  }
  node->is_end_word = true;
}

vector<string> Autocomplete::search(string prefix) {
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
