package main

import (
	"errors"
	"fmt"
)

type queue struct {
	maxsize int
	array   [10]int
	front   int
	rear    int
}

func (this *queue) add(val int) (err error) {
	if this.rear == this.maxsize-1 {
		return errors.New("queue full")
	}
	this.rear++
	this.array[this.rear] = val
	return

}
func (this *queue) show() {
	for i := this.front + 1; i <= this.rear; i++ {
		fmt.Printf("array[%d]=%d\n", i, this.array[i])
	}
}
func main() {
	q := &queue{
		maxsize: 10,
		front:   -1,
		rear:    -1,
	}
	err := q.add(1)
	if err != nil {
		fmt.Println(err)
		return
	}
	err = q.add(2)
	if err != nil {
		fmt.Println(err)
		return
	}
	q.show()
}
