#include  "vertexarrayobject.h"

VertexArrayObject::VertexArrayObject() {
	glGenVertexArrays(1, &vertexarrayobject);
	this->bind();
}

VertexArrayObject::~VertexArrayObject() {
	glDeleteVertexArrays(1, &vertexarrayobject);
}

void VertexArrayObject::specifyVertexAttribute() {
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);
}

void VertexArrayObject::bind() const {
	glBindVertexArray(vertexarrayobject);
}

void VertexArrayObject::unBind() const {
	glBindVertexArray(0);
}