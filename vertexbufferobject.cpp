#include "vertexbufferobject.h"

VertexBufferObject::VertexBufferObject(unsigned int size, const void* data, GLenum usage  /*GL_STATIC_DRAW*/):size(size) {
	glGenBuffers(1, &vertexbufferobject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferobject);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

VertexBufferObject::~VertexBufferObject()
{
	glDeleteBuffers(1, &vertexbufferobject);
}

void VertexBufferObject::updateBufferData(const void* data, unsigned int offset, unsigned int size) {
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferobject);
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}
void VertexBufferObject::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferobject);
}

void VertexBufferObject::unBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

