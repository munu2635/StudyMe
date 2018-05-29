// 문장을 표현하는 노드의 슈퍼클래스

package Compiler.cflat.ast;

//abstract는 추상 클래스 - 메소드의 시그니처만이 정의된 비어있는  메소드를 의미한다.
abstract public class StmtNode extends Node {
	protected Location location;

	public stmtNode(Location loc) {
		this.location = loc;
	}

	public Location location() {
		return location;
	}

	abstract public <S, E> S accept(ASTVisitor<S, E> visitor);
}
