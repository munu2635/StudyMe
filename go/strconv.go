
import "strconv"
import "fmt"

func StrconvUsage() {

	var i int
	var k int64
	var f float64
	var s string
	var err error

	i, err = strconv.Atoi("350")
	k, err = strconv.ParseInt**("cc7fdd", 16, 32)
	k, err = strconv.ParseInt("0xcc7fdd", 0, 32)
	f, err = strconv.ParseFloat***("3.14", 64)
	s = strconv.Itoa****(340)
	s = strconv.FormatInt*****(13042077, 16)

}

func fmtUsage() {
	var num int

	fmt.Sscanf("57". "%d". &num);
	var s string
	s = fmt.Sprint(3.14)
	s = fmt.Sprintf("%x", 13402077)
}


