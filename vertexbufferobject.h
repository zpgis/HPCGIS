
///****************************************************************************
/// @Author        : 
/// @Create time   :   2020-08-30                                                    
/// @Last modified :                                                                 
/// @Filename      :   vertexbufferobject.h                                                         
/// @Description   :   vbo 顶点缓冲对象                                                             
///****************************************************************************

#pragma once
#ifndef __VERTEXBUFFEROBJECT_H__
#define __VERTEXBUFFEROBJECT_H__
#include <glad/glad.h>

class VertexBufferObject {
public:
	
	VertexBufferObject(unsigned int size, const void* data, GLenum usage = 0x88e4 /*GL_STATIC_DRAW*/);
	~VertexBufferObject();
	unsigned int getRendererId() const {
		return vertexbufferobject;
	}
	unsigned int getSize() const { return size; }
	// 更新当前缓冲区对象中的数据，更新数据的大小不能超过原来的数据的大小
	void updateBufferData(const void* data, unsigned int offset, unsigned int size);

	void bind() const;
	void unBind() const;
private:
	unsigned int size;
	unsigned int vertexbufferobject;
};
#endif // !__VERTEXBUFFEROBJECT_H__
