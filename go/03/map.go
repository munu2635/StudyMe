// 맵 선언	var m map[keyType]valuetype
//		m := make(map[keyType]ValueType)
//		m := map[keyType]valueType{}
//   읽을때 	value, ok := m[key]
//     쓸때	map[key] = value
// 삭제할때	delete(m, key)

package main

import "reflect"
import "fmt"
import "testing"
import "sort"

func count(s string, codeCount map[rune]int) {
	for _, r := range s {
		codeCount[r]++
	}
}


func TestCount(t *testing.T) {
	codeCount := map[rune]int{}

	count("가나다나", codeCount)

	if !reflect.DeepEqual(map[rune]int{'가': 1, '나': 2, '다': 1}, codeCount, ) {
		t.Error("codeCount mismatch:", codeCount)
	}
	/*이렇게도 TestCount를 쓸수있다.  
	   if len(codeCount) != 3 {
		t.Error("codeCount:", codeCount)
		t.Fatal("cont should be 3 but:", len(codeCount))
	   }

	   if codeCount['가'] != 1 || codeCount['나'] != 2 || codeCount['다'] != 1 {
		t.Error("codeCount mismatch:", codeCount)
	   }
	*/
}


func ExampleCount() {
	codeCount := map[rune]int{}
	count("가나다나", codeCount)

	var keys sort.IntSlice
	for key := range codeCount {
		keys = append(keys, int(key))
	}

	sort.Sort(keys)
	for _, key := range []rune{'가', '나', '다'} {
		fmt.Println(string(key), codeCount[key])
	}
	// Output:
	// 가 1
	// 나 2
	// 다 1
}


func hasDupeRune(s string) bool {
	runeSet := map[rune]bool{}
	for _, r := range s {
		if runeSet[r]{ //if -, exists := runeSet[r]; exists 
			return true
		}
		reneSet[r] = true //struct{}{}
	}
	return false
}


func main(){
	ExampleCount()
}
