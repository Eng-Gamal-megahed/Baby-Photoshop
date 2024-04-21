#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGray_clicked();

    void on_btnB_W_clicked();

    void on_btnInvert_clicked();

    void on_btnHFlip_clicked();

    void on_btnVFlip_clicked();

    void on_btnDarken_clicked();

    void on_btnLighten_clicked();

    void on_btnRotate90_clicked();

    void on_brnRoatate180_clicked();

    void on_btnRotate270_clicked();

    void on_btnFrame1_clicked();

    void on_btnFrame2_clicked();

    void on_btnFrame3_clicked();

    void on_btnDENormal_clicked();

    void on_btnDEFire_clicked();

    void on_btnSunlight_clicked();

    void on_btnOld_TV_clicked();

    void on_btnPurple_clicked();

    void on_btnInfrared_clicked();

    void on_btnPrison_clicked();

    void on_pushButton_clicked();

    void on_btnCrop_clicked();

    void on_btnResize_clicked();

    void on_btnBlur_clicked();

    void on_btnOIL_clicked();

    void on_btnSkew_clicked();

    void on_btnChess_clicked();

    void on_btnSave_clicked();

    void on_btnSave_2_clicked();

    void on_pushButton_4_clicked();
protected:
    void showEvent(QShowEvent *event) override;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
