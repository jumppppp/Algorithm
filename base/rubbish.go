package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Node struct {
	row int
	col int
	val int
}

func main() {
	var chessmap [11][11]int
	rand.Seed(time.Now().Unix())

	// 生成 0 到 10 之间的随机整数

	for i := 0; i < 20; i++ {
		x := rand.Intn(11)
		y := rand.Intn(11)
		v := rand.Intn(11)
		chessmap[x][y] = v
	}

	for _, v := range chessmap {
		for _, v2 := range v {
			fmt.Printf("%d ", v2)
		}
		fmt.Printf("\n")
	}
	var sp []Node
	n2 := Node{row: 11, col: 11, val: 0}
	sp = append(sp, n2)
	for i, v := range chessmap {
		for j, v2 := range v {
			if v2 != 0 {
				n1 := Node{
					row: i,
					col: j,
					val: v2,
				}
				sp = append(sp, n1)
			}
		}
	}
	for i, v := range sp {
		fmt.Printf("[%d] %d %d %d\n", i, v.row, v.col, v.val)
	}
	var chessmap2 [11][11]int
	for i, v := range sp {
		if i > 0 {
			chessmap2[v.row][v.col] = v.val
		}

	}
	for _, v := range chessmap2 {
		for _, v2 := range v {
			fmt.Printf("%d ", v2)
		}
		fmt.Printf("\n")
	}

}
