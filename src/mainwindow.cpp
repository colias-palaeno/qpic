#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileInfo>
#include <QFileDialog>
#include <QPixmap>
#include <QDir>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionShow_Menu_Bar_toggled(bool checked)
{
    ui->menuBar->setVisible(checked);
}

void MainWindow::render_file(QString* file_path)
{
    setWindowTitle(*file_path);
    auto file = std::make_unique<QImage>(*file_path);
    delete file_path;

    setMaximumSize(QSize(file->width(), file->height()+20));
    resize(file->width(), file->height()+20);
    ui->label->resize(file->width(), file->height()+20);
    ui->label->setPixmap(QPixmap::fromImage(*file));
}

void MainWindow::enable_navigation()
{
    // used in main.cpp
    ui->actionNext_Image->setEnabled(true);
    ui->actionPrevious_Image->setEnabled(true);
}

void MainWindow::on_actionOpen_triggered()
{
    auto* file_path = new QString(QFileDialog::getOpenFileName(
        this,
        tr("Open Image"),
        "/",
        tr("Image Files (*.png *.jpg *.bmp)")
    ));

    if (*file_path == "") {
        delete file_path;
        return;
    }

    render_file(file_path);
    enable_navigation();
}

void MainWindow::navigate_dir(bool next)
{
    // setting this in the MainWindow namespace to easily resize the window. I did this with the zoom function too
    auto* file_path = new QString(windowTitle());
    auto* file_name = new QString(QFileInfo(*file_path).fileName());
    auto file_dir = std::make_shared<QString>(file_path->remove(*file_name));

    delete file_path;

    QDir* dir = new QDir(*file_dir);
    dir->setNameFilters({"*.jpg", "*.jpeg", "*.png"});

    QStringList images = dir->entryList();
    delete dir;

    int idx = images.indexOf(*file_name) + (next ? 1 : -1);
    delete file_name;

    if (images.size() > idx && idx > (next ? 0 : -1))
        render_file(new QString(*file_dir + images[idx]));
}

void MainWindow::on_actionNext_Image_triggered()
{
    navigate_dir(true);
}

void MainWindow::on_actionPrevious_Image_triggered()
{
    navigate_dir(false);
}

void MainWindow::zoom(float sf)
{
    auto* label = ui->label;
    auto dims = QSize(label->pixmap().width() * sf, label->pixmap().height() * sf);

    label->setPixmap(label->pixmap().scaled(dims, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    label->resize(dims);

    setMaximumSize(dims);
    resize(dims);
}

void MainWindow::on_actionZoom_In_triggered()
{
    zoom(1.25);
}

void MainWindow::on_actionZoom_Out_triggered()
{
    zoom(0.8);
}
