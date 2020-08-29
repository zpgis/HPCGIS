#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include "openglwidget.h"

class IGIS : public QMainWindow
{
    Q_OBJECT

public:
    IGIS(QWidget *parent = Q_NULLPTR);
    ~IGIS() {}
public:
    /* ��ʼ�� */
    void createMenuBar();
    void createActions();
    void createWidgets();
    void setupLayout();// ���ò���
public slots:
    void onOpenGeoJsonUsingGDAL();
    void onOpenGeoShapefile();
    void onOpenTiff();
private:
    /* menu bar */
    QMenu* fileMenu;    // File
    QMenu* openFileMenu;

    //  Action
    QAction* openGeoJsonUsingGDALAction;
    QAction* openShapfileAction;
    QAction* openTiffAction;

    // widget
    OpenGLWidget* openglWidget;
};
