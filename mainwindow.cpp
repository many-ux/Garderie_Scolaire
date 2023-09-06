#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eleve.h"
#include "enseignant.h"
#include <QtDebug>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QtGui>
#include <QVariant>
#include <QAbstractEventDispatcher>
#include <QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajouter_EN_clicked()
{
    int cin= ui->CIN->text().toInt();
    QString nom= ui->Nom->text();
    QString prenom= ui->Prenom->text();
    QString sexe= ui->sexe->currentText();
    QString mail= ui->Mail->text();
    QDate datenais= ui->datenais->date();
    int numtel= ui->num_tel->text().toInt();
    QDate datemp= ui->dateemp->date();
    QString adresse= ui->Adresse->text();
    int salaire= ui->salaire->text().toInt();
    Enseignant en(cin, nom,prenom,sexe,mail,datenais,salaire,numtel,adresse,datemp);


    en.ajouter();

}


void MainWindow::on_Modifier_En_clicked()
{
    int cin= ui->CIN_2->text().toInt();
    QString nom= ui->Nom_2->text();
    QString prenom= ui->Prenom_2->text();
    QString sexe= ui->sexe_2->currentText();
    QString mail= ui->Mail_2->text();
    QDate datenais= ui->datenais_2->date();
    int numtel= ui->num_tel_2->text().toInt();
    QDate datemp= ui->dateemp_2->date();
    QString adresse= ui->Adresse_2->text();
    int salaire= ui->salaire_2->text().toInt();

    Enseignant en(cin, nom,prenom,sexe,mail,datenais,salaire,numtel,adresse,datemp);

    en.modifier();
}


void MainWindow::on_Suppoimer_En_clicked()
{
    int cin= ui->CIN_3->text().toInt();
    Enseignant e;
    e.supprimer(cin);
}


void MainWindow::on_Ajouter_Eleve_clicked()
{
    int cin= ui->CIN_eleve->text().toInt();
    QString nom= ui->Nom_eleve->text();
    QString prenom= ui->prenom_eleve->text();
    QString sexe= ui->sexe_eleve->currentText();
    QString mail= ui->Mail_Eleve->text();
    QDate datenais= ui->dateNais_eleve->date();
    int numpar= ui->NumParent->text().toInt();
    QDate dateIns= ui->dateIns->date();
    QString adresse= ui->Adresse_Eleve->text();

    Eleve el(cin,nom,prenom,sexe,mail,datenais,numpar,adresse,dateIns);

    el.ajouter();
}


void MainWindow::on_Modifier_eleve_clicked()
{
    int cin= ui->modCIN->text().toInt();
    QString nom= ui->modNom->text();
    QString prenom= ui->modPrenom->text();
    QString sexe= ui->modSexe->currentText();
    QString mail= ui->modMail->text();
    QDate datenais= ui->modDatenais->date();
    int numpar= ui->modNumPar->text().toInt();
    QDate dateIns= ui->modDateIns->date();
    QString adresse= ui->modAdr->text();

    Eleve el(cin,nom,prenom,sexe,mail,datenais,numpar,adresse,dateIns);

    el.modifier();
}


void MainWindow::on_Supp_Eleve_clicked()
{
    int cin= ui->del_Eleve->text().toInt();
    Eleve el;
    el.supprimer(cin);
}


void MainWindow::on_Afficher_clicked()
{
    ui->tableViewEleve->setModel(ele.afficher());
    ui->tableViewEnseignant->setModel(ense.afficher());

}


void MainWindow::on_CINR_3_clicked()
{
    int cin= ui->CINR->text().toInt();
    ui->tableViewRechercherEns->setModel(ense.recherche(cin));
}


void MainWindow::on_NomR_3_clicked()
{
    QString nom= ui->NomR->text();
    ui->tableViewRechercherEns->setModel(ense.RechercheNom(nom));

}


void MainWindow::on_PrenomR_3_clicked()
{
    QString prenom= ui->Prenom->text();
    ui->tableViewRechercherEns->setModel(ense.RecherchePrenom(prenom));

}


void MainWindow::on_CINR_4_clicked()
{
    int cin= ui->CINR_2->text().toInt();
    ui->tableViewRechercherEle->setModel(ele.Recherche(cin));

}


void MainWindow::on_NomR_4_clicked()
{
    QString nom= ui->NomR_2->text();
    ui->tableViewRechercherEle->setModel(ele.RechercheNom(nom));

}


void MainWindow::on_PrenomR_4_clicked()
{
    QString prenom= ui->PrenomR_2->text();
    ui->tableViewRechercherEle->setModel(ele.RecherchePrenom(prenom));

}


void MainWindow::on_Trier_clicked()
{
    ui->tableViewTrierCIN->setModel(ense.triercin());
    ui->tableViewTrierNom->setModel(ense.triernom());
    ui->tableViewTrierPrenom->setModel(ense.trierprenom());

}


void MainWindow::on_pushButton_clicked()
{
    QString strStream;
    strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(strStream).suffix().isEmpty())
    { strStream.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(strStream);

    QTextStream out(&strStream);

    const int rowCount = ui->tableViewEnseignant->model()->rowCount();
    const int columnCount = ui->tableViewEnseignant->model()->columnCount();
    QString TT = QDateTime::currentDateTime().toString();
    out <<"<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - COMmANDE LIST<title>\n "
        << "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"
           "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
               +"<img src=C:\\Users\\asus\\Desktop\\pdf\\logo_projet />" //path
                 "<h1 style=\"text-align: center;\"><strong> ****LISTE DES ENSEIGNANTS **** </strong></h1>"

                 "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                 "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableViewEnseignant->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableViewEnseignant->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableViewEnseignant->isColumnHidden(column)) {
                QString data =ui->tableViewEnseignant->model()->data(ui->tableViewEnseignant->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;")); //pas compriis
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
           "</body>\n"
           "</html>\n";
    QTextDocument document;
    document.setHtml(strStream);
    document.print(&printer);
    QMessageBox::information(this,"ok","fichier crée");
}


void MainWindow::on_Afficher_stat_clicked()
{
    ui->verticalLayout->addWidget(ense.stat());
}

