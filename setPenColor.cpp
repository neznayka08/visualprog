#include <QPainter>
#include <QColor>

void setPenColorBySignalPower(QPainter* p, float Signal_Power) {
    if(Signal_Power < -44 && Signal_Power >= -54) {
        p->setPen(QColor(255, 0, 0, 255));
    } else if (Signal_Power < -54 && Signal_Power >= -64) {
        p->setPen(QColor(220, 50, 0, 255));
    } else if (Signal_Power < -64 && Signal_Power >= -74) {
        p->setPen(QColor(255, 165, 0, 255));
    } else if(Signal_Power < -74 && Signal_Power >= -84) {
        p->setPen(QColor(255, 255, 0, 255));
    } else if(Signal_Power < -84 && Signal_Power >= -94) {
        p->setPen(QColor(173, 255, 47, 255));
    } else if(Signal_Power < -94 && Signal_Power >= -104) {
        p->setPen(QColor(0, 255, 10, 255));
    } else if(Signal_Power < -104 && Signal_Power >= -114) {
        p->setPen(QColor(0, 250, 154, 255));
    } else if(Signal_Power < -114 && Signal_Power >= -124) {
        p->setPen(QColor(102, 205, 170, 255));
    } else if(Signal_Power < -124 && Signal_Power >= -134) {
        p->setPen(QColor(65, 105, 225, 255));
    } else if(Signal_Power < -134 && Signal_Power >= -144) {
        p->setPen(QColor(0, 0, 255, 255));
    }
}

