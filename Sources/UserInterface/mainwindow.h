#include <QMainWindow>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include "Algorithms.h"
#include "Utils.h"


#ifdef UI_EXPORT
#define UI_API __declspec(dllexport)
#else
#define UI_API __declspec(dllimport)
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class UI_API MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionOpen_Help_Page_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_applybtn_clicked();

    void on_resetbtn_clicked();

	bool isMinChecked();
  
    bool isMaxChecked();

    bool isBlueChecked();

    bool isGreenChecked();

    bool isRedChecked();

    void on_radioButton_blue_clicked();

    void on_radioButton_green_clicked();

    void on_radioButton_red_clicked();

    void on_radioButton_min_clicked();

    void on_radioButton_max_clicked();
   
    bool img_display(const cv::Mat& image);

    void Apply(QString arg1);

private:
    Ui::MainWindow* ui;
    QImage m_dispimg;
    QPixmap m_image;
};

