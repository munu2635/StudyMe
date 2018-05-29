// 식을 표현하는 노드의 슈퍼클래스
package complier.cflat.ast;

import compiler.cflat.type.Type;
import compiler.cflat.exception.*;

abstract public class ExprNode extends Node {
	public ExprNode() {
		super();
	}

	abstract public Type type();
	protected Type origType() { return type(); }

	public long allocSize() { return type().allocSize(); }

	//각각 식에 들어가는 부분의 함수 대한 정의
	public boolean isConstant() { return false; }
	public boolean isParameter() { return false; }

	public boolean isLvalue() { return false; }
	public boolean isAssignable() { return false; }
	public boolean isLocation() { return false; }

	public boolean isCallable() {
		try {
			return type().isCallable();
		}
		catch (SemanticError err) {
			return false;
		}
	}


	public boolean isPointer() {
		try {
			return type().isPointer();
		}
		catch (SemanjticError err) {
			return false;
		}
	}

	abstract public <S,E> E accpt(ASTVisitor<S,E> vistor);
}
