#include <iostream>
#include <list>
#include <set>
#include <stack>

#define ans(x) cout<<x<<endl
#define debug(tag,x) cout<<tag<<" : "<<x<<endl

using namespace std;

struct node {
    int n1,n2,wth;
};

bool do_contain(auto i, int q[]){
    return (i->find(q[0]) != i->end()) || (i->find(q[1]) != i->end());
}

bool do_contain_both(auto i, int q[]){
    return (i->find(q[0]) != i->end()) && (i->find(q[1]) != i->end());
}

bool is_in_union(node *a, list<set <int> > *b) {
    stack<int> s;
    int q[] = {a->n1,a->n2};
    set<int> z(q,q+2);
    set<int> g;
    int j=0;
    bool suc = false;
    for(auto i = b->begin(); i != b->end(); ++i) {
        if (do_contain_both(i,q)) {
            suc = true;
            break;
        }
    }

    for(auto i = b->begin(); i != b->end(); ++i, j++) {
        if (do_contain(i,q)) s.push(j);
    }
    //debug("size",b->size());
    while(!s.empty()){
        auto y = b->begin();
        advance(y, s.top());
        z.insert(y->begin(),y->end());
        b->remove(*y);
        s.pop();
    }
    b->push_back(z);
    return suc;
}

void node_swap(node *A, node *B) {
    node tmp = *A;
    *A = *B;
    *B = tmp;
}

void node_insert_sort(node* a, int n) {
    int i,j;
    for(i=1; i<n; i++){
        j = i;
        while(j > 0 && a[j-1].wth >= a[j].wth) {
            if(a[j-1].wth == a[j].wth){
                if(!(a[j-1].n1+a[j-1].n2+a[j-1].wth)<(a[j].n1+a[j].n2+a[j].wth))
                    {j--;continue;}
            }
            node_swap(&a[j-1],&a[j]);
            j--;
        }
    };

}

int main() {
    int n,e,start,sum=0;
    list<set <int> > b;
    cin>>e>>n;
    node a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i].n1>>a[i].n2>>a[i].wth;
        a[i].n1--;
        a[i].n2--;
    }
    node_insert_sort(a,n);
    cin>>start;
    start--;
    int w = 0;
    for(int i=0; i<n; i++) {
        if (w==e-1) break;
        if(!is_in_union(&a[i],&b)) {
            //debug("sum",a[i].wth);
            sum += a[i].wth;
            w++;
        }
    }
    ans(sum);
}
