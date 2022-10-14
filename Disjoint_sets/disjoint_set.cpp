#include "disjoint_set.h"

Disjoint_set::Disjoint_set(int n){

    std::cout << "constructor called" << std::endl;
    for (int i = 0; i < n; i++){
        vec.push_back(-1); /* setting them as reperesentative elements */
        size_vec.push_back(1);
    }

}

/*I could actually do better here Manas*/
int Disjoint_set::find(int x) {

    int representative;
    if (vec[x] == -1){
        return x;
    }

    else {
        representative = find(vec[x]);
        vec[x] = representative;   //This will flatten out the whole path till root node.
        return representative;
    }
}

int Disjoint_set::union_sets(int x, int y){

    int x_set, y_set;
    x_set = find(x);
    y_set = find(y);

    if (x_set == y_set) {
        return 0;
    }

    else {
        if (x_set < y_set) {
            vec[x_set] = y_set;
            size_vec[y_set] = size_vec[y_set] + size_vec[x_set];
            size_vec[x_set] = 0;
        }

        else {
            vec[y_set] = x_set;
            size_vec[x_set] = size_vec[x_set] + size_vec[y_set];
            size_vec[y_set] = 0;
        }
    }
    return 0;
}