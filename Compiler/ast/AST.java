// 추상 구문 트리의 루트를 나타내는 노드 클래스

package compiler.ast;

import compiler.entity.*;
import compiler.ir.IR;
import java.util.List;
import java.util.ArrayList;
import java.io.PrintStream;

public class AST extends Node {
	protected Location source;
	protected Declearations declarations;
	protected ToplevelScope scope;
	protected ConstantTable constantTable;

	public AST(Location source, Declaration declations) {
		super();
		this.source = source;
		this.declarations = declations;
	}

	public Location location() {
		return source;
	}

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
//이어서 하...

}
