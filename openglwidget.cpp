#include "openglwidget.h"
#include "vertexbufferobject.h"
#include <QDebug>


/*************************************/
/*                                   */
/*         OpenGLWidget              */
/*                                   */
/*************************************/

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent), shader(nullptr)
{

}

OpenGLWidget::~OpenGLWidget()
{
    //glDeleteVertexArrays(1, &vertex_array_object);
    //glDeleteBuffers(1, &vertex_buffer_object);
    delete vao;
    delete vbo;
    delete ebo;
}

/**********************************************/
/*                                            */
/*       Override QOpenGLWidget               */
/*                                            */
/**********************************************/

void OpenGLWidget::initializeGL() {
    // 初始化glad
    if (gladLoadGL() == 0) {
        qDebug("Failed to initialize GLAD");
    }
    shader = new Shader();
    shader->create("resources/shaders/triangle.vs", "resources/shaders/triangle.fs");

    static const GLfloat triangle[] = {
             //-0.5f, -0.5f, 0.0f,   // 左下
             // 0.5f, -0.5f, 0.0f,   // 右下
             // 0.0f,  0.5f, 0.0f    // 正上
            // 第一个三角形
    0.5f, 0.5f, 0.0f,     // 右上
    0.5f, -0.5f, 0.0f,    // 右下
    -0.5f, -0.5f, 0.0f,   // 左下
    // 第二个三角形
    //-0.5f, -0.5f, 0.0f,   // 左下
    //0.5f, 0.5f, 0.0f,     // 右上
    -0.5f, 0.5f, 0.0f     // 左上
    };
    // 索引数据(注意这里是从0开始的)
    unsigned int indices[] = {
        0, 1,              // 第一个三角形
        1, 2,               // 第二个三角形
        2,3,
        3,0
    };

    //// 将顶点数据绑定至当前默认的缓冲中
    vbo = new VertexBufferObject(sizeof(triangle), triangle,  GL_STATIC_DRAW);

    vao = new VertexArrayObject();
    vao->specifyVertexAttribute();

    ebo = new ElementBufferObject(sizeof(indices), indices, GL_STATIC_DRAW);

    // 解绑VAO和VBO
    vao->unBind();
    vbo->unBind();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void OpenGLWidget::resizeGL(int w, int h) {
    Q_UNUSED(w);
    Q_UNUSED(h);
}

void OpenGLWidget::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    shader->use();
    vao->bind();

    glDrawElements(GL_LINES, 8, GL_UNSIGNED_INT, 0);// 使用ebo时，对应的使用glDrawElements.并且在使用的前后要进行VAO的绑定与解绑

    vao->unBind();
}
