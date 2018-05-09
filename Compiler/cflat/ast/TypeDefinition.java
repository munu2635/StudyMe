//타입을 정의하는 노드의 슈퍼클레스

package Compiler.cflat.ast;
import compiler.cflat.type.*;

abstract public class TypeDefinition extends Node {
	protected String name;
	protected Location location;
	protected TypeNode typeNode;

	public TypeDefinition(Location loc, TypeRef ref, String name) {
		this.name = name;
		this.location = loc;
		this.typeNode = new TypeNode(ref);
	}

	public String name() {
		return name;
	}

	public Location location() {
		return location;
	}

	public TypeNode typeNode() {
		return typeNode;
	}

	public TypeRef typeRef() {
		return typeNode.typeRef();
	}

	public Type type() {
		return typeNode.type();
	}

	abstract public Type definingType();
	abstract public <T> T accept(DeclarationVistitor<t> visitor);
}
