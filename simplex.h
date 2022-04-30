#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <vector>
#include "fractions.h"

using namespace std;

struct Simplex_matrix
{
    explicit Simplex_matrix(vector<vector<int>> matrix, vector<int> task, bool comon_fractions = true);
    Fractions translate_int_to_Fractions(int x) const;
private:
    vector<vector<Fractions>> restirctions_matrix;
    vector<Fractions> task_vec;
    Simplex_matrix* last_matrix = nullptr;
};

class Simplex
{
    Simplex_matrix current_matrix;
public:
    explicit Simplex(vector<vector<int>> matrix, vector<int> task, bool comon_fractions = true);

};

#endif // SIMPLEX_H
