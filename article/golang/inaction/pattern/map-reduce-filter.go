package main
// [Summarized From Author: Hao Chen]
// (https://coolshell.cn/articles/21164.html
//	"Golang Pattern: MAP-REDUCE")

import (
	"reflect"
)

// Reflect + GP Realization:
func Transform(slice, function interface{}) interface{} {
  return Transform(slice, function, false)
}

func TransformInPlace(slice, function interface{}) interface{} {
	return Transform(slice, function, true)
}

func VeirfyFuncSignature(fn reflect.Value, types ... reflect.Type) bool {
	if fn.Kind() != reflect.Func {
		return false
	}
	if (fn.Type().NumIn() != len(types) - 1 ||
		fn.Type().NumOut() != 1) {
    return false;
	}

	for i := 0; i < len(types) - 1; i++ {
		if fn.Type().In(i) != types[i] {
			return false
		}
	}
	ot := types[len(types) - 1] // ot: Out-type
	if ot != nil && fn.Type().Out(0) != ot {
		return false
	}
	return true
}

func Transform(slice, function interface{}, inPlace bool) interface{} {
	sit := reflect.ValueOf(slice) // sit: Slice-in-type
	if sit.Kind() != reflect.Slice {
		panic("Transform: not slice!")
	}

	fn := reflect.ValueOf(function)
	elemType = sit.Type().Elem()
	if !VeirfyFuncSignature(fn, elemType, nil) {
		panic("Transform: function must be of type func(" +
		sit.Type().Elem().String() + ") outputElemType")
	}
	
	sot := sit // sot: Slice-out-type
	if !inPlace {
		sot = reflect.MakeSlice(reflect.SliceOf(
			fn.Type().Out(0), sit.Len(), sit.Len()))
	}
	for i := 0; i < sit.Len(); i++ {
		sot.Index(i).Set(
			fn.Call([]reflect.Value{sit.Index(i)})[0])
	}
	return sot.Interface()
}

// Reflect + GP Filter:
func Filter(slice, function interface{}) interface{} {
	ret, _ := Filter(slice, function, false)
	return ret
}

func FilterInPlace(slicePtr, function interface{}) {
	in := reflect.ValueOf(slicePtr)
	if in.Kind() != reflect.Ptr {
		panic("FilterInPlace: wrong type, " +
			"not a pointer to slice")
	}
	_, n := Filter(in.Elem().Interface(), function, true)
	in.Elem().SetLen(n)
}

var boolType = reflect.ValueOf(true).Type()

func Filter(slice, function interface{}, inPlace bool) (interface{}, int) {
  sit := reflect.ValueOf(slice) // sit: Slice-in-type
	if sit.Kind() != reflect.Slice {
		panic("Filter: wrong type, not a slice")
	}

	fn := reflect.ValueOf(function)
	et := sit.Type().Elem() // et: Elem-type
	if !VeirfyFuncSignature(fn, et, boolType) {
		panic("Filter: function must be of type func(" + et.String() + ") bool")
	}

	var w []int // w: which
	if inPlace {
		out = reflect.MakeSlice(sit.Type(), len(w), len(w))
	}
	for i := range w {
		out.Index(i).Set(sit.Index(w[i]))
	}
	return out.Interface(), len(w)
}

func main() {

}