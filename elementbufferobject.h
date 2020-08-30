
///****************************************************************************
/// @Author        : 
/// @Create time   :  2020-08-30                                                     
/// @Last modified :                                                                 
/// @Filename      :  elementbufferobject.h                                                               
/// @Description   :  元素缓冲对象ebo，也叫索引缓冲对象Index buffer object，该缓冲区主要用来存储顶点的索引信息                                                               
///****************************************************************************

#pragma once
#ifndef __ELEMENTBUFFEROBJECT_H__
#define __ELEMENTBUFFEROBJECT_H__

#include <glad/glad.h>

class ElementBufferObject {
public:
	ElementBufferObject(unsigned int size, const void* data, GLenum usage = 0x88e4 /*GL_STATIC_DRAW*/);
	~ElementBufferObject();

private:
	unsigned int elementbufferobject;
};

#endif // !__ELEMENTBUFFEROBJECT_H__
