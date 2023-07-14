#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<int> child;
    bool end;

    Node() {
        child.assign(26, -1);
        end = false;
    }
};

vector<Node> trie(1);

void insert(string &s) {
    int v = 0;
    for (auto &ch : s) {
        int c = ch - 'a';
        if (trie[v].child[c] == -1) {
            trie[v].child[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].child[c];
    }
    trie[v].end = true;
}

void prints(int v, string &s) {
    if (trie[v].end) cout << s << endl;
    for (int i = 0; i < 26; i++) {
        if (trie[v].child[i] != -1) {
            s.push_back(char(i + 'a'));
            prints(trie[v].child[i], s);
            s.pop_back();
        }
    }
}

bool trieSearch(string s) {
    int v = 0;
    for (auto &ch : s) {
        int c = ch - 'a';
        if (trie[v].child[c] != -1) {
            v = trie[v].child[c];
        }
        else {
            return false;
        }
    }
    return trie[v].end;
}

int main() {
    string s = "hello", t = "helaa", r = "xyz";
    insert(s); insert(t); insert(r);

    // for (auto &i : trie) {
    //     for (auto j : i.child) cout << j << " "; cout << endl;
    // }

    cout << trieSearch("xyz") << endl;

    string tmp;
    prints(0, tmp);

    return 0;
}