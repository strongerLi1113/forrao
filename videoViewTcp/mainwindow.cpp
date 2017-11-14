#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QFile>
#include <iostream>
#include <fstream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        int i;
    ui->setupUi(this);


   QFile tmpfile("camera.yuv");
    tmpfile.open(QIODevice::ReadOnly);
    tmpfile.read((char*)yuvBuf, sizeof(yuvBuf));
    cnv = new conversion();
    cnv->YUV2RGB(yuvBuf,rgbBuf,640,480);
    QImage image = QImage(rgbBuf, 640,480, QImage::Format_RGB888);
    ui->label->clear();
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}
