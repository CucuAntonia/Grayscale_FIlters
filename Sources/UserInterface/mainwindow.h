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
    ///@brief Constructor
    ///@param QWidget* parent = nullptr
    MainWindow(QWidget* parent = nullptr);

    ///@brief Destructor
    ~MainWindow();

private slots:
    ///@brief   When the button is pressed, the application will stop running
    ///@return  void
    void on_actionQuit_triggered();

    ///@brief   When the button is pressed, it will display a pop-up containing the developer name and some other info
    ///@return  void
    void on_actionOpen_Help_Page_triggered();

    ///@brief   When the button is pressed, the users can upload a photo from their machine
    ///@return  void
    void on_actionOpen_triggered();

    ///@brief   When the button is pressed, the photo will be saved
    ///@return  void
    void on_actionSave_triggered();

    ///@brief   Creates the list with all algorithms names
    ///@details This function also sets the visibility of the interface elements, depending on the selected algorithm
    ///@param   const QString &arg1
    ///@return  void
    void on_comboBox_currentTextChanged(const QString &arg1);

    ///@brief   When the button is pressed, the algorithm will modify the original picture
    ///@return  void
    void on_applybtn_clicked();

    ///@brief   When the button is pressed, the original picture will be displayed.
    ///@return  void
    void on_resetbtn_clicked();

    ///@brief   Verify if the radiobutton for Minimum decomposition algorithm is checked or not.
    ///@return  bool
	bool isMinChecked();
  
    ///@brief   Verify if the radiobutton for Maximum decomposition algorithm is checked or not.
    ///@return  bool
    bool isMaxChecked();

    ///@brief   Verify if the blue radiobutton for Single color channel algorithm is checked or not.
    ///@return  bool
    bool isBlueChecked();

    ///@brief   Verify if the green radiobutton for Single color channel algorithm is checked or not.
    ///@return  bool
    bool isGreenChecked();

    ///@brief   Verify if the red radiobutton for Single color channel algorithm is checked or not.
    ///@return  bool
    bool isRedChecked();

    ///@brief   If the blue radiobutton is checked, the method will call on_comboBox_currentTextChanged("Single color channel")
    ///@return  void
    void on_radioButton_blue_clicked();

    ///@brief   If the green radiobutton is checked, the method will call on_comboBox_currentTextChanged("Single color channel")
    ///@return  void
    void on_radioButton_green_clicked();

    ///@brief   If the red radiobutton is checked, the method will call on_comboBox_currentTextChanged("Single color channel")
    ///@return  void
    void on_radioButton_red_clicked();

    ///@brief   If the min_decomposition radiobutton is checked, the method will call on_comboBox_currentTextChanged("Decomposition")
    ///@return  void
    void on_radioButton_min_clicked();

    ///@brief   If the max_decomposition radiobutton is checked, the method will call on_comboBox_currentTextChanged("Decomposition")
    ///@return  void
    void on_radioButton_max_clicked();
   
    ///@brief Verify if the image can be displayed.
    ///@param const cv::Mat& image
    ///@return  bool
    bool img_display(const cv::Mat& image);

    ///@brief   Apply the algorithm selected by the user.
    ///@details This function does not display the modified image. Click Apply button to modify the image.
    ///@param   QString arg1
    ///@return  void
    void Apply(QString arg1);

private:
    Ui::MainWindow* ui;
    QImage m_dispimg;
    QPixmap m_image;
};

