package main

import "fmt"

func Example_Array(){
	fruits := [3]string{"사과", "바나나", "토마토"}
	// fruits := [...]string{etc} 이런식으로 사용 가능하다.

	for _, fruit := range fruits {
		fmt.Printf("%s는 맛있나..\n", fruit)
	}

	// Output:
	// 사과는 맛있나..
	// 바나나는 맛있나..
	// 토마토는 맛있나..
}


func main(){
	Example_Array()
}
