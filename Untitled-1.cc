int compare_and_swap(int *reg, int oldval, int newval) {
  int old_reg_val = *reg;
  if (old_reg_val == oldval) {
    *reg = newval;
  }
  return old_reg_val;
}