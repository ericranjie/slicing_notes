#include <iostream>
#include <vector>
using namespace std;

// many-entrap:
struct node {
    int value;
    struct node *p_next;
};

int main() {
    int n, h, t; // number-head-target
    vector<int> v;

    cin >> n >> h;
    while (cin >> t) {
        v.push_back(t);
        // cout << t << " ";
    }
    t = v[v.size() - 1]; // target
    v.pop_back();
    if (v.size() % 2 != 0) {
        return 0; // guard: error
    }

    // header-construct:
    struct node *ph = (struct node *)malloc(sizeof(struct node));
    ph->value = h;
    ph->p_next = nullptr;

    // body-construct:
    bool pair = false; // construct-one-pair
    int o = 0, e = 0; // odd-even
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0) { // even
            e = v[i];
            pair = false;
        } else if ((i % 2) == 1) { // odd
            o = v[i];
            pair = true;
        }
        
        if (pair) { // found-a-pair(odd->even)
            // cout << e << "-" << o<< endl;
            pair = false; // POE:
            struct node *c = ph; // current-pointer
            while (c != nullptr) {
                // cout << c->value << "--" << e << endl;
                // POE: insert-need-verify
                if (c->value == o) { // POE: second-one-is-odd
                    struct node *p = (struct node *)malloc(sizeof(struct node));
                    p->value = e; // POE:
                    p->p_next = c->p_next;
                    c->p_next = p;
                    // cout << o << "->" << e << endl;
                    break;
                }
                c = c->p_next;
            }
        }
    }

    // step-n: find-node-and-erase:
    struct node *dummy = (struct node *)malloc(sizeof(struct node));
    dummy->value = -1;
    dummy->p_next = ph;
    struct node *c = dummy;
    // cout << t << endl;
    while (c->p_next) {
        if (c->p_next->value == t) {
            c->p_next = c->p_next->p_next;
            // break;
        }
        c = c->p_next;
    }

    while (ph) {
        cout << ph->value << " ";
        ph = ph->p_next;
    }

    return 0;
}
// 5 2 3 2 4 3 5 2 1 4 3
// 64 位输出请用 printf("%lld")