
///****************************************************************************
/// @Author        : 
/// @Create time   :   2020-08-30                                                    
/// @Last modified :                                                                 
/// @Filename      :    vertexarrayobject.h                                                             
/// @Description   :   顶点数组对象                                                              
///****************************************************************************

#pragma once
#ifndef _VERTEXARRAYOBJECT_H__
#define _VERTEXARRAYOBJECT_H__

#include <glad/glad.h>
class VertexArrayObject {
public:
	VertexArrayObject();
	~VertexArrayObject();
	void bind() const;  // 绑定
	void unBind() const;// 解绑
	void specifyVertexAttribute(); // 指定顶点的属性信息，即如何解释VBO数据或者说是以什么样的格式解释
private:
	unsigned int vertexarrayobject;
};

#endif // !_VERTEXARRAYOBJECT_H__

