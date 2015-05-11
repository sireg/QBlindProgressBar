// demo.cpp

#include "qBlindProgressBar.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QBlindProgressBar bar;
    bar.show();

    bar.resize(500, 30);

    return app.exec();
}
