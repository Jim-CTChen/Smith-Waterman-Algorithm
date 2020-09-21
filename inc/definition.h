#define SUBSTITUTION_MATRIX_WEIGHT 3
#define GAP_PENALTY_OPENING 10
#define GAP_PENALTY_EXTENSION 0.5
/**
 * affine gap penalty def: uk + v
 * v GAP_PENALTY_OPENING
 * k length
 * u GAP_PENALTY_EXTENSION
 * 
 * linear gap penalty def: v
**/

const int GAP_PENALTY_TYPE_LINEAR = 1;
const int GAP_PENALTY_TYPE_AFFINE = 2;