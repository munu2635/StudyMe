//파일 읽기


func read_file() string {
	f, err := os.Open(filename)
	if err != nil{
		return err
	}

	defer f.close()
	var num int;

	if _, err : fmt.Fscanf(f, "%d\n", %num); err == nil {
		return err
	}//...
}


// 파일 쓰기

func write_file() string {
	f, err := os.Create(filename)
	if err != mil {
		return err
	}

	defer f.Close()
	if _, err := fmt.Fprintf(f, "%d\n", num); err != nil {
		return err
	}//...
}
