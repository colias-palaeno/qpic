#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

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


int zoom_count = 0;

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
    ui->actionZoom_In->setEnabled(true);
    ui->actionZoom_Out->setEnabled(true);
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

    if (idx == images.size())
        idx = 0;
    else if (idx == -1)
        idx = images.size() - 1;

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

void MainWindow::zoom(bool zooming_in)
{
    if (abs(zoom_count) > 5 && zooming_in == (zoom_count > 0))
        return;
    auto* label = ui->label;
    zoom_count += zooming_in ? 1 : -1;
    auto* sf = new double(pow(1.25, zoom_count));

    auto* current_file = new QPixmap(QPixmap::fromImage(QImage(windowTitle())));
    auto dims = QSize(current_file->width() * *sf, current_file->height() * *sf);

    delete sf;

    label->setPixmap(current_file->scaled(dims));
    delete current_file;

    label->resize(dims);

    setMaximumSize(dims);
    resize(dims);
}

void MainWindow::on_actionZoom_In_triggered()
{
    zoom(true);
}

void MainWindow::on_actionZoom_Out_triggered()
{
    zoom(false);
}
