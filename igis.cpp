#include "igis.h"
#include "logger.h"

#include <QIcon>
#include <QFileDialog>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>


IGIS::IGIS(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("iGIS");

    QString logFilePath = QDir::currentPath() + "/logs";
    QDir dir(logFilePath);
    if (!dir.exists()) {
        dir.mkdir(logFilePath);
    }

    LInfo("Program start");

    createMenuBar();
    createActions();
    createWidgets();

    setupLayout();
}

/*************************************************************/
/*                                                           */
/*                       Initialize                          */
/*             1. Create actions, widgets, menu, etc         */
/*             2. Setup layout                               */
/*                                                           */
/*************************************************************/

void IGIS::createMenuBar() {
    /* menu bar */
    // File
    fileMenu = menuBar()->addMenu(QStringLiteral("文件"));

    openFileMenu = fileMenu->addMenu(QStringLiteral("打开"));
    openFileMenu->setIcon(QIcon(":/resources/icons/open.ico"));

}

void IGIS::createActions() {

    // menu: File -> Open
    openGeoJsonUsingGDALAction = new QAction(QStringLiteral("GeoJson"), this);   // file -> open -> GeoJson
    openShapfileAction = new QAction(QStringLiteral("Shapefile"), this);   // file -> open -> Shapefile
    openTiffAction = new QAction(QStringLiteral("Tiff"), this);   // file -> open -> Tiff

    openFileMenu->addAction(openGeoJsonUsingGDALAction);
    openFileMenu->addAction(openShapfileAction);
    openFileMenu->addAction(openTiffAction);

    connect(openGeoJsonUsingGDALAction, &QAction::triggered, this, &IGIS::onOpenGeoJsonUsingGDAL);
    connect(openShapfileAction, &QAction::triggered, this, &IGIS::onOpenGeoShapefile);
    connect(openTiffAction, &QAction::triggered, this, &IGIS::onOpenTiff);
}

void IGIS::createWidgets() {
    // opengl
    openglWidget = new OpenGLWidget(this);
}

void IGIS::setupLayout()// 设置布局
{
    this->setMinimumSize(720, 540);
    QWidget* centerWidget = new QWidget();
    this->setCentralWidget(centerWidget);

    QHBoxLayout* mainLayout = new QHBoxLayout(centerWidget);
    mainLayout->addWidget(openglWidget);
}
/*************************************************************/
/*                                                           */
/*                          槽函数                            */
/*                                                           */
/*************************************************************/

void IGIS::onOpenGeoJsonUsingGDAL() {
    QStringList files = QFileDialog::getOpenFileNames(this, QStringLiteral("打开文件"), "",
        QStringLiteral("json files(*.json)"), nullptr, QFileDialog::DontUseNativeDialog);
}

void IGIS::onOpenGeoShapefile() {
    QStringList files = QFileDialog::getOpenFileNames(this, QStringLiteral("打开文件"), "",
        QStringLiteral("shapefile(*.shp)"), nullptr, QFileDialog::DontUseNativeDialog);
}

void IGIS::onOpenTiff() {
    QStringList files = QFileDialog::getOpenFileNames(this, QStringLiteral("打开文件"), "",
        QStringLiteral("TIFF(*.tif)"), nullptr, QFileDialog::DontUseNativeDialog);
}
