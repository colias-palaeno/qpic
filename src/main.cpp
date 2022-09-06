#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QCommandLineParser>
#include <QLabel>

struct Viewer : public QWidget
{
    explicit Viewer(QWidget *parent = nullptr) :
        QWidget(parent)
    {
        auto* label = new QLabel();

        label->setScaledContents(true);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCommandLineParser parser;
    parser.addPositionalArgument("file", QCoreApplication::tr("file", "The image to view."));
    parser.process(a);
    MainWindow w;
    w.show();
    {
        auto args = std::make_unique<QStringList>(parser.positionalArguments());
        if (*args != QStringList()) {
            w.render_file(new QString((*args)[0]));
            w.enable_navigation();
        }
    }
    return a.exec();
}
