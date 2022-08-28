Tries implementation.
  ---------------


#include <bits/stdc++.h>

using namespace std;

class Tries{
 public:
    class Node{
        public:
        bool end;
        Node *next[25];
        Node()
        {
             end=false;
             for(int i=0;i<26;i++)
             {
                 next[i]=NULL;
             }
        }
    };

    Node* trie;
    Tries()
    {
        trie=new Node();
    }

    void Insert(string word)
    {
        int i=0;
        Node* it=trie;

        while(i<word.size())
        {
            if(it->next[word[i]-'a']==NULL)
            {
                it->next[word[i]-'a']=new Node();
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        it->end=true;
    }

    bool Search(string word)
    {
        int i=0;
        Node* it = trie;
        while(i<word.size())
        {
            if(it->next[word[i]-'a']==NULL)
            {
                return false;
            }
            it=it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }


};
int main()
{
Tries *mytrie = new Tries();

mytrie->Insert("abhishek");
mytrie->Insert("satyam");

cout<<mytrie->Search("abhishek");
cout<<mytrie->Search("abhi");

}
