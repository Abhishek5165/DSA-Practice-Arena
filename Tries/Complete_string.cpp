#include <bits/stdc++.h>

struct Node
{
  Node *Links[26];
  bool flag = false;

  bool containsKey(char ch)
  {
    return Links[ch - 'a'] != NULL;
  }
  void put(char ch, Node *node)
  {
    Links[ch - 'a'] = node;
  }
  Node *get(char ch)
  {
    return Links[ch - 'a'];
  }
  void set()
  {
    flag = true;
  }
  bool getflag()
  {
    return flag;
  }
};

class Trie
{
private:
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }

  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {

      if (!node->containsKey(word[i]))
      {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->set();
  }

  bool EndsWith(string word)
  {
    Node *node = root;

    for (int i = 0; i < word.size(); i++)
    {

      if (node->containsKey(word[i]))
      {
        node = node->get(word[i]);
        if (node->getflag() == false)
        {
          return false;
        }
      }
      else
      {
        return true;
      }
    }
    return true;
  }
};

string completeString(int n, vector<string> &a)
{
  Trie T;
  for (string &word : a)
  {
    T.insert(word);
  }
  string ans = "";

  for (string st : a)
  {
    if (T.EndsWith(st))
    {
      if (st.length() > ans.length())
      {
        ans = st;
      }
      else if (st.length() == ans.length() && st < ans)
      {
        ans = st;
      }
    }
  }

  if (ans == "")
  {
    return "None";
  }
  return ans;
}