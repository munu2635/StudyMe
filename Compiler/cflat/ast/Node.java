package Compiler.cflat.ast;
import java.io.printstream;

//오류가 있는 문장이나 식이 들어 있는 파일과 행 번호를 표시해준다.

abstract public class Node implements Dumpable {
	public Node() {
	}

	abstract public Location location();

// dump, _dump는 추상구문 트리를 텍스트로 표시하는 메서드. method
	public void dump () {
		dump (System.out);
	}

	public void dump(PrintStrean s) {
		dump(new Dumper(s));
	}

	public void dump(Dumper d) {
		d.printClass(this, location());
		_dump(d);
	}

	abstract protected void _dump(Dumper d);
}
