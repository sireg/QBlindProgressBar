// qBlindProgressBar.h

#ifndef QBLINDPROGRESSBAR_H
#define QBLINDPROGRESSBAR_H

#include <QtWidgets/QPushButton>

class QPropertyAnimation;

class QBlindProgressBar : public QPushButton
{
    Q_OBJECT

public:
    QBlindProgressBar(QWidget *parent = 0);
    ~QBlindProgressBar();

protected:
    virtual void resizeEvent(QResizeEvent * event);

private:
    QWidget *point1_;
    QWidget *point2_;
    QWidget *point3_;
    QPropertyAnimation *animation1_;
    QPropertyAnimation *animation2_;
    QPropertyAnimation *animation3_;
};
#endif
