#define SUBSTITUTION_MATRIX_WEIGHT 3
#define GAP_PENALTY_OPENING 10
#define GAP_PENALTY_EXTENSION 0.5
/**
 * affine gap penalty def: uk + v
 * u GAP_PENALTY_OPENING
 * k length
 * v GAP_PENALTY_EXTENSION
 * 
**/

enum Direction {
  top_left = 0,
  top = 1,
  left = 2,
  zero = 3,
  last
};