// 문장을 표현하는 노드의 슈퍼클래스
package Compiler.ast;

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
