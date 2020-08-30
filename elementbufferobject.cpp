#include "elementbufferobject.h"

ElementBufferObject::ElementBufferObject(unsigned int size, const void* data, GLenum usage /*GL_STATIC_DRAW*/) {

    glGenBuffers(1, &elementbufferobject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbufferobject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
ElementBufferObject::~ElementBufferObject() {
    glDeleteBuffers(1, &elementbufferobject);
}