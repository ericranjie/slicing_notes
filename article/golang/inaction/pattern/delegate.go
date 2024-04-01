package main
// [Summarized From Author: Hao Chen]
// (https://coolshell.cn/articles/21214.html
//	"Golang Pattern: Delegate-IOC")

type Widget struct {
	X, Y int
}

type Label struct {
	Widget // Embedding (delegation)
	Text string // Aggregation
}

type Button struct {
	Label // Embedding (delegation)
}

type ListBox struct {
	Widget // Embedding (delegation)
	Texts []string
	index int
}

type Painter interface {
	Paint()
}

type Clicker interface {
	Click()
}

func (label Label) Paint() {
	///
}

func (button Button) Paint() { // Override
	///
}

func (button Button) Click() {
	///
}

func (listbox ListBox) Paint() {
	///
}

func (listbox ListBox) Click() {
	///
}

func main() {
  b1 := Button{Label{Widget{10, 70}, "OK"}}
	b2 := NewButton(50, 70, "Cancel")
	lb := ListBox{Widget{10, 40}, // lb: listbox
		[]string{"AL", "AK", "AZ", "AR"}, 0}
	
	for _, p := range []Painter{l, lb, b1, b2} {
		p.Paint()
	}

	for _, w := range []interface{} {l, lb, b1, b2} { // w: widget
		w.{Painter}.Paint()
		if c, ok: w.{Clicker}; ok { // c: clicker
			c.Click()
		}
	}
}