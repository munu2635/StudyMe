// 임의의 2항 연산을 표현하는 노드 및 노드에 의한 식 표현의 예

package Compiler.ast;
import type.Type;

public class BinaryOpNode extends ExprNode {
	protected String operator;
	protected ExptNode left, right;
	protected Type type;

	public BinaryOpNode(ExprNode left, String op, ExprNode right) {
		super();
		this.operator = op;
		this.left = left;
		this.right = right;
	}

	public BinaryOpNode(Type t, ExprNode left, String op, ExprNode right) {
		super();
		this.operator = op;
		this.left = left;
		this.right = right;
		this.type = t;
	}

	public String operator() {
		return operator;
	}

	public Type type() {
		return (type != null) ? type : left.type();
	}

	public void setType(Type type) {
		if (this.type != null)
			throw new Error("BinaryOp#setType called twice");

		this.type = type;

	}

	public ExprNode left() {
		return left;
	}

	public ExprNode right() {
		return right;
	}

	public void setLeft(ExprNode left) {
		this.left = left;
	}

	public void setRight(ExprNode right) {
		this.right = right;
	}

	public Location location() {
		return left.location();
	}


	protected void _dump(Dumper d) {
		d.printMember("operator", operator);
		d.printMember("left", left);
		d.printMember("right", right);
	}

	public <S, E> E accept(ASTVisitor<S, E> visitor) {
		return visitor.visit(this);
	}

}
