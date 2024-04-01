package main
// [Summarized From Author: Hao Chen]
// (https://coolshell.cn/articles/21214.html
//	"Golang Pattern: Delegate-IOC")

// IOC: Inversion of Control
type IntSet struct {
	data map[int]bool
}

func NewIntSet() IntSet {
	return IntSet(make(map[int]bool))
}

func (set *IntSet) Add(x int) {
	set.data[x] = true
}

func (set *IntSet) Delete(x int) {
	delete(set.data, x)
}

func (set *IntSet) Contains(x int) bool {
  return set.data[x]
}

type UndoableIntSet struct {
  IntSet
	functions []func()
}

func NewUndoableIntSet() UndoableIntSet {
	return UndoableIntSet(NewIntSet(), nil)
}

func (set *UndoableIntSet) Add(x int) {
	if !set.Contains(x) {
		set.data[x] = true
		set.functions = append(set.functions, func() {
			set.Delete(x)
		})
	} else {
		set.functions = append(set.functions, nil)
	}
}

func (set *UndoableIntSet) Undo() error {
	if len(set.functions) == 0 {
		return errors.New("No function to undo")
	}
	i := len(set.functions) - 1 // i: index
	if function := set.functions[i]; function != nil {
		function()
		set.functions[i] = nil // Garbage collection
	}
	set.functions = set.functions[:index]
	return nil
}

func main() {

}