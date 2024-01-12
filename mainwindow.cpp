#include "mainwindow.h"
#include <QtWidgets>
#include <QGroupBox>
#include <QWidget>
#include <cmath>

float MainWindow::PL(float f, float d){
    return 28 + 22 * log10(f) + 20* log10(d);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    QGraphicsScene* scene = new QGraphicsScene();
    int maxX = 1000;
    int maxY = 1000;
    double onePixDistance = 10; //[m]
    int TxPower = 10; // [dBm]
    int antGain = 6; // [dBi]
    float freq = 6; // [GHz]
    int cellPosX = 100;
    int cellPosY = 900;
    QPixmap map(maxX, maxY); // создаем карту для рисования
    QPainter p(&map);
    //p.setPen(QColor(255, 0, 0, 255)); // <--
    for(int i = 0; i < maxX; i++){
        for(int j = 0; j < maxY; j++){
            float distance = 0;
            distance = sqrt(pow(abs(cellPosX - i),2) + pow(abs(cellPosY - j),2)); // [pix]
            distance *= onePixDistance; // [meters]
            float sigPower = TxPower + antGain - PL(freq, distance);
            if(sigPower < -30 && sigPower >= -35){
                p.setPen(QColor(255, 0, 0, 255)); // <--
            } else if (sigPower < -35 && sigPower >= -40) {
                p.setPen(QColor(255, 50, 0, 255)); // <--
            } else if (sigPower < -40 && sigPower >= -45) {
                p.setPen(QColor(255, 80, 0, 255)); // <--
            } else if (sigPower < -45 && sigPower >= -50) {
                p.setPen(QColor(255, 120, 0, 255)); // <--
            } else if (sigPower < -50 && sigPower >= -55) {
                p.setPen(QColor(255, 180, 0, 255)); // <--
            } else if (sigPower < -55 && sigPower >= -60) {
                p.setPen(QColor(255, 215, 0,255)); // <--
            } else if (sigPower < -60 && sigPower >= -65) {
                p.setPen(QColor(255, 255, 0, 255)); // <--
            } else if (sigPower < -65 && sigPower >= -70) {
                p.setPen(QColor(173, 255, 47, 255)); // <--
            } else if (sigPower < -70 && sigPower >= -75) {
                p.setPen(QColor(127, 255, 0, 255)); // <--
            } else if (sigPower < -75 && sigPower >= -80) {
                p.setPen(QColor(124, 252, 0)); // <--
            } else if (sigPower < -80 && sigPower >= -85) {
                p.setPen(QColor(102, 205, 170, 231)); // <--
            } else if (sigPower < -85 && sigPower >= -90) {
                p.setPen(QColor(32, 178, 170, 255)); // <--
            } else if (sigPower < -90 && sigPower >= -95) {
                p.setPen(QColor(0, 139, 139)); // <--
            } else if (sigPower < -95 && sigPower >= -100) {
                p.setPen(QColor(0, 128, 128, 178)); // <--
            } else if (sigPower < -100 && sigPower >= -105) {
                p.setPen(QColor(0, 191, 255)); // <--
            } else if (sigPower < -105 && sigPower >= -110) {
                p.setPen(QColor(30, 144, 255, 117)); // <--
            } else if (sigPower < -115 && sigPower >= -120) {
                p.setPen(QColor(65, 105, 225, 255)); // <--
            } else if (sigPower < -120 && sigPower >= -125) {
                p.setPen(QColor(0, 0, 205, 0 )); // <--
            } else if (sigPower < -0 && sigPower >= -5) {
                p.setPen(QColor(0, 0, 0, 255)); // <--
            }
            p.drawPoint(i, j);
        }
    }
    p.end();
    scene->addPixmap(map);
    QGraphicsView* view = new QGraphicsView(scene);
    setCentralWidget(view);

}



MainWindow::~MainWindow()
{
}
