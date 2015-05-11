// qBlindProgressBar.cpp

#include "qBlindProgressBar.h"
#include <QResizeEvent>
#include <QPropertyAnimation>
#include <QTimer>

QBlindProgressBar::QBlindProgressBar(QWidget *parent)
    :QPushButton(parent)
{
    point1_ = new QWidget(this);
    point2_ = new QWidget(this);
    point3_ = new QWidget(this);

    point1_->move(0 - point1_->width(), 0);
    point2_->move(0 - point2_->width(), 0);
    point3_->move(0 - point3_->width(), 0);

    animation1_ = new QPropertyAnimation(point1_, "pos", point1_);
    animation1_->setDuration(5000);
    animation1_->setEasingCurve(QEasingCurve::InOutCirc);
    animation1_->setStartValue(QPoint(width() - 30, 0));
    animation1_->setEndValue(QPoint(width() + 30, 0));
    animation1_->setLoopCount(-1);

    animation2_ = new QPropertyAnimation(point2_, "pos", point2_);
    animation2_->setDuration(5000);
    animation2_->setEasingCurve(QEasingCurve::InOutCirc);
    animation2_->setStartValue(QPoint(width() - 30, 0));
    animation2_->setEndValue(QPoint(width() + 30, 0));
    animation2_->setLoopCount(-1);

    animation3_ = new QPropertyAnimation(point3_, "pos", point3_);
    animation3_->setDuration(5000);
    animation3_->setEasingCurve(QEasingCurve::InOutCirc);
    animation3_->setStartValue(QPoint(width() - 30, 0));
    animation3_->setEndValue(QPoint(width() + 30, 0));
    animation3_->setLoopCount(-1);

    QTimer::singleShot(2000, Qt::CoarseTimer, animation1_, SLOT(start()));
    QTimer::singleShot(2500, Qt::CoarseTimer, animation2_, SLOT(start()));
    QTimer::singleShot(3000, Qt::CoarseTimer, animation3_, SLOT(start()));
}

void QBlindProgressBar::resizeEvent(QResizeEvent *event)
{
    int height = event->size().height();
    int point_height = height * 0.75f;

    int radius = point_height * 0.5f;
    int y = (height - point_height) * 0.5f;

    point1_->resize(point_height, point_height);
    point2_->resize(point_height, point_height);
    point3_->resize(point_height, point_height);

    QString stylesheet = QString("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5," \
                                 " radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(85, 170, 255, 255)," \
                                 " stop:1 rgba(85, 170, 255, 0));border-radius:%1px").arg(radius);
    point1_->setStyleSheet(stylesheet);
    point2_->setStyleSheet(stylesheet);
    point3_->setStyleSheet(stylesheet);

    QPoint start(0 - point_height, y);
    QPoint end(width(), y);
    animation1_->setStartValue(start);
    animation1_->setEndValue(end);

    animation2_->setStartValue(start);
    animation2_->setEndValue(end);

    animation3_->setStartValue(start);
    animation3_->setEndValue(end);

    QPushButton::resizeEvent(event);
}

QBlindProgressBar::~QBlindProgressBar()
{}
