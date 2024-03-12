# Golang-pattern
[Summarize From Author: Hao Chen](https://coolshell.cn/ "Golang Pattern")

## Pipeline
```golang
type EchoFunc func ([]int) (<- chan int)
type PipeFunc func (<- chan int) (<- chan int)

from pipeline(num []int, echo EchoFunc, pipeFns ... PipeFunc) <- chan int{
  ch := echo(nums)
  for i := range pipeFns {
    ch = pipeFns[i](ch)
  }
  return ch
}

func sq(in <-chan int) <-chan int {
  out := make(chan int)
  go func() {
    for n := range in {
      out <- n * n
    }
    close(out)
  } ()
  return out
}

func odd(in <-chan int) <-chan int {
  out := make(chan int)
  go func() {
    for n := range in {
      if n%2 != 0 {
        out <- n
      }
    }
    close(out)
  }()
  return out
}

func sum(in <-chan int) <-chan int {
  out := make(chan int)
  go func() {
    var sum = 0
    for n := range in {
      sum += n
    }
    out <- sum
    close(out)
  }()
  return out
}

func main() {
  var nums = []int{1, 2, 3, 4, 5}
  for n := range pipelang(nums, gen, odd, sq, sum) {
    fmt.Println(n)
  }
}
```
### Fan-in/out
```golang
func makeRange(min, max int) []int {
  a := make([]int, max-min+1)
  for i := range a {
    a[i] = min + i
  }
  return a
}

func is_prime(value int) bool {
  for i := 2; i <= int(math.Floor(float64(value) / 2)); i++ {
    if value%i == 0 {
      return false
    }
  }
  return value > 1
}

func prime(in <-chan int) <-chan int {
  out := make(chan int)
  go func ()  {
    for n := range in {
      if is_prime(n) {
        out <- n
      }
    }
    close(out)
  }()
  return out
}

func merge(cs []<-chan int) <-chan int {
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
  nums := makeRange(1, 10000)
  in := echo(nums)

  const nProcess = 5
  var chans [nProcess]<-chan int
  for i := range chans {
    chans[i] = sum(prime(in))
  }

  for n := range sum(merge(chans[:])) {
    fmt.Println(n)
  }
}
```