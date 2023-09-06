#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eleve.h"
#include "enseignant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_EN_clicked();

    void on_Modifier_En_clicked();

    void on_Suppoimer_En_clicked();

    void on_Ajouter_Eleve_clicked();

    void on_Modifier_eleve_clicked();

    void on_Supp_Eleve_clicked();

    void on_Afficher_clicked();

    void on_CINR_3_clicked();

    void on_NomR_3_clicked();

    void on_PrenomR_3_clicked();

    void on_CINR_4_clicked();

    void on_NomR_4_clicked();

    void on_PrenomR_4_clicked();

    void on_Trier_clicked();

    void on_pushButton_clicked();

    void on_Afficher_stat_clicked();

private:
    Ui::MainWindow *ui;
    Eleve ele;
    Enseignant ense;
};
#endif // MAINWINDOW_H
