package main

import (
	"math"
	"sync"
	"fmt"
)
// [Summarized From Author: Hao Chen]
// (https://coolshell.cn/articles/21228.html
//	"Golang Pattern: pipeline")

func Echo(nums []int) <-chan int {
	out := make(chan int)
	go func() {
		for _, n := range nums {
			out <- n
		}
		close(out)
	}()
	return out
}

func Sum(in <-chan int) <-chan int {
	out := make(chan int)
	go func() {
		var sum = 0
		for i := range in {
			sum += i
		}
		out <- sum
		close(out)
	}()
	return out
}

func MakeRange(min, max int) []int {
  a := make([]int, max - min + 1)
	for i := range a {
		a[i] = min + i
	}
	return a
}

func IsPrime(value int) bool {
	for i := 2; i <= int(math.Floor(
		float64 (value) / 2)); i++ {
		if value % i == 0 {
			return false
		}
	}
	return value > 1
}

func Prime(in <-chan int) <-chan int {
	out := make(chan int)
	go func() {
		for n := range in {
			if IsPrime(n) {
				out <- n
			}
		}
		close(out)
	}()
	return out
}

// param[in]: cs: multi-channel
func Merge(cs []<-chan int) <-chan int {
	var wg sync.WaitGroup
	out := make(chan int)

	wg.Add(len(cs))
	for _, c := range cs {
		go func(c <-chan int) {
			for n := range c {
				out <- n
			}
			wg.Done()
		}(c)
	}
	go func() {
		wg.Wait()
		close(out)
	}()
	return out
}

func main() {
  nums := MakeRange(1, 10000)
	in := Echo(nums)

	const nProcess = 5
	var chans [nProcess] <-chan int
	for i := range chans {
		chans[i] = Sum(Prime(in))
	}

	for n := range Sum(Merge(chans[:])) {
		fmt.Println(n)
	}
}