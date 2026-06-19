#include <queue>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    pair<int, char> val;

    Node(Node* l, Node* r, const pair<int, char> &v) {
        left = l; right = r; val = v;
    }

    Node(const pair<int, char> &v) {
        val = v;
    }
};

void Encode(map<char, string> &m, Node &cur, string s) {
    if (cur.val.second != '\0') {
        m[cur.val.second] = s.empty() ? "0": s;
        return;
    }

    if (cur.left != nullptr) Encode(m, *cur.left, s+'0');
    if (cur.right != nullptr) Encode(m, *cur.right, s+'1');
}

struct Compare {
    bool operator()(const Node* a, const Node* b) const {
        return a->val.first > b->val.first;
    }
};

map<char, string> buildtree(string s) {
    map<char, int> h;
    for (int i{0}; i < s.length(); i++) {
        if (h.contains(s[i])) {
            h[s[i]] += 1;
            continue;
        }
        h[s[i]] = 1;
    }
    priority_queue<Node*, vector<Node*>, Compare> q;
    for (auto& [key, value] : h) {
        q.push(new Node({value, key}));
    }

    while (q.size() > 1) {
        Node* t1 = q.top(); q.pop();
        Node* t2 = q.top(); q.pop();
        if (t1->val.first < t2->val.first) {
            Node* n = new Node(t1, t2, {t2->val.first + t1->val.first, '\0'});
            q.push(n);
            continue;
        }
        Node* n = new Node(t2, t1, {t2->val.first + t1->val.first, '\0'});
        q.push(n);
    }
    Node* root = q.top();
    map<char, string> fin;
    Encode(fin, *root, "");
    return fin;
}


int main() {
    string s = "AAAAAAAAAAAAABCBCBABCDBDCYCBDBDHCKSSIFWAOFINWAIUONB";
    map<char, string> m = buildtree(s);
    for (auto& [key, value] : m) {
        cout << key << ": " << value << "\n";
    }
}