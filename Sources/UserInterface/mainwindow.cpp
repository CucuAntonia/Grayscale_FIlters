#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QImageReader>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionOpen->setIcon(QIcon("..\\..\\PracticaSpring2022\\Resources\\open.png"));
    ui->actionOpen_Help_Page->setIcon(QIcon("..\\..\\PracticaSpring2022\\Resources\\help.png"));
    ui->actionQuit->setIcon(QIcon("..\\..\\PracticaSpring2022\\Resources\\quit.png"));
    ui->actionSave->setIcon(QIcon("..\\..\\PracticaSpring2022\\Resources\\save.png"));
    ui->horizontalSlider->setVisible(false);
    ui->radioButton_green->setVisible(false);
    ui->radioButton_red->setVisible(false);
    ui->radioButton_blue->setVisible(false);
    ui->radioButton_min->setVisible(false);
    ui->radioButton_max->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->comboBox->setFixedHeight(48);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_Help_Page_triggered()
{
    QMessageBox::information(this, "Information", "This application was designed by Cucu Ioana-Antonia. Work in progress!");
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    
    if (QString::compare(filename, QString()) != 0)
    {
        bool valid = m_image.load(filename);

        if (valid)
        {
            ui->image_lbl->setPixmap(m_image);
            ui->image_lbl->setFixedSize(m_image.size());
            ui->statusbar->showMessage("Image opened", 5000);

        }

    }
    else
        ui->statusbar->showMessage("Error opening image", 5000);
}

void MainWindow::on_actionSave_triggered()
{
    QPixmap pixmap(ui->image_lbl->size());

    QFileDialog::Options options;
    QString selectedFilter;

    QString fileName = "";


    fileName = QFileDialog::getSaveFileName(this, "Export Plot", ".", "PNG Files (*.png);;All Files (*)",
        &selectedFilter,
        options);

    if (fileName.length() == 0)
        return;

    m_image.save(fileName);
}

bool MainWindow::img_display(const cv::Mat& image)
{
    ui->image_lbl->setVisible(true);

    if (!Utils::ConvertMat2QImage(image, m_dispimg))
    {
        std::cout << "ConvertMat2QImage failed!!!" << std::endl;
        return false;
    }

    ui->image_lbl->clear();
    ui->image_lbl->setPixmap(QPixmap::fromImage(m_dispimg));
    ui->image_lbl->resize(ui->image_lbl->pixmap()->size());
    return true;
}

void MainWindow::on_comboBox_currentTextChanged(const QString& arg1)
{
    ui->horizontalSlider->setVisible(false);
    ui->radioButton_green->setVisible(false);
    ui->radioButton_red->setVisible(false);
    ui->radioButton_blue->setVisible(false);
    ui->radioButton_min->setVisible(false);
    ui->radioButton_max->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    
    
    if (arg1 == "Decomposition")
    {
        ui->radioButton_min->setVisible(true);
        ui->radioButton_max->setVisible(true);
        ui->radioButton_blue->setVisible(false);
        ui->radioButton_green->setVisible(false);
        ui->radioButton_red->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->horizontalSlider->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
    }
    if (arg1 == "Single color channel")
    {
        ui->radioButton_blue->setVisible(true);
        ui->radioButton_green->setVisible(true);
        ui->radioButton_red->setVisible(true);
        ui->radioButton_min->setVisible(false);
        ui->radioButton_max->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->horizontalSlider->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
    }
    if (arg1 == "Custom gray shades")
    {
        ui->horizontalSlider->setVisible(true);
        ui->radioButton_green->setVisible(false);
        ui->radioButton_red->setVisible(false);
        ui->radioButton_blue->setVisible(false);
        ui->radioButton_min->setVisible(false);
        ui->radioButton_max->setVisible(false);
        ui->lineEdit->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);
    }
}

void MainWindow::Apply(QString arg1)
{
    ui->horizontalSlider->setVisible(false);
    ui->radioButton_green->setVisible(false);
    ui->radioButton_red->setVisible(false);
    ui->radioButton_blue->setVisible(false);
    ui->radioButton_min->setVisible(false);
    ui->radioButton_max->setVisible(false);
    ui->lineEdit->setVisible(false);

    QImage qim = m_image.toImage();
    cv::Mat inImage;
    bool rv = Utils::ConvertQImage2Mat(qim, inImage);
    if (!inImage.data)
    {
        QMessageBox::warning(this, tr("Warning"), tr("Error!"));
        return;
    }

    cv::Mat outImage;


    if (arg1 == "Averaging")
    {
        if (!Algo::Averaging(inImage, outImage))
        {
            QMessageBox::information(this, "Information", "Averaging algorithm cannot be applied!");
            return;
        }

        ui->statusbar->showMessage("Averaging algorithm applied", 5000);
    }
    else if (arg1 == "Luminance")
    {
            if (!Algo::Luminance(inImage, outImage))
            {
                QMessageBox::information(this, "Information", "Luminance algorithm cannot be applied!");
                return;
            }
            ui->statusbar->showMessage("Luminance algorithm applied", 5000);

    }
    else if (arg1 == "Desaturation")
    {
        if (!Algo::Desaturation(inImage, outImage))
        {
            QMessageBox::information(this, "Information", "Desaturation algorithm cannot be applied!");
            return;
        }
        ui->statusbar->showMessage("Desaturation algorithm applied", 5000);

    }
    else if (arg1 == "Decomposition")
    {

        ui->radioButton_min->setVisible(true);
        ui->radioButton_max->setVisible(true);
        ui->radioButton_min->isCheckable();
        ui->radioButton_max->isCheckable();
        if (ui->radioButton_min->isChecked())
        {
            if (!Algo::Minimum_decomposition(inImage, outImage))
            {
                QMessageBox::information(this, "Information", "Minimum decomposition algorithm cannot be applied!");
                return;
            }
            ui->statusbar->showMessage("Minimum decomposition algorithm applied", 5000);
            
        }
        else if (ui->radioButton_max->isChecked())
        {
            if (!Algo::Maximum_decomposition(inImage, outImage))
            {
                QMessageBox::information(this, "Information", "Maximum decomposition algorithm cannot be applied!");
                return;
            }
            ui->statusbar->showMessage("Maximum decomposition algorithm applied", 5000);
        }
    }
    else if (arg1 == "Single color channel")
    {
        ui->radioButton_green->setVisible(true);
        ui->radioButton_red->setVisible(true);
        ui->radioButton_blue->setVisible(true);
        ui->radioButton_green->isCheckable();
        ui->radioButton_red->isCheckable();
        ui->radioButton_blue->isCheckable();

        if (ui->radioButton_blue->isChecked())
        {
            std::cout << "blue" << std::endl;
            if (!Algo::Single_color_channel(inImage, outImage, Algo::ColorChannel::Blue))
            {
                QMessageBox::information(this, "Information", "Single color channel - blue algorithm cannot be applied!");
                return;
            }
            ui->statusbar->showMessage("Single color channel blue algorithm applied", 5000);
        }
        else if (ui->radioButton_green->isChecked())
        {
            std::cout << "green" << std::endl;
            if (!Algo::Single_color_channel(inImage, outImage, Algo::ColorChannel::Green))
            {
                QMessageBox::information(this, "Information", "Single color channel - green algorithm cannot be applied!");
                return;
            }
            ui->statusbar->showMessage("Single color channel green algorithm applied", 5000);
        }
        else if (ui->radioButton_red->isChecked())
        {
            std::cout << "red" << std::endl;
            if (!Algo::Single_color_channel(inImage, outImage, Algo::ColorChannel::Red))
            {
                QMessageBox::information(this, "Information", "Single color channel - red algorithm cannot be applied!");
                return;
            }
            ui->statusbar->showMessage("Single color channel red algorithm applied", 5000);
        }
    }
    else if (arg1 == "Custom gray shades")
    {

        ui->lineEdit->setVisible(true);
        ui->horizontalSlider->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);
        connect(ui->lineEdit, &QLineEdit::textChanged, [this](const QString& val)->void {ui->horizontalSlider->setValue(val.toInt()); });
        connect(ui->horizontalSlider, &QSlider::valueChanged, [this](const int& val)->void {ui->lineEdit->setText(locale().toString(val)); });

        if (!Algo::Custom_gray_shades(inImage, outImage, ui->horizontalSlider->value()))
        {
            QMessageBox::information(this, "Information", "Custom gray shades algorithm cannot be applied!");
            return;
        }
        ui->statusbar->showMessage("Custom gray shades algorithm applied", 5000);
    }

    if (!img_display(outImage))
    {
        std::cout << "Oops! Something went wrong!" << std::endl;
        return;
    }
    
}

bool MainWindow::isMinChecked()
{
    return ui->radioButton_min->isChecked();
}

bool MainWindow::isMaxChecked()
{
    return ui->radioButton_max->isChecked();
}

bool MainWindow::isBlueChecked()
{
    return ui->radioButton_blue->isChecked();
}

bool MainWindow::isGreenChecked()
{
    return ui->radioButton_green->isChecked();
}

bool MainWindow::isRedChecked()
{
    return ui->radioButton_red->isChecked();
}

void MainWindow::on_applybtn_clicked()
{
	 Apply(ui->comboBox->currentText());
}

void MainWindow::on_resetbtn_clicked()
{
	ui->image_lbl->clear();
    ui->image_lbl->setPixmap(m_image);
    ui->image_lbl->resize(ui->image_lbl->pixmap()->size());
}

void MainWindow::on_radioButton_blue_clicked()
{
	std::cout << "Blue radio button!"<<std::endl;
   if (isBlueChecked())
   {
       on_comboBox_currentTextChanged("Single color channel");
   }
}

void MainWindow::on_radioButton_green_clicked()
{
	std::cout << "Green radio button!"<<std::endl;
    if (isGreenChecked())
    {
        on_comboBox_currentTextChanged("Single color channel");
    }
}

void MainWindow::on_radioButton_red_clicked()
{
	std::cout << "Red radio button!" << std::endl;
    if (isRedChecked())
    {
        on_comboBox_currentTextChanged("Single color channel");
    }
}

void MainWindow::on_radioButton_min_clicked()
{
	std::cout << "Minimum decomposition radio button!" << std::endl;
    if (isMinChecked()) 
    {
        on_comboBox_currentTextChanged("Decomposition");
    }
}

void MainWindow::on_radioButton_max_clicked()
{
	std::cout << "Maximum decomposition radio button!" << std::endl;
    if (isMaxChecked())
    {
        on_comboBox_currentTextChanged("Decomposition");
    }
}

