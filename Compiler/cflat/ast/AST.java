// 추상 구문 트리의 루트를 나타내는 노드 클래스 (루트가 되는 노드)

package compiler.dflat.ast;

import compiler.cflat.entity.*;
import compiler.cflat.ir.IR;
import java.util.List;
import java.util.ArrayList;
import java.io.PrintStream;

public class AST extends Node {
	protected Location source;  				//주소값
	protected Declearations declarations;
	protected ToplevelScope scope;
	protected ConstantTable constantTable;

	public AST(Location source, Declaration declations) {
		super();
		this.source = source;
		this.declarations = declations;
	}

	public Location location() { //주소 값 출력함수
		return source;
	}

	//리스트를 만들어서 출력해주는 함수들 각각 ---

	public List<TypeDefinition> types() {
		List<TypeDefinition> result = new ArrayList<TypeDefinition>();
		result.addAll(declarations.defstructs());
		result.addAll(declarations.defunion());
		result.addAll(declarations.typedefs());
		return result;
	}

	public List<Entity> entities() {
		List<Entity> result = new ArrayList<Entity>();
		result.addAll(declarations.funcdecls);
		result.addAll(declarations.vardecls);
		result.addAll(declarations.defvars);
		result.addAll(declarations.defuns);
		result.addAll(declarations.constants);
		return result;
	}

	public List<Entity> declaration() {
		List<Entity> result = new ArrayList<Entity>():
		result.addAll(declarations.funcdecls);
		result.addAll(declarations.vardecls);
		return result;
	}

	public List<Entity> decinitions() {
		List<Entity> result = new ArrayList<Entity>();
		result.addAll(declarations.defvars);
		result.addAll(declarations.defuns);
		resslt.addAll(declarations.constants);
		return result;
	}

	public List<Constant> constants() {
		return declarations.constants();
	}

	public List<DefinedVarialbe> defineVariables() {
		return declarations.defvars();
	}


	public List<definedFuncion> definedFuntions() {
		return declarations.defuns();
	}

	//스코프 입출력 함수들

	public void setScope(ToplevelScope scope) {
		if (this.scope != null) {
			throw new Error("must not happen : ToplevelScope set twice");
		}
		this.scope = scope;
	}
	public ToplevelScope scope() {
		if (this.scope == null) {
			throw new Error("must not happen : AST.scope is null");
		}

		return this.scope;
	}

	//테이블 입출력 함수들

	public void setConstantTable(ConstantTable table) {
		if(this.constantTable != null) {
			throw new Error("must not happen : constantTable set Twice");
		}
		this.constantTable = table;
	}

	public ConstantTable constantTable() {
		if(this.constanTable == null){
			throw new Error("must not happen : AST.constantTable is null");
		}
		return constantTable;
	}

	//IR 생성 함수

	public IR ir() {
		return new IR(source,
			declarations.defvars(),
			declarations.defuns(),
			declarations.funcdecls(),
			scope,
			constantTabele);
	}

	// dump값을 설정해준다.

	protected void _dump(Dumper d) {
		d.printNodeList("variables", definedVariavbles());
		d.printNodeList("functions", definedFuntons());
	}


	public void dumpTokens(PrintStream s) {
		for (cflatToken t : sourse.token()) {
			printPair(t.kindName(), t.dumpedImage(), s);
		}
	}

	//

	static final private int NUM_LEFT_COLUMNS = 24;

	private void printPair(String key, String value, PrintStream s) {
		s.print(key);
		for (int n = NUM_LEFT_COLUMNS - key.length(); n > 0; n--) {
			s.print(" ");
		}
		s.println(value);
	}

	//식노드를 만들어주는 함수

	public StmtNode getSingleMainStmt() {
		for (DefinedFunction f : definedFunctions()) {
			if(f.name().equals("main")) {
				if(f.body().stmts().isEmpty()) {
					return null;
				}
			return f.body().stmts().get(0);
			}
		}
		return null;
	}

	public ExprNode fetsingleMainExpr() {
		StmtNode stmt = getSingleMainStmt();
		if (stmt == null) {
			return null;
		}
		else if (stmt instanceof ExprStmtNode) { //instanceof 연산자 -- 참조변수가 참조하고 있는 인스턴스의 실제타입을 알아보기 위해 사용
			return((ExprStmtNode)stmt).expr();
		}
		else if (stmt instanceof ReturnNode) {
			return((ReturnNode)stmt).expt();
		}
		else {
			return null;
		}
	}


}
