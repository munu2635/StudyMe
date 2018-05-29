package main

import (
	"io"
	"os"
	"io/ioutil"
)

func main() {
	//입력파일 열기
	fi, err := os.Open("1.txt")
	if err != nil{
		panic(err)
	}
	defer fi.Close()


	//출력파일 생성
	fo, err := os.Create("1.txt")
	if err != nil {
		panic(err)
	}

	defer fo.Close()

	buff := make([]byte, 1024)

	for {
		cnt, err := fi.Read(buff)
		if err != nil && err != io.EOF {
			panic(err)
		}

		if cnt == 0 {
			break
		}

		_, err = fo.Write(buff[:cnt])
		if err != nil {
			panic(err)
		}
	}
}


func use_ioutil() {
	//파일 읽기
	bytes, err := ioutil.ReadFile("1.txt")
	if err != nil {
		panic(err)
	}

	err = ioutil.WriteFile("1.txt", bytes, 0)
	if err != nil {
		panic(err)
	}
}
